//
//  light.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 14.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "light.hpp"

Light::Light(Vector3f position, float radius) : Light(position, radius, new EmissiveMaterial(Colors::White)) {
}

Light::Light(Vector3f position, float radius, EmissiveMaterial* material) : Sphere(position, radius, material){
}
