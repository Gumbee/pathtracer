//
//  random.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 13.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "random.hpp"

float rand_float(){
    return rand() / (RAND_MAX + 1.0);
}
