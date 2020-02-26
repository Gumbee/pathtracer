//
//  camera.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 09.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "camera.hpp"
#include "datatypes/vector.hpp"

#include <math.h>
#include "datatypes/ray.hpp"

Camera::Camera(unsigned int width, unsigned int height, float fov){
    width_ = width;
    height_ = height;
    fov_ = fov;
    // initialize the ray cache
    ray_cache_ = new float[height + width];
    // populate the ray cache
    BuildRayCache();
}

void Camera::BuildRayCache(){
    #pragma omp parallel for
    for(int row=0;row<height_;row++){
        ray_cache_[row] = -(2*(row + 0.5)/(float)height_ - 1)*tanh(fov_/2.);
    }
    #pragma omp parallel for
    for(int col=0;col<width_;col++){
        ray_cache_[height_ + col] = (2*(col + 0.5)/(float)width_  - 1)*tanh(fov_/2.)*width_/(float)height_;
    }
}

Ray Camera::GetRayThroughPixel(unsigned int row, unsigned int column){
    float x = ray_cache_[height_ + column];
    float y = ray_cache_[row];
    
    Vector3f dir = Vector3f(x, y, -1).Normalize();
    
    return Ray(Vector3f(0,0,0), dir);
}
