/*! \Class to extrude a polygon cross-section along spline path
 * Uses parallel transport to avoid twists
 * File:   Tube.h
 * Author: Ira Greenberg
 * Created by Ira on 10/17/12.
 */


#ifndef Protobyte_iig001_Tube_h
#define Protobyte_iig001_Tube_h

#include <iostream>
#include "ProtoGeom3.h"
#include "TransformFunction.h"
#include "Spline3.h"
#include "VerletSpine.h"
//#include "EllipticalWing.h"

namespace proto {
    
    class Tube : public ProtoGeom3 {
    public:
        
        friend std::ostream& operator<<(std::ostream& out, const Tube& tube);
        
        /*!
         * Constructor */
        Tube();
        
        /*!
         * Constructor
         */
        Tube(const Spline3& path, float radius, int crossSectionDetail, bool isClosed = true);
        
        /*!
         * Constructor
         * with TransformFunction object
         */
        Tube(const Spline3& path, float radius, int crossSectionDetail, const TransformFunction& transFuncObj, bool isClosed = true);
        
        /*!
         * Constructor
         * with TransformFunction object
         */
        Tube(const Spline3& path, std::vector<float>& radii, int crossSectionDetail, const TransformFunction& transFuncObj, bool isClosed = true);
        
        /*!
         * Constructor
         * varied thickness*/
        Tube(const Spline3& path, std::vector<float>& radii, int crossSectionDetail, bool isClosed = true);
        
        /*!
         * Constructor
         * varied color*/
        Tube(const std::vector<Color4f>& col4s, const Spline3& path, float radius, int crossSectionDetail, bool isClosed = true);
        
        /*!
         * Constructor
         * varied color and TransformFunction object*/
        Tube(const std::vector<Color4f>& col4s, const Spline3& path, float radius, int crossSectionDetail, const TransformFunction& transFuncObj, bool isClosed = true);
        
        /*!
         * Constructor
         * varied thickness and color */
        Tube(const std::vector<Color4f>& col4s, const Spline3& path, std::vector<float>& radii, int crossSectionDetail, bool isClosed = true);
        
        /*!
         * Constructor
         * All */
        Tube(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, const Spline3& path, float radius, int crossSectionDetail, bool isClosed = true);
        
        /*!
         * Constructor
         * All with TransformFunction obj*/
        Tube(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, const Spline3& path, float radius, int crossSectionDetail, const TransformFunction& transFuncObj, bool isClosed = true);
        
        /*!
         * Constructor
         * All with varied radii*/
        Tube(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, const Spline3& path, std::vector<float>& radii, int crossSectionDetail, bool isClosed = true);
        
        /*!
         * Constructor
         * all with varied color */
        Tube(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const std::vector<Color4f>& col4s, const Spline3& path, float radius, int crossSectionDetail, bool isClosed = true);
        
        /*!
         * Constructor
         * all with varied color and TransformFunction obj */
        Tube(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const std::vector<Color4f>& col4s, const Spline3& path, float radius, int crossSectionDetail, const TransformFunction& transFuncObj, bool isClosed = true);
        
        /*!
         * Constructor
         * All with varied thickness and color */
        Tube(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const std::vector<Color4f>& col4s, const Spline3& path, std::vector<float>& radii, int crossSectionDetail, bool isClosed = true);
        
        
        
        ~Tube();
        
        
        
        
        /*! overrides base class virtual functions
         */
        void calcVerts();
        
        /*! overrides base class virtual functions
         */
        void calcInds();
        
        
        /*! getters | setters prototypes
         */
        void setFrenetFrameLength(int frenetFrameLength);
        int getFrenetFrameLength() const;
        void setCrossSectionDetail(int crossSectionDetail);
        int getCrossSectionDetail() const;
        void setRadii(std::vector<float> radii);
        std::vector<float> getRadii() const;
        void setRadius(float radius);
        float getRadius() const;
        void setPath(Spline3 path);
        Spline3 getPath() const;
        void setIsClosed(bool isClosed);
        bool isIsClosed() const;
        void setTransFuncObj(TransformFunction transFuncObj);
        TransformFunction getTransFuncObj() const;
        void setIsTransformFunction(bool isTransformFunction);
        bool getIsTransformFunction() const;
        void setPerturbation(const Vector3& perturbation);
        Vector3 getPerturbation() const;
        void rotateY();
        void breath();
        void wave();
        void verlet();
        void live();
        const std::vector<FrenetFrame>& getFrenetFrame() const;
        
