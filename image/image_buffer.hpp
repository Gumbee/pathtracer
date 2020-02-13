//
//  image_buffer.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 09.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef image_buffer_hpp
#define image_buffer_hpp

#include <stddef.h>

#include "../datatypes/color.hpp"

class ImageBuffer {
private:
    /** buffer settings */
    unsigned int width_;
    unsigned int height_;
    /** the content of the buffer */
    Color* data_;
    
public:
    ImageBuffer(unsigned int width, unsigned int height);
    /** returns the size of the buffer */
    size_t Size();
    /** fill the buffer with the given buffer (overrides any buffer content) */
    void Fill(Color color);
    /** fill the buffer with the given buffer (overrides any buffer content) */
    void Set(unsigned int row, unsigned int column, Color color);
    /** return the content of the buffer */
    Color* GetData();
};

#endif /* image_buffer_hpp */
