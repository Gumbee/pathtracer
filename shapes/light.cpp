//
//  light.cpp
//  pathtracer
//
//  Created by Mugeeb Hassan on 14.02.20.
//  Copyright © 2020 Gumbee. All rights reserved.
//

#include "light.hpp"

Light::Light(Vector3f position, float radius) : Light(position, radius, 10.0f) {
}

Light::Light(Vector3f position, float radius, float intensity) : Light(position, radius, intensity, FlatColors::Yellow) {
}

Light::Light(Vector3f position, float radius, float intensity, Color color) : Sphere(position, radius, new EmissiveMaterial(color, intensity)){
}
