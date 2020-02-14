//
//  random.hpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 13.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#ifndef random_hpp
#define random_hpp

#include <stdlib.h>

#include "datatypes/vector.hpp"

float rand_float();
/** return a sample in the hemisphere */
Vector3f rand_vec_in_hemisphere();
/** returns a random unit vector in the hemisphere defined by the given normal*/
Vector3f rand_vec_in_oriented_hemisphere(Vector3f surface_normal, Vector3f to_reflect);

#endif /* random_hpp */
