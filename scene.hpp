//
//  scene.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 09.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef scene_hpp
#define scene_hpp

#include <stddef.h>

#include <vector>

#include "shapes/shape.hpp"
#include "datatypes/color.hpp"
#include "datatypes/ray.hpp"

class Scene {
private:
    /** list of all objects in the scene */
    std::vector<Shape*> objects_;
public:
    /** return the number of objects in the scene */
    size_t Size();
    /** Add an object to the scene */
    void AddObject(Shape* object);
    /** trace a ray in the scene */
    Color Trace(Ray& ray);
    /** return the scene object at the given index in the scene */
    Shape* operator[](size_t index) const;
};
#endif /* scene_hpp */
