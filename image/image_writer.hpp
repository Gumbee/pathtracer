//
//  image_writer.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 09.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef image_writer_hpp
#define image_writer_hpp

#include <stdio.h>

#include <vector>
#include <string>

struct ImageBuffer;

class ImageWriter {
private:
    unsigned int width_;
    unsigned int height_;
    unsigned int channels_;
    
public:
    /** create an image writer for images of the given height and width */
    ImageWriter(unsigned int width, unsigned int height);
    
    /** save the given data to an image */
    void SaveImage(std::string path, ImageBuffer* buffer);
};

#endif /* image_writer_hpp */
