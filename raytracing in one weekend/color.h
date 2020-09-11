// Code implemented from here : https://raytracing.github.io/books/RayTracingInOneWeekend.html
#pragma once

#include "vec3.h";

#ifndef COLOR_H
#define COLOR_H

void write_color(std::ostream &out, color pixel_color) {
	// Write the translated [0,255] value of each color component, Red, Green, and Blue.
	out << static_cast<int>(255.999 * pixel_color.x()) << ' '
		<< static_cast<int>(255.999 * pixel_color.y()) << ' '
		<< static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif