//
//  example_scenes.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 12.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "example_scenes.hpp"

#include "../shapes/sphere.hpp"

Scene* GetDebugScene(){
    Scene* scene = new Scene();
    scene->AddObject(new Sphere(Vector3f(0,0,-16), 5.0f));
    scene->AddObject(new Sphere(Vector3f(-10,0,-16), 3.0f));
    scene->AddObject(new Sphere(Vector3f(10,0,-16), 10.0f));
    
    return scene;
}
