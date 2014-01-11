
#include "VerletBall.h"


using namespace proto;

VerletBall::VerletBall() {
}

VerletBall::VerletBall(const Vector3& pos) {
    this->pos = pos;
    posOld = pos;
}

//float VerletBall::dist(const VerletBall& b) {
//
//}

void VerletBall::verlet() {
    Vector3 posTemp = pos;
    pos += (pos - posOld);
    //std::cout << "in VerletBall verlet(), pos = " << pos << std::endl;
    posOld = posTemp;
}