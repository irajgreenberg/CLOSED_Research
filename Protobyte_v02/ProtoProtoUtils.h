/* 
 * File:   ProtoUtils.h
 * Author: ira
 *
 * Created on April 5, 2013, 10:54 AM
 */

#ifndef PROTOUTILS_H
#define	PROTOUTILS_H

class ProtoUtils {
private:
    // no instantiation
    ProtoUtils();
    
public:
    // static consts
    static const unsigned char FALLOFF_LINEAR = 0x0;
    static const unsigned char FALLOFF_EXPONENTIAL = 0x1;
    static const unsigned char FALLOFF_SINE = 0x10;
    static const unsigned char FALLOFF_COSINE = 0x11;
};

#endif	/* PROTOUTILS_H */

