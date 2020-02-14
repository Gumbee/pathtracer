//
//  sphere.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 12.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "sphere.hpp"

#include<limits>
#include "../materials/diffuse_material.hpp"

Sphere::Sphere(Vector3f position, float radius) : Sphere(position, radius, new DiffuseMaterial(Colors::White)) {
}

Sphere::Sphere(Vector3f position, float radius, Material* material) : Shape(material){
    position_ = position;
    radius_ = radius;
}

bool Sphere::Intersects(Ray& ray, HitResult& result){
    Vector3f diff = position_ - ray.position;
    
    float tca = diff.Dot(ray.direction);
    float d2 = diff.Dot(diff) - tca*tca;
    
    if(d2 > radius_*radius_)
        return false;
    
    float thc = sqrtf(radius_*radius_ - d2);
    float t0 = tca - thc;
    float t1 = tca + thc;
    
    if(t0 < 0)
        t0 = t1;
    
    if(t0 < 0)
        return false;
    
    Vector3f scaled_dir = ray.direction * t0;
    result.hit_position = ray.position + scaled_dir;
    result.hit_normal = (result.hit_position - position_).Normalize();
    result.t = t0;
    result.material = material_;
    result.hit = true;
    
    return true;
}
