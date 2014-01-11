
//#include <OpenGL.framework/Headers/gl.h>

#include "VerletStick.h"


using namespace proto;

VerletStick::VerletStick() {
}

VerletStick::VerletStick(VerletBall* b1_ptr, VerletBall* b2_ptr, float tension, Tuple2f elasticity) :
b1_ptr(b1_ptr), b2_ptr(b2_ptr), tension(tension), elasticity(elasticity){

    // std::cout << "address in cstr b1_ptr = " << b1_ptr << std::endl;
    vecOrig = b2_ptr->pos - b1_ptr->pos;
    //std::cout << "vecOrig = " << vecOrig << std::endl;
    len = b1_ptr->pos.dist(b2_ptr->pos);
    //std::cout << "len = " << len << std::endl;

    //    std::cout << "upper b1_ptr->pos = " << b1_ptr->pos << std::endl;
    //     std::cout << "upper b2_ptr->pos = " << b2_ptr->pos << std::endl;

    //    std::cout << "upper &b1_ptr = " << b1_ptr << std::endl;
    //    std::cout << "upper &b2_ptr = " << b2_ptr << std::endl;
}

VerletStick::VerletStick(VerletBall& b1, VerletBall& b2, float tension) :
b1(b1), b2(b2), tension(tension) {
    vecOrig = b2.pos - b1.pos;
    //std::cout << "vecOrig = " << vecOrig << std::endl;
    len = b1.pos.dist(b2.pos);

    //std::cout << "len = " << len << std::endl;
}

//VerletStick::VerletStick(const VerletStick& vs) {
//    b1 = vs.b1;
//    b2 = vs.b2;
//   // b1_ptr = 0;
//   // b2_ptr = 0;
//    b1_ptr = vs.b1_ptr;
//    b2_ptr = vs.b2_ptr;
//    tension = vs.tension;
//    vecOrig = vs.vecOrig;
//    len = vs.len;
//}

void VerletStick::printFields() {
    //    std::cout << "in printFields() b1_ptr.pos = " << b1_ptr->pos << std::endl;
    //    std::cout << "in printFields() b2_ptr.pos = " << b2_ptr->pos << std::endl;

}

void VerletStick::constrainLen() {
    //std::cout << "address in constrainLen() b1_ptr = " << b1_ptr << std::endl;
    //std::cout << "in constrainLen() b1.pos = " << b1.pos << std::endl;
    //std::cout << "in constrainLen() b2.pos = " << b2.pos << std::endl;
    //         std::cout << "in constrainLen() b1_ptr->pos = " << b1_ptr->pos << std::endl;
    //         std::cout << "in constrainLen() b2_ptr->pos = " << b2_ptr->pos << std::endl;
    //        std::cout << "upper b2_ptr->getPos() = " << b2_ptr->getPos() << std::endl;
    //std::cout<<"In VerletSys constrainLen()" <<std::endl;
    // std::cout<<"lower b1_ptr->getPos() = " << b1_ptr->getPos()<<std::endl;

    // collision code 
    for (int i = 0; i < 1; i++) {
        Vector3 delta = b2_ptr->pos - b1_ptr->pos;
        //std::cout << "b1_ptr->pos = " << b1_ptr->pos << std::endl;
        //std::cout << "b2_ptr->pos = " << b2_ptr->pos << std::endl;
        //std::cout << "delta = " << delta << std::endl;
        float deltaLength = delta.mag();

        //std::cout << "len = " << len << std::endl;
        //std::cout << "deltaLength = " << deltaLength << std::endl;
        //std::cout << "deltaLength - len = " << (deltaLength - len) << std::endl;
        float difference = ((deltaLength - len) / deltaLength);
        //std::cout << "difference = " << difference << std::endl;
        //b1.setPos(b1.getPos() + delta * (0.5f * tension * difference));
        //b2.setPos(b2.getPos() - delta * (0.5f * tension * difference));

        //std::cout << "delta * (0.5f * tension * difference)" << delta * (0.5f * tension * difference) << std::endl;
        //b1_ptr->setPos(b1_ptr->getPos() + delta * (0.5f * tension * difference));
        //b2_ptr->setPos(b2_ptr->getPos() - delta * (0.5f * tension * difference));

        b1_ptr->pos += delta * elasticity.elem0 * tension * difference;
        b2_ptr->pos -= delta * elasticity.elem1 * tension * difference;


    }
}

void VerletStick::display(){
    //glColor3f(1, .5, 0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(b1_ptr->pos.x, b1_ptr->pos.y, b1_ptr->pos.z);
    glVertex3f(b2_ptr->pos.x, b2_ptr->pos.y, b2_ptr->pos.z);
    glEnd();
}
