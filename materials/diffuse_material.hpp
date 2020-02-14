//
//  diffuse_material.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 14.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef diffuse_material_hpp
#define diffuse_material_hpp

#include "material.hpp"

class DiffuseMaterial : public Material {
public:
    DiffuseMaterial(Color diffuse_color);
    
    Vector3f Reflect(Vector3f surface_normal, Vector3f to_refelect) override;
    float Weight(Vector3f surface_normal, Vector3f to_refelect) override;
};

#endif /* diffuse_material_hpp */
