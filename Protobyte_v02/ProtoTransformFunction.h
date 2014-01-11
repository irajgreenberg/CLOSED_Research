
/*! File:   ProtoTransformFunction.h
 * Author: Ira Greenberg
 *
 * Created on May 18, 2013, 10:42 AM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#ifndef PROTO_TRANSFORMFUNCTION_H
#define	PROTO_TRANSFORMFUNCTION_H

#include "ProtoTuple2.h"
#include "ProtoVector3.h"

namespace ijg {

    class ProtoTransformFunction {
    private:
        unsigned char functionType;
        float minValue, maxValue;
        ProtoTuple2<Vec3f> vectorRange;
        ProtoTuple2f scalerRange;
       // bool isRandom;
        short periodCount;
        bool isVectorRange, isScalerRange;

    public:

        /*!
         * Default Constructor */
        ProtoTransformFunction();

        /*!
         * Constructor */
        ProtoTransformFunction(unsigned char functionType, /*bool isRandom = 0, */short periodCount = 1);

        /*!
         * Constructor */
        ProtoTransformFunction(unsigned char functionType, ProtoTuple2v3f vectorRange, /*bool isRandom = 0, */short periodCount = 1);

        /*!
         * Constructor */
        ProtoTransformFunction(unsigned char functionType, ProtoTuple2f scalerRange, /*bool isRandom = 0, */short periodCount = 1);

        /*!
         * Constructor */
        ProtoTransformFunction(unsigned char functionType, float maxValue, /*bool isRandom = 0, */short periodCount = 1);



        /*!
         * getters/setters */

        void setPeriodCount(short periodCount);
        short getPeriodCount() const;
//        void setIsRandom(bool isRandom);
//        bool getIsRandom() const;
        void setScalerRange(ProtoTuple2f scalerRange);
        ProtoTuple2f getScalerRange() const;
        void setVectorRange(ProtoTuple2v3f vectorRange);
        ProtoTuple2v3f getVectorRange() const;
        void setMaxValue(float maxValue);
        float getMaxValue() const;
        void setMinValue(float minValue);
        float getMinValue() const;
        void setFunctionType(unsigned char functionType);
        unsigned char getFunctionType() const;

        bool getIsVectorRange();
        bool getIsScalerRange();

        //  Specifies Cross-section transform functions
        static const unsigned char LINEAR = 0x00;
        static const unsigned char LINEAR_INVERSE = 0x01;
        static const unsigned char SINUSOIDAL = 0x10;
        static const unsigned char SINUSOIDAL_INVERSE = 0x11;
        //static const unsigned char SINUSOIDAL_TRANSFORM_RANDOM = 0x11;

    };

    inline void ProtoTransformFunction::setPeriodCount(short periodCount) {
        this->periodCount = periodCount;
    }

    inline short ProtoTransformFunction::getPeriodCount() const {
        return periodCount;
    }

//    inline void ProtoTransformFunction::setIsRandom(bool isRandom) {
//        this->isRandom = isRandom;
//    }
//
//    inline bool ProtoTransformFunction::getIsRandom() const {
//        return isRandom;
//    }

    inline void ProtoTransformFunction::setScalerRange(ProtoTuple2f scalerRange) {
        this->scalerRange = scalerRange;
    }

    inline ProtoTuple2f ProtoTransformFunction::getScalerRange() const {
        return scalerRange;
    }

    inline void ProtoTransformFunction::setVectorRange(ProtoTuple2<Vec3f> vectorRange) {
        this->vectorRange = vectorRange;
    }

    inline ProtoTuple2v3f ProtoTransformFunction::getVectorRange() const {
        return vectorRange;
    }

    inline void ProtoTransformFunction::setMaxValue(float maxValue) {
        this->maxValue = maxValue;
    }

    inline float ProtoTransformFunction::getMaxValue() const {
        return maxValue;
    }

    inline void ProtoTransformFunction::setMinValue(float minValue) {
        this->minValue = minValue;
    }

    inline float ProtoTransformFunction::getMinValue() const {
        return minValue;
    }

    inline void ProtoTransformFunction::setFunctionType(unsigned char functionType) {
        this->functionType = functionType;
    }

    inline unsigned char ProtoTransformFunction::getFunctionType() const {
        return functionType;
    }

    inline bool ProtoTransformFunction::getIsVectorRange() {
        return isVectorRange;
    }

    inline bool ProtoTransformFunction::getIsScalerRange() {
        return isScalerRange;
    }



}
#endif	/* PROTO_TRANSFORMFUNCTION_H */

