//
//  scene.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 09.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "scene.hpp"

#include <assert.h>

#include "random.hpp"

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
    
    Color background = Color(
        120,
        51,
        (ray.direction.y+1)*255*.5f
    );
    
    if(ray.depth > 5){
        return background;
    }
    
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
        /** calculate the direction in which the ray bounces*/
        Vector3f bounce_direction = rand_vec_in_oriented_hemisphere(closest_hit.hit_normal, ray.direction);
        /** create a bounce ray with increased depth */
        Ray bounce_ray = Ray(closest_hit.hit_position + closest_hit.hit_normal, bounce_direction);
        bounce_ray.depth = ray.depth + 1;
        
        // calculate the factor by which we scale the bounce light
        float weight = bounce_direction.Normalize().Dot(closest_hit.hit_normal.Normalize());
        
        return 0.5 * Trace(bounce_ray);
    }
    
    return background;
}

