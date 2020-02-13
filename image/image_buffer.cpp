//
//  image_buffer.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 09.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "image_buffer.hpp"

#include <assert.h>

#include "omp.h"

ImageBuffer::ImageBuffer(unsigned int width, unsigned int height) : width_(width), height_(height){
    data_ = new Color[width*height];
}

size_t ImageBuffer::Size(){
    return width_ * height_;
}

void ImageBuffer::Fill(Color color){
    #pragma omp parallel for
    for(int i=0;i<height_;i++){
        for(int j=0;j<width_;j++){
            Set(i, j, color);
        }
    }
}

void ImageBuffer::Set(unsigned int row, unsigned int column, Color color){
    assert(row < height_);
    assert(column < width_);
    
    data_[row*width_+column] = color;
}

Color* ImageBuffer::GetData(){
    return data_;
}
