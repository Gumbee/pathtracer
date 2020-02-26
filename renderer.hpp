//
//  renderer.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 12.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef renderer_hpp
#define renderer_hpp

class Scene;
class Camera;
class ImageBuffer;

class Renderer {
private:
    unsigned int num_samples_;
    
public:
    Renderer(unsigned int num_samples);
    /** render the scene with the given camera */
    ImageBuffer* Render(Scene* scene, Camera* camera);
};

#endif /* renderer_hpp */
