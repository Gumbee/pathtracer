//
//  main.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 11.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include <math.h>
#include <stdlib.h>

#include <iostream>
#include <chrono>
#include <vector>

#include "image/image_writer.hpp"
#include "image/image_buffer.hpp"
#include "examples/example_scenes.hpp"
#include "camera.hpp"
#include "renderer.hpp"

int main(int argc, const char * argv[]) {
    unsigned int width = 800;
    unsigned int height = 500;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    ImageWriter* writer = new ImageWriter(width, height);
    Camera* camera = new Camera(width, height, M_PI/2.0f);
    Renderer* renderer = new Renderer(50);
    Scene* scene = MirrorDebugScene();
    
    /** render an example scene */
    ImageBuffer* buffer = renderer->Render(scene, camera);
    
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    writer->SaveImage("output/output_pathtraced_pic.png", buffer);
    
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
    std::cout << "Time taken: " << duration.count()/1000000.0f << " seconds" << std::endl;
    
    return 0;
}