        // for live states
        void setIsSlithering(bool isSlithering);
        bool getIsSlithering() const;
        void setIsBreathing(bool isBreathing);
        bool getIsBreathing() const;
        
        
        // enables varying tube radii values
        
        /* enum TransformFunction {
         LINEAR,
         LINEAR_INVERSE,
         SINUSOIDAL,
         SINUSOIDAL_2,
         SINUSOIDAL_3,
         SINUSOIDAL_4,
         SINUSOIDAL_5,
         SINUSOIDAL_RAND_5,
         SINUSOIDAL_RAND_10,
         SINUSOIDAL_RAND_15,
         SINUSOIDAL_RAND_20,
         SINUSOIDAL_RAND_25,
         SINUSOIDAL_RAND_30,
         SINUSOIDAL_RAND_35,
         SINUSOIDAL_RAND_40
         };*/
        
        
    private:
        Spline3 path;
        float radius;
        std::vector<float> radii;
        int crossSectionDetail;
        int frenetFrameLength;
        bool isClosed;
        TransformFunction transFuncObj;
        bool isTransformFunction;
        Vector3 perturbation;
        std::vector<Vector3> crossSectionCentroids;
        
        // spline stuff
        VerletSpine vSpine;
        // local frames of reference
        std::vector<FrenetFrame> ff;
        
        // for Verlet Integration - NEED to fix this eventually
        // for now using individual sticks and balls
        //VerletSys verletSys;
        //        std::vector<VerletBall> vBalls;
        //        std::vector<VerletStick> vSticks;
        //        std::vector<Vector3> testingVerts;
        
        //        VerletBall vbs[4];
        //        VerletStick vss[6];
        
        //std::vector<Vector3> testingVerts;
        
        // live states NOTE - maybe move to derived arthropod class
        bool isBreathing, isSlithering;
        
        // wings
        // std::vector<EllipticalWing> wings;
        
    };
    
    // inline getters | setters
    
    inline void Tube::setFrenetFrameLength(int frenetFrameLength) {
        this->frenetFrameLength = frenetFrameLength;
    }
    
    inline int Tube::getFrenetFrameLength() const {
        return frenetFrameLength;
    }
    
    inline void Tube::setCrossSectionDetail(int crossSectionDetail) {
        this->crossSectionDetail = crossSectionDetail;
    }
    
    inline int Tube::getCrossSectionDetail() const {
        return crossSectionDetail;
    }
    
    inline void Tube::setRadii(std::vector<float> radii) {
        this->radii = radii;
    }
    
    inline std::vector<float> Tube::getRadii() const {
        return radii;
    }
    
    inline void Tube::setRadius(float radius) {
        this->radius = radius;
    }
    
    inline float Tube::getRadius() const {
        return radius;
    }
    
    inline void Tube::setPath(Spline3 path) {
        this->path = path;
    }
    
    inline Spline3 Tube::getPath() const {
        return path;
    }
    
    inline void Tube::setIsClosed(bool isClosed) {
        this->isClosed = isClosed;
    }
    
    inline bool Tube::isIsClosed() const {
        return isClosed;
    }
    
    inline void Tube::setTransFuncObj(TransformFunction transFuncObj) {
        this->transFuncObj = transFuncObj;
        setIsTransformFunction(true);
    }
    
    inline TransformFunction Tube::getTransFuncObj() const {
        return transFuncObj;
    }
    
    inline void Tube::setIsTransformFunction(bool isTransformFunction) {
        this->isTransformFunction = isTransformFunction;
    }
    
    inline bool Tube::getIsTransformFunction() const {
        return isTransformFunction;
    }
    
    inline void Tube::setPerturbation(const Vector3& perturbation) {
        this->perturbation = perturbation;
        init();
    }
    
    inline Vector3 Tube::getPerturbation() const {
        return perturbation;
    }
    
    inline const std::vector<FrenetFrame>& Tube::getFrenetFrame() const {
        return ff;
    }
    
    inline void Tube::setIsSlithering(bool isSlithering) {
        this->isSlithering = isSlithering;
    }
    
    inline bool Tube::getIsSlithering() const {
        return isSlithering;
    }
    
    inline void Tube::setIsBreathing(bool isBreathing) {
        this->isBreathing = isBreathing;
    }
    
    inline bool Tube::getIsBreathing() const {
        return isBreathing;
    }
    
}


#endif
