/*!  \brief  ProtoFrenetFrame.cpp: Frenet frame class for parallel transport correction
 ProtoFrenetFrame.cpp
 Protobyte Library v02
 
 Created by Ira on 7/23/13.
 Copyright (c) 2013 Ira Greenberg. All rights reserved.
 
 Library Usage:
 This work is licensed under the Creative Commons
 Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 To view a copy of this license, visit
 http://creativecommons.org/licenses/by-nc-sa/3.0/
 or send a letter to Creative Commons,
 444 Castro Street, Suite 900,
 Mountain View, California, 94041, USA.
 
 This notice must be retained any source distribution.
 
 \ingroup common
 This class is templated to allow for varied single collection types
 This class is part of the group common (update)
 \sa NO LINK
 */


#include "ProtoFrenetFrame.h"
#include <iostream>



namespace ijg {

    std::ostream& operator<<(std::ostream& out, const ProtoFrenetFrame& frame) {
        std::cout << "T = " << frame.getT() <<", B = " << frame.getB()<<", N = " << frame.getN();
        return out;
    }
}

using namespace ijg;

ProtoFrenetFrame::ProtoFrenetFrame() {

}

ProtoFrenetFrame::ProtoFrenetFrame(const Vec3f& p, const Vec3f& T, const Vec3f& B, const Vec3f& N) :
p(p), T(T), B(B), N(N) {
}

ProtoFrenetFrame::ProtoFrenetFrame(const Vec3f TBN[3]) {
    T = TBN[0];
    B = TBN[1];
    N = TBN[2];
}

Vec3f ProtoFrenetFrame::getT() const {
    return T;
}

Vec3f ProtoFrenetFrame::getN() const {
    return N;
}

Vec3f ProtoFrenetFrame::getB() const {
    return B;
}

void ProtoFrenetFrame::display(float len) {
    //     std::cout << "T = " << T.length() << std::endl;
    //     std::cout << "B = " << B.length() << std::endl;
    //     std::cout << "N = " << N.length()<< std::endl;

    glBegin(GL_LINES);

    // T = RED
    glColor3f(1, 0, 0);
    glVertex3f(p.x, p.y, p.z);
    glVertex3f(p.x + T.x*len, p.y + T.y*len, p.z + T.z * len);

    // B = BLUE
    glColor3f(0, 0, 1);
    glVertex3f(p.x, p.y, p.z);
    glVertex3f(p.x + B.x*len, p.y + B.y*len, p.z + B.z * len);


    // N = GREEN
    glColor3f(0, 1, 0);
    glVertex3f(p.x, p.y, p.z);
    glVertex3f(p.x + N.x*len, p.y + N.y*len, p.z + N.z * len);




    glEnd();
}