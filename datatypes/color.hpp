//
//  color.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 11.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef color_hpp
#define color_hpp

#include "vector.hpp"

typedef Vector3f Color;

namespace Colors {
    const static Color White = Color(255,255,255);
    const static Color Black = Color(0,0,0);
    const static Color Red = Color(255,0,0);
    const static Color Green = Color(0,255,0);
    const static Color Blue = Color(0,0,255);
    const static Color Yellow = Color(255,255,0);
}

namespace FlatColors {
    const static Color Red = Color(229, 80, 57);
    const static Color Green = Color(184, 233, 148);
    const static Color Blue = Color(106, 137, 204);
    const static Color Yellow = Color(250, 211, 144);
}

#endif /* color_hpp */
