//
//  ray.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 12.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef ray_hpp
#define ray_hpp

#include "vector.hpp"

struct Ray {
    Vector3f position;
    Vector3f direction;
    
    unsigned int depth;
    
    Ray(Vector3f position, Vector3f direction){
        this->position = position;
        this->direction = direction;
        this->depth = 0;
    }
};

#endif /* ray_hpp */
