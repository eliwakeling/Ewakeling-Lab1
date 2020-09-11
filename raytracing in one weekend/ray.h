// Code implemented from here : https://raytracing.github.io/books/RayTracingInOneWeekend.html

#pragma once
#ifndef RAY_H
#define RAY_H

#include "vec3.h"

//Create a Ray Class, I see it as a "Ray of Light" that bounces off of objects to make it visible to the "Camera's Eye".
class ray {
public:
	ray() {}
	ray(const point3& origin, const vec3& direction)
		: orig(origin), dir(direction)
	{}

	point3 origin() const { return orig; }
	vec3 direction() const { return dir; }

	point3 at(double t) const {
		return orig + t * dir;
	}

public:
	point3 orig;
	vec3 dir;
};

#endif
