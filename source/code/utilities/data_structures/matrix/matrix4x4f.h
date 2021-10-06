

//    Description: OpenGL compatible utility class for a 4x4 matrix of floats.
//                 NOTE: This class has been left unoptimized for readability.

#pragma once

#include "code/utilities/data_structures/vector/vector3f.h"
#include <memory>
#include <cmath>

#define DEGTORAD(degree) ((degree) * (3.141592654f / 180.0f))
#define RADTODEG(radian) ((radian) * (180.0f / 3.141592654f))

class matrix4x4f
{
public:

    float m[16];

    matrix4x4f()  { identity(); }

    matrix4x4f( float m0, float m4, float  m8, float m12,
               float m1, float m5, float  m9, float m13,
               float m2, float m6, float m10, float m14,
               float m3, float m7, float m11, float m15 );

    //transformers
    void identity(void);
    void translate(const vector3f &trans);
    void translate_x(const float &dist);
    void translate_y(const float &dist);
    void translate_z(const float &dist);
    void rotate(const float &angle, vector3f &axis);
    void rotate_x(const float &angle);
    void rotate_y(const float &angle);
    void rotate_z(const float &angle);
    void scale(const vector3f &scale);
    void transformPoint( vector3f *vec );
    void transformVector( vector3f *vec );
    
    //observers
    float* getComponents() { return m;}

    //operators
    matrix4x4f operator + (const matrix4x4f &other);
    matrix4x4f operator - (const matrix4x4f &other);
    matrix4x4f operator * (const matrix4x4f &other);

    matrix4x4f operator * (const float scalar);
};

matrix4x4f::matrix4x4f( float m0, float m4, float  m8, float m12,
                      float m1, float m5, float  m9, float m13,
                      float m2, float m6, float m10, float m14,
                      float m3, float m7, float m11, float m15 )
{
    m[0]=m0; m[4]=m4; m[8] =m8;  m[12]=m12;
    m[1]=m1; m[5]=m5; m[9] =m9;  m[13]=m13;
    m[2]=m2; m[6]=m6; m[10]=m10; m[14]=m14;
    m[3]=m3; m[7]=m7; m[11]=m11; m[15]=m15;
}

void matrix4x4f::identity( void )
{
    m[0]=1.0f; m[4]=0.0f; m[8] =0.0f; m[12]=0.0f;
    m[1]=0.0f; m[5]=1.0f; m[9] =0.0f; m[13]=0.0f;
    m[2]=0.0f; m[6]=0.0f; m[10]=1.0f; m[14]=0.0f;
    m[3]=0.0f; m[7]=0.0f; m[11]=0.0f; m[15]=1.0f;
}

void matrix4x4f::translate( const vector3f &trans )
{
    identity();

    m[12] = trans.x;
    m[13] = trans.y;
    m[14] = trans.z;
}

void matrix4x4f::translate_x( const float &dist )
{
    identity();

    m[12] = dist;
}

void matrix4x4f::translate_y( const float &dist )
{
    identity();

    m[13] = dist;
}

void matrix4x4f::translate_z( const float &dist )
{
    identity();

    m[14] = dist;
}

void matrix4x4f::rotate( const float &angle, vector3f &axis )
{
    float s = sin(DEGTORAD(angle));
    float c = cos(DEGTORAD(angle));

    axis.normalize();

    float ux = axis.x;
    float uy = axis.y;
    float uz = axis.z;
    
    m[0]  = c + (1-c) * ux;
    m[1]  = (1-c) * ux*uy + s*uz;
    m[2]  = (1-c) * ux*uz - s*uy;
    m[3]  = 0;
    
    m[4]  = (1-c) * uy*ux - s*uz;
    m[5]  = c + (1-c) * pow(uy,2);
    m[6]  = (1-c) * uy*uz + s*ux;
    m[7]  = 0;
    
    m[8]  = (1-c) * uz*ux + s*uy;
    m[9]  = (1-c) * uz*uz - s*ux;
    m[10] = c + (1-c) * pow(uz,2);
    m[11] = 0;
    
    m[12] = 0;
    m[13] = 0;
    m[14] = 0;
    m[15] = 1;
}

void matrix4x4f::rotate_x( const float &angle )
{
    float s = sin(DEGTORAD(angle));
    float c = cos(DEGTORAD(angle));

    identity();

    m[5]  =  c;
    m[6]  =  s;
    m[9]  = -s;
    m[10] =  c;
}

void matrix4x4f::rotate_y( const float &angle )
{
    float s = sin(DEGTORAD(angle));
    float c = cos(DEGTORAD(angle));

    identity();

    m[0]  =  c;
    m[2]  = -s;
    m[8]  =  s;
    m[10] =  c;
}

void matrix4x4f::rotate_z( const float &angle )
{
    float s = sin(DEGTORAD(angle));
    float c = cos(DEGTORAD(angle));

    identity();

    m[0] =  c;
    m[1] =  s;
    m[4] = -s;
    m[5] =  c;
}

void matrix4x4f::scale( const vector3f &scale )
{
    identity();

    m[0]  = scale.x;
    m[5]  = scale.y;
    m[10] = scale.z;
}

void matrix4x4f::transformPoint( vector3f *vec )
{
    vector3f &v = *vec;

    float x = v.x;
    float y = v.y;
    float z = v.z;

    v.x = x * m[0] +
          y * m[4] +
          z * m[8] + m[12];

    v.y = x * m[1] +
          y * m[5] +
          z * m[9] + m[13];

    v.z = x * m[2] +
          y * m[6] +
          z * m[10]+ m[14];
}

