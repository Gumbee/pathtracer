//
//  example_scenes.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 12.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "example_scenes.hpp"

#include "../materials/diffuse_material.hpp"
#include "../materials/emissive_material.hpp"
#include "../shapes/sphere.hpp"
#include "../shapes/triangle.hpp"
#include "../shapes/light.hpp"

Scene* SingleSphereScene(){
    Scene* scene = new Scene();
    scene->AddObject(new Sphere(Vector3f(0,0,-16), 5.0f));
    
    return scene;
}

Scene* DebugScene(){
    Scene* scene = new Scene();
    scene->AddObject(new Sphere(Vector3f(0,0,-16), 5.0f));
    scene->AddObject(new Sphere(Vector3f(-10,0,-16), 3.0f));
    scene->AddObject(new Sphere(Vector3f(10,0,-16), 10.0f));
    
    return scene;
}

Scene* TriangleDebugScene(){
    Scene* scene = new Scene();
    scene->AddObject(new Sphere(Vector3f(0,0,-16), 5.0f));
    scene->AddObject(new Sphere(Vector3f(-10,0,-16), 3.0f));
    
    float height = -5;
    Vector3f a = Vector3f(20,height,0);
    Vector3f b = Vector3f(20,height,-40);
    Vector3f c = Vector3f(-20,height,-40);
    Vector3f d = Vector3f(-20,height,0);
    scene->AddObject(new Triangle(
        a,
        b,
        c
    ));
    scene->AddObject(new Triangle(
        c,
        d,
        a
    ));
    
    return scene;
}

Scene* MirrorDebugScene(){
    Scene* scene = new Scene();
    scene->AddObject(new Sphere(Vector3f(0,0,-16), 5.0f, new Material(Colors::White)));
    scene->AddObject(new Sphere(Vector3f(-10,-3,-16), 3.0f, new Material(Colors::White)));
    scene->AddObject(new Sphere(Vector3f(10,-2,-16), 4.0f, new DiffuseMaterial(Colors::White)));
    scene->AddObject(new Sphere(Vector3f(7,-4,-12), 2.0f, new DiffuseMaterial(Colors::White)));
    scene->AddObject(new Sphere(Vector3f(4,-5,-13), 1.0f, new DiffuseMaterial(Colors::White)));
    
    float height = -6;
    Vector3f a = Vector3f(20,height,0);
    Vector3f b = Vector3f(20,height,-40);
    Vector3f c = Vector3f(-20,height,-40);
    Vector3f d = Vector3f(-20,height,0);
    scene->AddObject(new Triangle(
        a,
        b,
        c
    ));
    scene->AddObject(new Triangle(
        c,
        d,
        a
    ));
    
    return scene;
}

Scene* LightDebugScene(){
    Scene* scene = new Scene();
    scene->AddObject(new Sphere(Vector3f(0,0,-16), 5.0f, new Material(Colors::White)));
    scene->AddObject(new Sphere(Vector3f(-10,-3,-16), 3.0f, new DiffuseMaterial(Colors::White)));
    scene->AddObject(new Light(Vector3f(-70,70,-60), 30.0f, 15.0f, FlatColors::Blue));
    
    float height = -6;
    Vector3f a = Vector3f(20,height,0);
    Vector3f b = Vector3f(20,height,-40);
    Vector3f c = Vector3f(-20,height,-40);
    Vector3f d = Vector3f(-20,height,0);
    scene->AddObject(new Triangle(
        a,
        b,
        c
    ));
    scene->AddObject(new Triangle(
        c,
        d,
        a
    ));
    
    return scene;
}
