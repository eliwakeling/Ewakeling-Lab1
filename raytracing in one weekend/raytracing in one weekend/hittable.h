// Code implemented from here : https://raytracing.github.io/books/RayTracingInOneWeekend.html

#pragma once
#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

//A generic object the ray can intersect with.
struct hit_record {
	point3 p;
	vec3 normal;
	double t;
	bool front_face;

	//sets the normal of an object.
	inline void set_face_normal(const ray& r, const vec3& outward_normal) {
		front_face = dot(r.direction(), outward_normal) < 0;
		normal = front_face ? outward_normal : -outward_normal;
	}
};

class hittable {
public:
	//a class sets where a ray could hit a sphere within the rendering process.
	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};


#endif