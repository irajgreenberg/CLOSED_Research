//
//  Quaternion.h
//  Protobyte_iig001
//
//  Created by Ira on 10/14/12.
//
//

#ifndef Protobyte_iig001_Quaternion_h
#define Protobyte_iig001_Quaternion_h

#include "ofMain.h"

namespace ijg {
    class Quaternion {
       

    public:
        // fields
        float x, y, z, w;
        
        // constructor
        Quaternion(const ofVec3f& axis = ofVec3f(0, 0, 1), float theta = 0);
        Quaternion(float x, float y, float z, float w);
        //void rotate(ofVec3f v);
        ofVec3f getRotate(const ofVec3f& v); // return
        void rotate(ofVec3f& v); // update in place
        float mag() const;
        void normalize();
        
        friend Quaternion& operator*(const Quaternion& q); // need to implement
        void operator*=(const Quaternion& q); // need to implement
        
        void setAxis(const ofVec3f& axis);
        const ofVec3f& getAxis() const;
        
    private:
        ofVec3f axis;
        float theta;

    };
    
}

#endif