void matrix4x4f::transformVector( vector3f *vec )
{
    vector3f &v = *vec;

    float x = v.x;
    float y = v.y;
    float z = v.z;

    v.x = x * m[0] +
          y * m[4] +
          z * m[8];

    v.y = x * m[1] +
          y * m[5] +
          z * m[9];

    v.z = x * m[2] +
          y * m[6] +
          z * m[10];
}

matrix4x4f matrix4x4f::operator + ( const matrix4x4f &other )
{
    matrix4x4f result;

    result.m[0]  = m[0]  + other.m[0];
    result.m[1]  = m[1]  + other.m[1];
    result.m[2]  = m[2]  + other.m[2];
    result.m[3]  = m[3]  + other.m[3];

    result.m[4]  = m[4]  + other.m[4];
    result.m[5]  = m[5]  + other.m[5];
    result.m[6]  = m[6]  + other.m[6];
    result.m[7]  = m[7]  + other.m[7];

    result.m[8]  = m[8]  + other.m[8];
    result.m[9]  = m[9]  + other.m[9];
    result.m[10] = m[10] + other.m[10];
    result.m[11] = m[11] + other.m[11];

    result.m[12] = m[12] + other.m[12];
    result.m[13] = m[13] + other.m[13];
    result.m[14] = m[14] + other.m[14];
    result.m[15] = m[15] + other.m[15];

    return result;
}

matrix4x4f matrix4x4f::operator - ( const matrix4x4f &other )
{
    matrix4x4f result;

    result.m[0]  = m[0]  - other.m[0];
    result.m[1]  = m[1]  - other.m[1];
    result.m[2]  = m[2]  - other.m[2];
    result.m[3]  = m[3]  - other.m[3];

    result.m[4]  = m[4]  - other.m[4];
    result.m[5]  = m[5]  - other.m[5];
    result.m[6]  = m[6]  - other.m[6];
    result.m[7]  = m[7]  - other.m[7];

    result.m[8]  = m[8]  - other.m[8];
    result.m[9]  = m[9]  - other.m[9];
    result.m[10] = m[10] - other.m[10];
    result.m[11] = m[11] - other.m[11];

    result.m[12] = m[12] - other.m[12];
    result.m[13] = m[13] - other.m[13];
    result.m[14] = m[14] - other.m[14];
    result.m[15] = m[15] - other.m[15];

    return result;
}

matrix4x4f matrix4x4f::operator * ( const matrix4x4f &other )
{
    matrix4x4f result;

    result.m[0]  = (m[0]*other.m[0])+(m[4]*other.m[1])+(m[8]*other.m[2])+(m[12]*other.m[3]);
    result.m[1]  = (m[1]*other.m[0])+(m[5]*other.m[1])+(m[9]*other.m[2])+(m[13]*other.m[3]);
    result.m[2]  = (m[2]*other.m[0])+(m[6]*other.m[1])+(m[10]*other.m[2])+(m[14]*other.m[3]);
    result.m[3]  = (m[3]*other.m[0])+(m[7]*other.m[1])+(m[11]*other.m[2])+(m[15]*other.m[3]);

    result.m[4]  = (m[0]*other.m[4])+(m[4]*other.m[5])+(m[8]*other.m[6])+(m[12]*other.m[7]);
    result.m[5]  = (m[1]*other.m[4])+(m[5]*other.m[5])+(m[9]*other.m[6])+(m[13]*other.m[7]);
    result.m[6]  = (m[2]*other.m[4])+(m[6]*other.m[5])+(m[10]*other.m[6])+(m[14]*other.m[7]);
    result.m[7]  = (m[3]*other.m[4])+(m[7]*other.m[5])+(m[11]*other.m[6])+(m[15]*other.m[7]);

    result.m[8]  = (m[0]*other.m[8])+(m[4]*other.m[9])+(m[8]*other.m[10])+(m[12]*other.m[11]);
    result.m[9]  = (m[1]*other.m[8])+(m[5]*other.m[9])+(m[9]*other.m[10])+(m[13]*other.m[11]);
    result.m[10] = (m[2]*other.m[8])+(m[6]*other.m[9])+(m[10]*other.m[10])+(m[14]*other.m[11]);
    result.m[11] = (m[3]*other.m[8])+(m[7]*other.m[9])+(m[11]*other.m[10])+(m[15]*other.m[11]);

    result.m[12] = (m[0]*other.m[12])+(m[4]*other.m[13])+(m[8]*other.m[14])+(m[12]*other.m[15]);
    result.m[13] = (m[1]*other.m[12])+(m[5]*other.m[13])+(m[9]*other.m[14])+(m[13]*other.m[15]);
    result.m[14] = (m[2]*other.m[12])+(m[6]*other.m[13])+(m[10]*other.m[14])+(m[14]*other.m[15]);
    result.m[15] = (m[3]*other.m[12])+(m[7]*other.m[13])+(m[11]*other.m[14])+(m[15]*other.m[15]);

    return result;
}

matrix4x4f matrix4x4f::operator * ( const float scalar )
{
    matrix4x4f result;

    result.m[0]  = m[0]  * scalar;
    result.m[1]  = m[1]  * scalar;
    result.m[2]  = m[2]  * scalar;
    result.m[3]  = m[3]  * scalar;

    result.m[4]  = m[4]  * scalar;
    result.m[5]  = m[5]  * scalar;
    result.m[6]  = m[6]  * scalar;
    result.m[7]  = m[7]  * scalar;

    result.m[8]  = m[8]  * scalar;
    result.m[9]  = m[9]  * scalar;
    result.m[10] = m[10] * scalar;
    result.m[11] = m[11] * scalar;

    result.m[12] = m[12] * scalar;
    result.m[13] = m[13] * scalar;
    result.m[14] = m[14] * scalar;
    result.m[15] = m[15] * scalar;

    return result;
}