//
//  sphere.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 12.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef sphere_hpp
#define sphere_hpp

#include "shape.hpp"
#include "../datatypes/vector.hpp"

class Sphere : public Shape {
private:
    /** the three dimensional location of the sphere (location is given in metres) */
    Vector3f position_;
    /** the size (radius) of the sphere (in metres) */
    float radius_;
    
public:
    Sphere(Vector3f position, float radius);
    /** check whether the given ray intersects the sphere */
    bool Intersects(Ray& ray, HitResult& result) override;
};

#endif /* sphere_hpp */
