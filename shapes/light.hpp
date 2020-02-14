//
//  light.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 14.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef light_hpp
#define light_hpp

#include "sphere.cpp"
#include "../materials/emissive_material.hpp"

class Light : public Sphere {
public:
    Light(Vector3f position, float radius);
    Light(Vector3f position, float radius, EmissiveMaterial* material);
};

#endif /* light_hpp */
