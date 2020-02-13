//
//  camera.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 09.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef camera_hpp
#define camera_hpp

struct Ray;

class Camera {
private:
    /** image width and height */
    unsigned int width_;
    unsigned int height_;
    /** camera field of vision */
    float fov_;
    /** small optimization to get rid of redundant calculations */
    float* ray_cache_;
    
protected:
    /** build the cache of rays which can be shot out of our camera */
    void BuildRayCache();
    
public:
    Camera(unsigned int width, unsigned int height, float fov);
    /** returns the ray which shoots from the camera lens through the pixel given by the row and column */
    Ray GetRayThroughPixel(unsigned int row, unsigned int column);
    /** getters for the dimensions */
    unsigned int GetWidth() {return width_;}
    unsigned int GetHeight() {return height_;}
};

#endif /* camera_hpp */
