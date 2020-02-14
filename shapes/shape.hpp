//
//  shape.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 12.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef shape_hpp
#define shape_hpp

#include "../datatypes/ray.hpp"
#include "../datatypes/hit_result.hpp"
#include "../materials/material.hpp"

class Shape {
protected:
    Material* material_;
public:
    Shape(Material* material);
    /** check whether or not a given ray intersects the shape */
    virtual bool Intersects(Ray& ray, HitResult& result) = 0;
};

#endif /* shape_hpp */
