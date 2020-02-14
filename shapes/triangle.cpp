//
//  triangle.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 14.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "triangle.hpp"

#include<limits>
#include "../materials/diffuse_material.hpp"

Triangle::Triangle(Vector3f a, Vector3f b, Vector3f c) : Triangle(a, b, c, new DiffuseMaterial(Colors::White)) {
}

Triangle::Triangle(Vector3f a, Vector3f b, Vector3f c, Material* material) : Shape(material) {
    a_ = a;
    b_ = b;
    c_ = c;
}

bool Triangle::Intersects(Ray& ray, HitResult& result){
    Vector3f ab = b_ - a_;
    Vector3f ac = c_ - a_;
    Vector3f pvec = ray.direction.Cross(ac);
    
    float det = ab.Dot(pvec);
    float eps = 0.0001f;
    
    if (det < eps) return false;
    //if (fabs(det) < eps) return false;
    
    float invDet = 1.0f / det;

    Vector3f tvec = ray.position - a_;
    
    float u = tvec.Dot(pvec) * invDet;
    
    if (u < 0 || u > 1) return false;

    Vector3f qvec = tvec.Cross(ab);
    float v = ray.direction.Dot(qvec) * invDet;
    
    if (v < 0 || u + v > 1) return false;

    float t = ac.Dot(qvec) * invDet;
    
    result.hit_position = ray.position + ((ray.direction.Normalize() * t));
    result.hit_normal = Vector3f(0,1,0);
    result.t = t;
    result.material = material_;
    result.hit = true;
    
    return true;
}
