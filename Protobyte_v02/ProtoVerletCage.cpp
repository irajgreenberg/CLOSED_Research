/*! File:   VerletCage.cpp
 * Author: Ira Greenberg
 *
 * Created on June 17, 2013, 3:01 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */
#include "VerletCage.h"

using namespace proto;

/*!
 * Default Constructor */
VerletCage::VerletCage() {
}

/*!
 * Overloaded Constructor */
VerletCage::VerletCage(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, int segments, int crossSectionDetail, float tension) :
GraphicsCore(pos, rot, size, col4), segments(segments), crossSectionDetail(crossSectionDetail), tension(tension) {
    // ensure even
    if (this->crossSectionDetail % 2 != 0) {
        crossSectionDetail++;
    }
    init();
}

// copy cstr

VerletCage::VerletCage(const VerletCage &orig) {
    // populate vector w balls via "heap" allocation
    for (int i = 0; i < orig.balls.size(); ++i) {
        balls.push_back(new VerletBall(*orig.balls.at(i)));
        initBallPositions.push_back(Vector3(orig.balls.at(i)->pos));
    }

    for (int i = 0; i < orig.exoBalls.size(); ++i) {
        exoBalls.push_back(new VerletBall(*orig.exoBalls.at(i)));
    }

    pos = orig.pos;
    rot = orig.rot;
    size = orig.size;
    col4 = orig.col4;
    segments = orig.segments;
    crossSectionDetail = orig.crossSectionDetail;
    tension = orig.tension;

    // calculate sticks
    calcSticks();

}

// dstr

VerletCage::~VerletCage() {
    // clean up free store
    for (int i = 0; i < balls.size(); ++i) {
        delete balls.at(i);
    }

    for (int i = 0; i < exoBalls.size(); ++i) {
        delete exoBalls.at(i);
    }
    
    std::cout << "in VerletCage Destructor" << std::endl;
}

// assignment op

VerletCage& VerletCage::operator=(const VerletCage& orig) {
    // avoid self assignment
    if (this != &orig) {
        // clean up free store
        for (int i = 0; i < balls.size(); ++i) {
            delete balls.at(i);
        }

        for (int i = 0; i < exoBalls.size(); ++i) {
            delete exoBalls.at(i);
        }
        // reset balls and initial position vector
        balls.clear();
        initBallPositions.clear();
        exoBalls.clear();

        // populate vector w balls via "heap" allocation
        for (int i = 0; i < orig.balls.size(); ++i) {
            balls.push_back(new VerletBall(*orig.balls.at(i)));
            initBallPositions.push_back(Vector3(orig.balls.at(i)->pos));
        }

        for (int i = 0; i < orig.exoBalls.size(); ++i) {
            exoBalls.push_back(new VerletBall(*orig.exoBalls.at(i)));
        }

        pos = orig.pos;
        rot = orig.rot;
        size = orig.size;
        col4 = orig.col4;
        segments = orig.segments;
        crossSectionDetail = orig.crossSectionDetail;
        tension = orig.tension;

        // clean up verlet sticks
        sticks.clear();
        // recalculate sticks
        calcSticks();

    }
    return *this;
}

void VerletCage::init() {
    theta = 0.0;

    // calculate vballs
    calcBalls();

    // calculate vsticks
    calcSticks();

    // nudge cross-section
    //    for (int i = 0; i < segments; ++i) {
    //        if (i == segments / 2 - 1) {
    //            for (int j = 0; j < crossSectionDetail; ++j) {
    //                balls.at(i * crossSectionDetail + j)->pos += Vector3(0, .54, 0);
    //            }
    //        }
    //    }

}

void VerletCage::calcBalls() {
    // calculate vballs for internal structure
    float shift = 1.0 / (segments - 1);
    for (int i = 0; i < segments; ++i) {
        float theta = 0;
        theta += Math::TWO_PI / 8.0;
        for (int j = 0; j < crossSectionDetail; ++j) {
             balls.push_back(new VerletBall(Vector3(-.5 + shift*i, cos(theta)*(i+1)*.03, sin(theta)*(i+1)*.03)));

            if (i == 0) {
                exoBalls.push_back(new VerletBall(Vector3(balls.at(j)->pos.x-.001, balls.at(j)->pos.y, balls.at(j)->pos.z)));
            } else if (i == segments - 1) {
               exoBalls.push_back(new VerletBall(Vector3(balls.at(i * crossSectionDetail + j)->pos.x+.001, balls.at(i * crossSectionDetail + j)->pos.y, balls.at(i * crossSectionDetail + j)->pos.z)));
            }
            
//            if (i == 0) {
//                exoBalls.push_back(new VerletBall(Vector3(-.5001 + shift*i, cos(theta), sin(theta))));
//            } else if (i == segments - 1) {
//                exoBalls.push_back(new VerletBall(Vector3(-.4999 + shift*i, cos(theta), sin(theta))));
//            }
           
            initBallPositions.push_back(balls.at(i * crossSectionDetail + j)->pos); // capture starting positions
            //std::cout << "-.5 + shift*i = " << (-.5 + shift*i) << std::endl;
            theta += Math::TWO_PI / crossSectionDetail;
        }
    }

}

