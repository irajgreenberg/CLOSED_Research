//
//  FrenetFrame.cpp
//  Protobyte_iig001
//
//  Created by Ira on 10/15/12.
//
//

#include "FrenetFrame.h"
#include <iostream>



namespace proto {

    std::ostream& operator<<(std::ostream& out, const FrenetFrame& frame) {
        //std::cout << "T = " << frame.getT()<<", B = " << frame.getB()<<", N = " << frame.getN();
        return out;
    }
}

using namespace proto;

FrenetFrame::FrenetFrame() {

}

FrenetFrame::FrenetFrame(const Vector3& p, const Vector3& T, const Vector3& B, const Vector3& N) :
p(p), T(T), B(B), N(N) {
}

FrenetFrame::FrenetFrame(const Vector3 TBN[3]) {
    T = TBN[0];
    B = TBN[1];
    N = TBN[2];
}

Vector3 FrenetFrame::getT() const {
    return T;
}

Vector3 FrenetFrame::getN() const {
    return N;
}

Vector3 FrenetFrame::getB() const {
    return B;
}

void FrenetFrame::display(float len) {
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