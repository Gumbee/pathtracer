//
//  emissive_material.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 14.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef emissive_material_hpp
#define emissive_material_hpp

#include "material.hpp"

class EmissiveMaterial : public Material {
public:
    EmissiveMaterial(Color emissive_color);
    
    float Weight(Vector3f surface_normal, Vector3f to_refelect) override;
};

#endif /* emissive_material_hpp */
