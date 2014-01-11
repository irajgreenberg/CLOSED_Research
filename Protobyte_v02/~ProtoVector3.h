/*!  \brief  ProtoVector3.h: Base vector implementation
 ProtoVector3.h
 Protobyte Library v02
 
 Created by Ira on 7/23/13.
 Copyright (c) 2013 Ira Greenberg. All rights reserved.
 
 Library Usage:
 This work is licensed under the Creative Commons
 Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 To view a copy of this license, visit
 http://creativecommons.org/licenses/by-nc-sa/3.0/
 or send a letter to Creative Commons,
 444 Castro Street, Suite 900,
 Mountain View, California, 94041, USA.
 
 This notice must be retained any source distribution.
 
 \ingroup common
 This class is part of the group common (update)
 \sa NO LINK
 */

#ifndef PROTO_VECTOR3_H
#define PROTO_VECTOR3_H

#include <string.h>
#include <iostream>
#include <cmath>


namespace ijg {

    /*****************************************************/
    /*            Non-Member Ops & Functions             */
    /*****************************************************/
    class ProtoVector3; // forward declare class for non-member prototypes

    ProtoVector3 operator+(const ProtoVector3& lhs, const ProtoVector3& rhs);
    ProtoVector3 operator-(const ProtoVector3& rhs);
    ProtoVector3 operator-(const ProtoVector3& lhs, const ProtoVector3& rhs);
    ProtoVector3 operator*(const ProtoVector3& lhs, const ProtoVector3& vrhs);
    ProtoVector3 operator*(const ProtoVector3& lhs, double rhs); // is this Kosher?
    ProtoVector3 operator*(double lhs, const ProtoVector3& rhs);
    ProtoVector3 operator/(const ProtoVector3& lhs, const ProtoVector3& rhs);
    ProtoVector3 cross(const ProtoVector3& lhs, const ProtoVector3& rhs);
    double mag(const ProtoVector3& v);
    double dot(const ProtoVector3& lhs, const ProtoVector3& rhs);
    ProtoVector3 rotate(double theta, const ProtoVector3& axis, const ProtoVector3& v);
    double angle(const ProtoVector3& lhs, const ProtoVector3& rhs);

    class ProtoVector3 {
        
        
    public:

        // overloaded << operator
        // declared friend function to allow access to private data fields
        friend std::ostream& operator<<(std::ostream& output, const ProtoVector3& vec); 

        // track total number of vertices
        static int totolVector3Count;

        // vertex coords
        double x, y, z;

        // vertex color
        float r, g, b, a;
        float rgba[4];
        //NOTE: vertex normal declared private below

        /*****************************************************/
        /*                    Constructors                   */
        /*****************************************************/
        explicit ProtoVector3();
        ProtoVector3(double xyz);
        ProtoVector3(double x, double y, double z);
        //explicit ProtoVector3(double x = 0.0f, double y = 0.0f, double z = 0.0f, float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 0.0f);
        ProtoVector3(double xyz[3]);
        //ProtoVector3(double xyz[3], float RGBA[4]);


        /* Not required since no heap allocation
         // destructor
         ~ProtoVector3();
         
         // copy constructor
         ProtoVector3 (const ProtoVector3& vec);
         
         // assignment op
         ProtoVector3& operator=(const ProtoVector3& vec);
         */

        /*****************************************************/
        /*              Member Overloaded Ops                */
        /*****************************************************/
        ProtoVector3& operator+=(const ProtoVector3& v);
        ProtoVector3& operator+=(double f);
        ProtoVector3& operator-=(const ProtoVector3& v);
        ProtoVector3& operator-=(double f);
        ProtoVector3& operator*=(const ProtoVector3& v);
        ProtoVector3& operator*=(double f);
        ProtoVector3& operator/=(const ProtoVector3& v);
        ProtoVector3& operator/=(double f);
        ProtoVector3& operator++();
        ProtoVector3& operator--();
        double operator[](int index);
        bool operator==(const ProtoVector3 &v) const;

        /*****************************************************/
        /*                 Member Functions                  */
        /*****************************************************/
        double mag();
        void normalize();
        double angle(const ProtoVector3& v);
        double dot(const ProtoVector3& v);
        ProtoVector3 cross(const ProtoVector3& v);
        void crossThis(const ProtoVector3& v);
        double dist(const ProtoVector3& v);
        ProtoVector3& rotate(double theta, const ProtoVector3& axis);

    private:
        // vertex normal
        double nx, ny, nz;
        double nxyz[3];

    };

}

#endif // PROTO_VECTOR3_H