void VerletCage::calcSticks() {
    // calculate internal cage
    for (int i = 0; i < segments; ++i) {
        for (int j = 0; j < crossSectionDetail; ++j) {
            //std::cout << "in here " << i * crossSectionDetail + j + 1 << " times" << std::endl;
            // calc sticks around cross-sections 
            if (j < crossSectionDetail - 1) {
                sticks.push_back(VerletStick(balls.at(i * crossSectionDetail + j), balls.at(i * crossSectionDetail + j + 1), tension, Tuple2f(.5, .5)));
                if (j == crossSectionDetail - 2) {
                    sticks.push_back(VerletStick(balls.at(i * crossSectionDetail + j + 1), balls.at(i * crossSectionDetail), tension, Tuple2f(.5, .5)));
                }
            }

            // calc orthogonal connecting sticks between cross-sections
            if (i < segments - 1) {
                sticks.push_back(VerletStick(balls.at(i * crossSectionDetail + j), balls.at((i + 1) * crossSectionDetail + j), tension, Tuple2f(.5, .5)));
            }

            // calc 2D diagonal supports around exterior
            if (i < segments - 1) {
                if (j < crossSectionDetail - 1) {
                    sticks.push_back(VerletStick(balls.at(i * crossSectionDetail + j), balls.at((i + 1) * crossSectionDetail + j + 1), tension, Tuple2f(.01, .01)));
                } else {
                    sticks.push_back(VerletStick(balls.at(i * crossSectionDetail + j), balls.at((i + 1) * crossSectionDetail), tension, Tuple2f(.01, .01)));
                }
            }

            // calc 2D diagonal supports across cross-section faces in 3d
            if (j < crossSectionDetail / 2) {
                // std::cout << "in here " << i * crossSectionDetail + j + 1 << " times" << std::endl;
                 sticks.push_back(VerletStick(balls.at(i * crossSectionDetail + j), balls.at(i * crossSectionDetail + crossSectionDetail / 2 + j), tension, Tuple2f(.5, .5)));
            }

            // calc 3D diagonal supports across interior
            if (i < segments - 1) {
                if (j < crossSectionDetail / 2) {
                    //sticks.push_back(VerletStick(balls.at(i * crossSectionDetail + j), balls.at((i + 1) * crossSectionDetail + (crossSectionDetail / 2) + j), tension, Tuple2f(.5, .5)));
                } else {
                    //sticks.push_back(VerletStick(balls.at(i * crossSectionDetail + j), balls.at((i + 1) * crossSectionDetail + j - crossSectionDetail / 2), tension, Tuple2f(.5, .5)));

                }
            }

            // end to end orthogonal supports
            if (i == 0) {
                 //sticks.push_back(VerletStick(balls.at(j), balls.at((segments - 1) * crossSectionDetail + j), tension, Tuple2f(.5, .5)));
            }

        }

    }

    // NOTE: used additional loops so anchor tethers get added to end of sticks vector
    for (int i = 0; i < segments; ++i) {
        for (int j = 0; j < crossSectionDetail; ++j) {
            // end anchors to exoBalls
            if (i == 0) {
                sticks.push_back(VerletStick(balls.at(i * crossSectionDetail + j), exoBalls.at(j), tension, Tuple2f(1.0, 0.0)));
            } else if (i == segments - 1) {
                sticks.push_back(VerletStick(balls.at(i * crossSectionDetail + j), exoBalls.at(crossSectionDetail + j), tension, Tuple2f(1.0, 0.0)));
            }
        }

    }

}

