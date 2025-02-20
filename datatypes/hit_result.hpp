//
//  hit_result.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 12.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef hit_result_hpp
#define hit_result_hpp

#include "vector.hpp"
#include "../materials/material.hpp"

struct HitResult {
    Vector3f hit_position;
    Vector3f hit_normal;
    Material* material;
    
    float t;
    bool hit;
    
    HitResult(){
        t = 0;
        hit = false;
    }
};

#endif /* hit_result_hpp */
