//
//  scene.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 09.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "scene.hpp"

#include <assert.h>

size_t Scene::Size(){
    return objects_.size();
}

void Scene::AddObject(Shape* object){
    objects_.push_back(object);
}

Shape* Scene::operator[](size_t index) const{
    assert(index < objects_.size());
   
    return objects_[index];
}

Color Scene::Trace(Ray& ray){
    size_t size = Size();

    HitResult closest_hit;
    
    for(int i=0;i<size;i++){
        Shape* shape = objects_[i];
        
        HitResult hit_result;
        
        if(shape->Intersects(ray, hit_result)){
            if(hit_result.t < closest_hit.t || !closest_hit.hit){
                closest_hit = hit_result;
            }
        }
    }
    
    if(closest_hit.hit){
        return Color(
            (closest_hit.hit_normal.x+1)*0.5*255,
            (closest_hit.hit_normal.y+1)*0.5*255,
            (closest_hit.hit_normal.z+1)*0.5*255
        );
    }
    
    return Colors::Black;
}

