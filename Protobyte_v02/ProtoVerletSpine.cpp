/*! File:   VerletSpine.cpp
 * Author: Ira Greenberg
 *
 * Created on May 31, 2013, 11:10 AM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#include "VerletSpine.h"


using namespace proto;

/*!
 * Default Constructor */
VerletSpine::VerletSpine() {
}

VerletSpine::VerletSpine(const std::vector<Vector3>& vecs, float tension, Anchor anchorPos) :
vecs(vecs), tension(tension), anchorPos(anchorPos) {
    for (int i = 0; i < vecs.size() - 1; ++i) {
        tensions.push_back(tension);
    }
    isRunning = false;
    init();

}

// dstr

VerletSpine::~VerletSpine() {
    for (int i = 0; i < balls.size(); ++i) {
        delete balls.at(i);
    }
}

// copy cstr

VerletSpine::VerletSpine(const VerletSpine& vs) {
    vecs = vs.vecs;
    tension = vs.tension;
    tensions = vs.tensions;
    isRunning = vs.isRunning;
    anchorPos = vs.anchorPos;
    init();
}

// overloaded assignment op

VerletSpine& VerletSpine::operator=(const VerletSpine& vs) {
    // check for self assignment
    if (this != &vs) {

        // clean up memory on heap
        for (int i = 0; i < balls.size(); ++i) {
            delete balls.at(i);
        }
        // just to be explicit
        balls.clear();
        sticks.clear();
        tensions.clear();

        vecs = vs.vecs;
        tension = vs.tension;
        tensions = vs.tensions;
        isRunning = vs.isRunning;
        anchorPos = vs.anchorPos;
        init();
    }

    return *this;

}

void VerletSpine::init() {
    for (int i = 0; i < vecs.size(); ++i) {
        balls.push_back(new VerletBall(vecs.at(i)));

        if (i > 0) {
            switch (anchorPos) {
                case NONE:
                    sticks.push_back(VerletStick(balls.at(i - 1), balls.at(i), tensions.at(i - 1)));
                    break;
                case LEFT:
                    if (i == 1) {
                        sticks.push_back(VerletStick(balls.at(i - 1), balls.at(i), tensions.at(i - 1), Tuple2f(0, 1.0)));
                    } else {
                        sticks.push_back(VerletStick(balls.at(i - 1), balls.at(i), tensions.at(i - 1)));
                    }
                    break;
                case RIGHT:
                    if (i == vecs.size() - 1) {
                        sticks.push_back(VerletStick(balls.at(i - 1), balls.at(i), tensions.at(i - 1), Tuple2f(1.0, 0)));
                    } else {
                        sticks.push_back(VerletStick(balls.at(i - 1), balls.at(i), tensions.at(i - 1)));
                    }
                    break;
                case BOTH:
                    if (i == 1) {
                        sticks.push_back(VerletStick(balls.at(i - 1), balls.at(i), tensions.at(i - 1), Tuple2f(0, 1.0)));
                    } else if (i == vecs.size() - 1) {
                        sticks.push_back(VerletStick(balls.at(i - 1), balls.at(i), tensions.at(i - 1), Tuple2f(1.0, 0)));
                    } else {
                        sticks.push_back(VerletStick(balls.at(i - 1), balls.at(i), tensions.at(i - 1)));
                    }
                    break;
            }
        }
    }

}

void VerletSpine::nudge(const Vector3& v, int index) {
    Vector3 p = balls.at(index)->getPos();
    p += v;
    //std::cout << "p += v = " << p << std::endl;
    balls.at(index)->setPos(p);
    //std::cout << "nudge: balls.at(index).getPos()= " << balls.at(index).getPos() << std::endl;
}

void VerletSpine::start() {
    isRunning = true;
}

void VerletSpine::stop() {
    isRunning = false;
}

void VerletSpine::run() {
    if (isRunning) {
        for (int i = 0; i < balls.size(); ++i) {
            balls.at(i)->verlet();
            //std::cout << "balls.at(i).getPos() = " << balls.at(i).getPos() << std::endl;

        }

        //std::cout << "sticks.size() = " <<sticks.size()<< std::endl;
        for (int i = 0; i < sticks.size(); ++i) {
            sticks.at(i).constrainLen();
            // std::cout << "sticks.at(i).getBall2()->getPos() = " << sticks.at(i).getBall2()->getPos() << std::endl;

        }
    }

}




