//
//  Vector3.h
//  Protobyte Library V01
//
//  Created by Ira Greenberg on 8/2/11.
//  Copyright 2011 SMU. All rights reserved.
//
// Library Usage:
// This work is licensed under the Creative Commons
// Attribution-NonCommercial-ShareAlike 3.0 Unported License.
// To view a copy of this license, visit
// http://creativecommons.org/licenses/by-nc-sa/3.0/
// or send a letter to Creative Commons,
// 444 Castro Street, Suite 900,
// Mountain View, California, 94041, USA.
//

#ifndef Protobyte_Library_V01_Vector3_h
#define Protobyte_Library_V01_Vector3_h

#include <string.h>
#include <iostream>
#include <math.h>


namespace proto {

    /*****************************************************/
    /*            Non-Member Ops & Functions             */
    /*****************************************************/
    class Vector3; // forward declare class for non-member prototypes

    Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
    Vector3 operator-(const Vector3& rhs);
    Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
    Vector3 operator*(const Vector3& lhs, const Vector3& vrhs);
    Vector3 operator*(const Vector3& lhs, double rhs); // is this Kosher?
    Vector3 operator*(double lhs, const Vector3& rhs);
    Vector3 operator/(const Vector3& lhs, const Vector3& rhs);
    Vector3 cross(const Vector3& lhs, const Vector3& rhs);
    double mag(const Vector3& v);
    double dot(const Vector3& lhs, const Vector3& rhs);
    Vector3 rotate(double theta, const Vector3& axis, const Vector3& v);
    double angle(const Vector3& lhs, const Vector3& rhs);

    class Vector3 {
    public:

        // overloaded << operator
        // declared friend function to allow access to private data fields
        friend std::ostream& operator<<(std::ostream& output, const Vector3& vec); 

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
        explicit Vector3(double x = 0.0f, double y = 0.0f, double z = 0.0f, float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 0.0f);
        explicit Vector3(double xyz[3]);
        Vector3(double xyz[3], float RGBA[4]);


        /* Not required since no heap allocation
         // destructor
         ~Vector3();
         
         // copy constructor
         Vector3 (const Vector3& vec);
         
         // assignment op
         Vector3& operator=(const Vector3& vec);
         */

        /*****************************************************/
        /*              Member Overloaded Ops                */
        /*****************************************************/
        Vector3& operator+=(const Vector3& v);
        Vector3& operator+=(double f);
        Vector3& operator-=(const Vector3& v);
        Vector3& operator-=(double f);
        Vector3& operator*=(const Vector3& v);
        Vector3& operator*=(double f);
        Vector3& operator/=(const Vector3& v);
        Vector3& operator/=(double f);
        Vector3& operator++();
        Vector3& operator--();
        double operator[](int index);
        bool operator==(const Vector3 &v) const;

        /*****************************************************/
        /*                 Member Functions                  */
        /*****************************************************/
        double mag();
        void normalize();
        double angle(const Vector3& v);
        double dot(const Vector3& v);
        Vector3 cross(const Vector3& v);
        void crossThis(const Vector3& v);
        double dist(const Vector3& v);
        Vector3& rotate(double theta, const Vector3& axis);

    private:
        // vertex normal
        double nx, ny, nz;
        double nxyz[3];

    };

}

#endif
