#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include "interval.h"
#include <iostream>
#include <ostream>

using color = vec3;

inline void write_color(std::ostream& out, const color& pixel_color) {
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	static const interval intensity(0.000, 0.999);

	int rbyte = int(255.99 * intensity.clamp(r));
	int gbyte = int(255.99 * intensity.clamp(g));
	int bbyte = int(255.99 * intensity.clamp(b));
	
	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif