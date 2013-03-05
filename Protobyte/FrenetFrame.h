//
//  FrenetFrame.h
//  Protobyte_iig001
//
//  Created by Ira on 10/15/12.
//
//

#ifndef Protobyte_iig001_FrenetFrame_h
#define Protobyte_iig001_FrenetFrame_h

#include "ofMain.h"

namespace ijg {
    
    class FrenetFrame {
    private:
        ofVec3f p, T, N, B;
        
    public:
        friend std::ostream& operator<<(std::ostream& out, const FrenetFrame& frame);
        FrenetFrame();
        FrenetFrame(const ofVec3f& p, const ofVec3f& T, const ofVec3f& B, const ofVec3f& N);
        FrenetFrame(const ofVec3f TBN[3]);
        
        void init();
        ofVec3f getT() const;
        ofVec3f getN() const;
        ofVec3f getB() const;
        
        void display(float len = 10);
        
    };
}

#endif
