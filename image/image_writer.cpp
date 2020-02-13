//
//  image_writer.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 09.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "image_writer.hpp"

#include <assert.h>

#include "stb_image_write.h"

#include "image_buffer.hpp"

ImageWriter::ImageWriter(unsigned int width, unsigned int height){
    width_ = width;
    height_ = height;
    channels_ = 3;
}

void ImageWriter::SaveImage(std::string path, ImageBuffer* buffer){
    assert(buffer->Size() == width_ * height_);
    
    void* data_pointer = &buffer->GetData()[0];
    
    
    stbi_write_png(path.c_str(), width_, height_, channels_, data_pointer, 0);
}
