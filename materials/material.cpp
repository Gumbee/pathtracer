//
//  material.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 14.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "material.hpp"

#include <math.h>
#include <stdlib.h>

#include "../random.hpp"

Material::Material(Color diffuse_color){
    this->diffuse_color_ = diffuse_color;
}

Material::Material(Color diffuse_color, Color emissive_color){
    this->diffuse_color_ = diffuse_color;
    this->emissive_color_ = emissive_color;
}

Vector3f Material::Reflect(Vector3f surface_normal, Vector3f to_refelect){
    Vector3f proj_scaled_normal = surface_normal * 2 * surface_normal.Dot(to_refelect);
    Vector3f reflection = (to_refelect - proj_scaled_normal).Normalize();
    return reflection.Normalize();
}

float Material::Weight(Vector3f surface_normal, Vector3f to_refelect){
    return 0.9;
}
