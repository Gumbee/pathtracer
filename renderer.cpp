//
//  renderer.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 12.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "renderer.hpp"
#include "scene.hpp"
#include "camera.hpp"
#include "image/image_buffer.hpp"
#include "datatypes/ray.hpp"
#include "datatypes/color.hpp"
#include "random.hpp"

Renderer::Renderer(unsigned int num_samples){
    num_samples_ = num_samples;
}

ImageBuffer* Renderer::Render(Scene* scene, Camera* camera){
    unsigned int width = camera->GetWidth();
    unsigned int height = camera->GetHeight();
    
    ImageBuffer* buffer = new ImageBuffer(width, height);
    
    /** fill the background yellow */
    buffer->Fill(Colors::Black);
    
    # pragma omp parallel for collapse(2)
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            Ray ray = camera->GetRayThroughPixel(i,j);
            
            Vector3f color_sum = Vector3f(0,0,0);
            
            float jitter = 0.05f;
            
            for(int k=0;k<num_samples_;k++){
                Ray sample_ray = ray;
                // add random jitter to the ray
                sample_ray.position += Vector3f(rand_float()*jitter,rand_float()*jitter,rand_float()*jitter);
                // cast the first ray for the given pixel
                Vector3f color = scene->Trace(sample_ray);
                // set the pixel's color according to the ray trace
                color_sum = color_sum + color;
            }
            
            Vector3f scaled = (color_sum / num_samples_);
            
            if(scaled.Max() > 255){
                scaled = scaled * (255.0f / scaled.Max());
            }
            
            Color color = Color(
                scaled.x,
                scaled.y,
                scaled.z
            );
            
            buffer->Set(i, j, color);
        }
    }
    
    return buffer;
}
