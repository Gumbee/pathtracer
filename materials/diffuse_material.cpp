//
//  diffuse_material.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 14.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "diffuse_material.hpp"

DiffuseMaterial::DiffuseMaterial(Color diffuse_color) : Material(diffuse_color) {
}

Vector3f sample_in_hemisphere(float u1, float u2){
    const double sin_theta = sqrt(fmax(0.0, 1.0 - u1 * u1));
    const double phi = 2.0 * M_PI * u2;
    
    return Vector3f(cos(phi) * sin_theta, sin(phi) * sin_theta, u1);
}

Vector3f DiffuseMaterial::Reflect(Vector3f surface_normal, Vector3f to_refelect){
    Vector3f w = (0.0 > surface_normal.Dot(to_refelect)) ? surface_normal : surface_normal * -1;
    Vector3f _u = Vector3f(0,0,0);
    
    if (fabs(w.x) > 0.1) {
        _u.y = 1.0;
    }
    else {
        _u.x = 1.0;
    }
    
    Vector3f u = _u.Cross(w).Normalize();
    Vector3f v = w.Cross(u);

    Vector3f sample_d = sample_in_hemisphere(rand() % 100 / 100.0f, rand() % 100 / 100.0f);
    
    Vector3f _x = u * sample_d.x;
    Vector3f _y = v * sample_d.y;
    Vector3f _z = w * sample_d.z;
    Vector3f _xy = _x + _y;
    
    return _xy + _z;
}

float DiffuseMaterial::Weight(Vector3f surface_normal, Vector3f to_refelect){
    return 0.5;
}