void VerletCage::display() {
    // skeleton
    glPushMatrix();

    glColor4f(col4.getR(), col4.getG(), col4.getB(), col4.getA());
    glScalef(size.w, size.h, size.d);
    // don't render anchor tethers
    for (int i = 0; i < sticks.size()-crossSectionDetail*2; ++i) {
        sticks.at(i).display();
        //std::cout << "sticks.at(i)getBall1().pos: " << sticks.at(i).getBall1()->pos << std::endl;
    }

//         glColor4f(col4.getR(), col4.getG(), col4.getB(), 1.0);
//         glBegin(GL_POLYGON);
//        for (int i = 0; i < segments - 1; ++i) {
//            for (int j = 0; j < crossSectionDetail; ++j) {
//                if (j < crossSectionDetail - 1) {
//                    glVertex3f(balls.at(i * crossSectionDetail + j)->pos.x, balls.at(i * crossSectionDetail + j)->pos.y, balls.at(i * crossSectionDetail + j)->pos.z);
//                    glVertex3f(balls.at(i * crossSectionDetail + j + 1)->pos.x, balls.at(i * crossSectionDetail + j + 1)->pos.y, balls.at(i * crossSectionDetail + j + 1)->pos.z);
//                    glVertex3f(balls.at((i + 1) * crossSectionDetail + j + 1)->pos.x, balls.at((i + 1) * crossSectionDetail + j + 1)->pos.y, balls.at((i + 1) * crossSectionDetail + j + 1)->pos.z);
//                    glVertex3f(balls.at((i + 1) * crossSectionDetail + j)->pos.x, balls.at((i + 1) * crossSectionDetail + j)->pos.y, balls.at((i + 1) * crossSectionDetail + j)->pos.z);
//                } else {
//                    glVertex3f(balls.at(i * crossSectionDetail + j)->pos.x, balls.at(i * crossSectionDetail + j)->pos.y, balls.at(i * crossSectionDetail + j)->pos.z);
//                    glVertex3f(balls.at(i * crossSectionDetail)->pos.x, balls.at(i * crossSectionDetail)->pos.y, balls.at(i * crossSectionDetail)->pos.z);
//                    glVertex3f(balls.at((i + 1) * crossSectionDetail)->pos.x, balls.at((i + 1) * crossSectionDetail)->pos.y, balls.at((i + 1) * crossSectionDetail)->pos.z);
//                    glVertex3f(balls.at((i + 1) * crossSectionDetail + j)->pos.x, balls.at((i + 1) * crossSectionDetail + j)->pos.y, balls.at((i + 1) * crossSectionDetail + j)->pos.z);
//    
//                }
//            }
//        }
//        glEnd();

    glPopMatrix();
}

void VerletCage::run() {
    static int frameCount = 0;
    static float theta3 = 0.0;


    //for (int i = 0; i < crossSectionDetail; ++i) {
    //balls.at(balls.size()/2)->pos = initBallPositions.at(balls.size()/2) + sin(theta)*.1;
    //balls.at(1)->pos = initBallPositions.at(1) - sin(theta*2)*.1;

    // }
    //theta += Math::PI / 45.0;


    for (int i = 0; i < segments; ++i) {
        for (int j = 0; j < crossSectionDetail; ++j) {
            balls.at(i * crossSectionDetail + j)->verlet();
        }

    }

    for (int i = 0; i < sticks.size(); ++i) {
        sticks[i].constrainLen();
    }

    // only nudge after system is running or you'll get permanent distortion
    if (frameCount++ == 0) {
        // nudge cross-section
        for (int i = 0; i < segments; ++i) {
            if (i == segments / 2 - 1) {
                for (int j = 0; j < crossSectionDetail; ++j) {
                    balls.at(i * crossSectionDetail + j)->pos.y += sin(theta3)*.01; //Vector3(0, 2.54, 0);
                }
            }
        }

    }


    //    for (int i = 0; i < balls.size(); ++i) {
    //        balls.at(i)->pos.y += sin(theta3)* (1.0 - balls.at(i)->pos.mag())*.001;
    //    }

    //    for (int i = 0; i < segments; ++i) {
    //        for (int j = 0; j < crossSectionDetail; ++j) {
    //            if (i == 2) {
    //                balls.at(i * crossSectionDetail + j)->pos.y += sin(theta3)*.005;
    //            } else if (i == 4) {
    //                balls.at(i * crossSectionDetail + j)->pos.y -= cos(theta3)*.005;
    //            }
    //        }
    //    }
    //    theta3 += Math::PI / 125.0;

    for (int i = 0; i < segments; ++i) {
        for (int j = 0; j < crossSectionDetail; ++j) {
            //exoBalls.at(j)->pos.y -= cos(theta3)*.09;

            if (i == 0) {
                exoBalls.at(j)->pos.y -= sin(theta3)*.03;
            } else if (i == segments - 1) {
                exoBalls.at(crossSectionDetail + j)->pos.y -= cos(theta3)*.14;
            }
            
             balls.at(i * crossSectionDetail + j)->pos += Vector3(Math::random(-.0002, .0002), Math::random(-.0002, .0002), Math::random(-.0002, .0002) );
        }
    }
    theta3 += Math::PI / Math::random(5, 90);

}

