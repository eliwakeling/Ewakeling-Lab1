// Code implemented from here : https://raytracing.github.io/books/RayTracingInOneWeekend.html

#pragma once
#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>


// Standards being used.

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constant doubles, infinites and irrational numbers.

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
	return degrees * pi / 180.0;
}

// Common Headers

#include "ray.h"
#include "vec3.h"

#endif