//
//  vector.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 09.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef vector_hpp
#define vector_hpp

#include <stddef.h>
#include <math.h>
#include <assert.h>

template<class data_type>
struct Vector {
    data_type x;
    data_type y;
    data_type z;
    
    /** compute the dot product between the given vector and this vector */
    float Dot(const Vector& other);
    /** normalize the vector to unit length */
    Vector Normalize();
    /** return the cross product of this vector and the given one */
    Vector Cross(Vector& other);
    /** get the length of the vector */
    float Size();
    
    Vector(){
    }
    
    Vector(data_type x, data_type y, data_type z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

typedef Vector<float> Vector3f;

template<class data_type>
inline void operator+=(Vector<data_type>& a, Vector<data_type> b){
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
}

template<class data_type>
inline Vector<data_type> operator+(Vector<data_type> a, Vector<data_type> b){
    return Vector<data_type>(a.x + b.x, a.y + b.y, a.z + b.z);
}

template<class data_type>
inline Vector<data_type> operator-(Vector<data_type>& a){
    return Vector<data_type>(-a.x, -a.y, -a.z);
}

template<class data_type>
inline Vector<data_type> operator-(Vector<data_type> a, Vector<data_type> b){
    return Vector<data_type>(a.x - b.x, a.y - b.y, a.z - b.z);
}

template<class data_type>
inline Vector<data_type> operator*(Vector<data_type>& a, Vector<data_type>& b){
    return Vector<data_type>(a.x * b.x, a.y * b.y, a.z * b.z);
}

template<class data_type>
inline Vector<data_type> operator*(float a, Vector<data_type> b){
    return b*a;
}

template<class data_type>
inline Vector<data_type> operator*(Vector<data_type> a, float b){
    return Vector<data_type>(a.x * b, a.y * b, a.z * b);
}

template<class data_type>
inline Vector<data_type>& operator/(float a, Vector<data_type>& b){
    return b/a;
}

template<class data_type>
inline Vector<data_type>& operator/(Vector<data_type>& a, float b){
    return Vector<data_type>(a.x / b, a.y / b, a.z / b);
}

template<class data_type>
inline Vector<data_type> Vector<data_type>::Normalize(){
    float size = Size();
    
    return Vector<data_type>(x/size, y/size, z/size);
}

template<class data_type>
inline Vector<data_type> Vector<data_type>::Cross(Vector<data_type>& other){
    return Vector<data_type>(y*other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

template<class data_type>
float Vector<data_type>::Dot(const Vector<data_type>& other){
    return x * other.x + y * other.y + z * other.z;
}

template<class data_type>
float Vector<data_type>::Size(){
    return sqrt(x*x + y*y + z*z);
}

inline Vector<float> operator+(Vector<float>& a, Vector<unsigned char>& b){
    return Vector<float>(a.x + b.x, a.y + b.y, a.z + b.z);
}

#endif /* vector_hpp */

