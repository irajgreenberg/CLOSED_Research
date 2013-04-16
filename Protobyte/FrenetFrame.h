//
//  FrenetFrame.h
//  Protobyte_iig001
//
//  Created by Ira on 10/15/12.
//
//

#ifndef Protobyte_iig001_FrenetFrame_h
#define Protobyte_iig001_FrenetFrame_h

#ifdef  __APPLE__
  #include <OpenGL/gl.h>
#elif __linux
  #include <GL/gl.h>
#elif defined(_WIN32) || defined(_WIN64)
  #include <GL/gl.h>
#endif

#include "Vector3.h"


namespace proto {   

    class FrenetFrame {
    private:
        Vector3 p, T, N, B;
        
    public:
        friend std::ostream& operator<<(std::ostream& out, const FrenetFrame& frame);
        FrenetFrame();
        FrenetFrame(const Vector3& p, const Vector3& T, const Vector3& B, const Vector3& N);
        FrenetFrame(const Vector3 TBN[3]);
        
        void init();
        Vector3 getT() const;
        Vector3 getN() const;
        Vector3 getB() const;
        
        void display(float len = 10);
        
    };
}

#endif
