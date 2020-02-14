//
//  triangle.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 14.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef triangle_hpp
#define triangle_hpp

#include "shape.hpp"
#include "../datatypes/vector.hpp"

class Triangle : public Shape {
private:
    /** a corner of the triangle ABC */
    Vector3f a_;
    /** a corner of the triangle ABC */
    Vector3f b_;
    /** a corner of the triangle ABC */
    Vector3f c_;
    
public:
    Triangle(Vector3f a, Vector3f b, Vector3f c);
    Triangle(Vector3f a, Vector3f b, Vector3f c, Material* material);
    /** check whether the given ray intersects the sphere */
    bool Intersects(Ray& ray, HitResult& result) override;
};

#endif /* triangle_hpp */
