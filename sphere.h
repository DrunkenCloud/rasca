#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"
#include <cmath>
#include <memory>

class sphere : public hittable {
private:
	point3 centre;
	double radius;
	shared_ptr<material> mat;
public:
	sphere(const point3& center, double radius, shared_ptr<material> mat) : centre(center), radius(std::fmax(0,radius)), mat(mat) {}

	bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
		vec3 oc = centre - r.origin();
		auto a = r.direction().length_squared();
		auto h = dot(r.direction(), oc);
		auto c = oc.length_squared() - radius*radius;

		auto discriminant = h*h - a*c;
		if (discriminant < 0) {
			return false;
		}

		auto sqrtd = std::sqrt(discriminant);

		auto root = (h - sqrtd)/a;
		if (!ray_t.surrounds(root)) {
            root = (h + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

		rec.t = root;
		rec.p = r.at(rec.t);
		rec.normal = (rec.p - centre)/radius;
		vec3 outward_normal = (rec.p - centre) / radius;
        rec.set_face_normal(r, outward_normal);
        rec.mat = mat;
		return true;
	}
};

#endif