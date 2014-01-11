/*! File:   VerletPoly.cpp
 * Author: Ira Greenberg
 *
 * Created on June 14, 2013, 7:17 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */


#include "VerletPoly.h"

using namespace proto;

/*!
 * Default Constructor */
VerletPoly::VerletPoly() {
}

VerletPoly::VerletPoly(int sides, float radius) :
sides(sides), radius(radius) {
    // ensure even
    if (sides % 2 != 0) {
        sides++;
    }
    balls.reserve(sides);
    //sticks.reserve(sides * 2);
    float theta = 0.0;
    for (int i = 0; i < sides; ++i) {
        balls.push_back(new VerletBall(Vector3(cos(theta)*.5, sin(theta)*.5, 0)));
        theta += Math::TWO_PI / sides;
    }

    for (int i = 0; i < sides; ++i) {
        if (i < sides - 1) {
            sticks.push_back(VerletStick(balls[i], balls[i + 1], .9));
        } else {
            sticks.push_back(VerletStick(balls[i], balls[0], .9));
        }
    }

    //    for (int i = 0; i < sides; ++i) {
    //        if (i < sides - 2) {
    //            sticks.push_back(VerletStick(balls[i], balls[i + 2], .005));
    //        } else if (i == sides - 2) {
    //            sticks.push_back(VerletStick(balls[i], balls[0], .005));
    //        } else {
    //            sticks.push_back(VerletStick(balls[i], balls[1], .005));
    //        }
    //    }

    for (int i = 0; i < sides / 2; ++i) {
        sticks.push_back(VerletStick(balls[i], balls[sides / 2 + i], .9));
    }

    // nudge initial ball
    balls.at(0)->pos.x -= .0002;
    //    std::cout << "balls length = " << balls.size() << std::endl;
    //    std::cout << "sticks length = " << sticks.size() << std::endl;


}

void VerletPoly::display() {


    for (int i = 0; i < sides; ++i) {
        sticks[i].printFields();
    }

    glPushMatrix();
    glScalef(radius, radius, radius);
    //glScale3f(radius, radius, radius);
//    glBegin(GL_POLYGON);
//    for (int i = 0; i < sticks.size(); ++i) {
//        glVertex3f(sticks.at(i).getBall1()->pos.x,
//                sticks.at(i).getBall1()->pos.y,
//                sticks.at(i).getBall1()->pos.z);
//
//        glVertex3f(sticks.at(i).getBall2()->pos.x,
//                sticks.at(i).getBall2()->pos.y,
//                sticks.at(i).getBall2()->pos.z);
//
//    }
//
//    glEnd();


    glColor3f(1.0, .5, 0);
    for (int i = 0; i < sticks.size(); ++i) {
        sticks.at(i).display();
    }
    glPopMatrix();

}

void VerletPoly::run() {
    for (int i = 0; i < balls.size(); ++i) {
        balls.at(i)->pos.x += Math::random(-.005, .005);
        balls[i]->verlet();
    }

    for (int i = 0; i < sticks.size(); ++i) {
        sticks[i].constrainLen();
    }

}
