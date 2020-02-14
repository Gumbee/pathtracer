//
//  material.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 14.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef material_hpp
#define material_hpp

#include "../datatypes/color.hpp"
#include "../datatypes/vector.hpp"

class Material {
public:
    Color diffuse_color_;
    Color emissive_color_;

public:
    Material(Color diffuse_color);
    Material(Color diffuse_color, Color emissive_color);
    
    virtual Vector3f Reflect(Vector3f surface_normal, Vector3f to_refelect);
    virtual float Weight(Vector3f surface_normal, Vector3f to_refelect);
};


#endif /* material_hpp */
