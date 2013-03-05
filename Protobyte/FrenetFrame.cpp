//
//  FrenetFrame.cpp
//  Protobyte_iig001
//
//  Created by Ira on 10/15/12.
//
//

#include "FrenetFrame.h"
#include <iostream>



namespace ijg {
    
    std::ostream& operator<<(std::ostream& out, const FrenetFrame& frame)
    {
        //std::cout << "T = " << frame.getT()<<", B = " << frame.getB()<<", N = " << frame.getN();
        return out;
    }
}

using namespace ijg;

FrenetFrame::FrenetFrame()
{
    
}

FrenetFrame::FrenetFrame(const ofVec3f& p, const ofVec3f& T, const ofVec3f& B, const ofVec3f& N):
p(p), T(T), B(B), N(N) {
}

FrenetFrame::FrenetFrame(const ofVec3f TBN[3])
{
    T = TBN[0];
    B = TBN[1];
    N = TBN[2];
}


ofVec3f FrenetFrame::getT() const
{
    return T;
}

ofVec3f FrenetFrame::getN() const
{
    return N;
}

ofVec3f FrenetFrame::getB() const
{
    return B;
}

void FrenetFrame::display(float len)
{
//     std::cout << "T = " << T.length() << std::endl;
//     std::cout << "B = " << B.length() << std::endl;
//     std::cout << "N = " << N.length()<< std::endl;
    
    glBegin(GL_LINES);
    
    // T = RED
    glColor3f(1, 0, 0);
    glVertex3f(p.x, p.y, p.z);
    glVertex3f(p.x + T.x*len, p.y + T.y*len, p.z + T.z*len);
    
    // B = BLUE
    glColor3f(0, 0, 1);
    glVertex3f(p.x, p.y, p.z);
    glVertex3f(p.x + B.x*len, p.y + B.y*len, p.z + B.z*len);
    
    
    // N = GREEN
    glColor3f(0, 1, 0);
    glVertex3f(p.x, p.y, p.z);
    glVertex3f(p.x + N.x*len, p.y + N.y*len, p.z + N.z*len);
    
    
    
    
    glEnd();
}