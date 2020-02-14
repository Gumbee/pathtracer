//
//  material.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 14.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef material_hpp
#define material_hpp

#include "../datatypes/color.hpp"
#include "../datatypes/vector.hpp"

class Material {
protected:
    Color color_;

public:
    Material(Color color);
    
    virtual Vector3f Reflect(Vector3f surface_normal, Vector3f to_refelect);
    virtual float Weight(Vector3f surface_normal, Vector3f to_refelect);
    
    virtual Color GetEmissiveColor();
};


#endif /* material_hpp */
