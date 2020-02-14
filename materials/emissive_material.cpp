//
//  emissive_material.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 14.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "emissive_material.hpp"

EmissiveMaterial::EmissiveMaterial(Color emissive_color, float intensity) : Material(emissive_color){
    intensity_ = intensity;
}

float EmissiveMaterial::Weight(Vector3f surface_normal, Vector3f to_refelect){
    return 0.0f;
}

Color EmissiveMaterial::GetEmissiveColor(){
    return color_ * intensity_;
}
