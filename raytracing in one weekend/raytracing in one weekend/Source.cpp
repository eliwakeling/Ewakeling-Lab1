// Code Modified from here: https://raytracing.github.io/books/RayTracingInOneWeekend.html

#include "rtweekend.h"
#include "color.h"
#include "hittable_list.h"
#include "sphere.h"

using namespace std;

//Determine if the sphere object is being hit by a ray.
double hit_sphere(const point3& center, double radius, const ray& r) {
	vec3 oc = r.origin() - center;
	auto a = r.direction().length_squared();
	auto half_b = dot(oc, r.direction());
	auto c = oc.length_squared() - radius * radius;
	auto discriminant = half_b * half_b - a * c;
	if (discriminant < 0) {
		return -1.0;
	}
	else {
		return (-half_b - sqrt(discriminant)) / a;
	}
}

color ray_color(const ray& r, const hittable& world) {
	hit_record rec;
	if (world.hit(r, 0, infinity, rec)) {
		return 0.5 * (rec.normal + color(1, 1, 1));
	}
	vec3 unit_direction = unit_vector(r.direction());
	auto t = 0.5*(unit_direction.y() + 1.0);
	return (1.0 - t)*color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main() {

	double size, posX, posY;
	//Set size of sphere
	cout << "Please state a size for your sphere, from 0.1 to 1." << endl;

	cin >> size;

	while (size < 0.1 || size > 1) {
		cout << "Invalid size." << endl;
		cin >> size;
	}
	// Set Horizontal position.
	cout << "What position do you want your sphere to be on the X axis from -1.0 to 1.0? 0 is center." << endl;
	cin >> posX;
	while (posX < -1 || posX > 1) {
		cout << "Invalid size." << endl;
		cin >> posX;
	}
	// Set Vertical Position.
	// Set Vertical Position.
	cout << "What position do you want your sphere to be on the Y axis? 0 is center." << endl;
	cin >> posY;
	while (posY < -1 || posY > 1) {
		cout << "Invalid size." << endl;
		cin >> posY;
	}

	// Image
	const auto aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);

	// Creates objects within the World
	hittable_list world;
	world.add(make_shared<sphere>(point3(posX, posY, -1), size));
	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

	// Sets where the Camera is in the world.
	auto viewport_height = 2.0;
	auto viewport_width = aspect_ratio * viewport_height;
	auto focal_length = 1.0;

	auto origin = point3(0, 0, 0);
	auto horizontal = vec3(viewport_width, 0, 0);
	auto vertical = vec3(0, viewport_height, 0);
	auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);

	ofstream outfile;

	// Renders the Object in the form of a PPM file.
	
	//Create and open the Output file.
	outfile.open("outfile.ppm");

	//Create image width and height, and record it into the outfile.
	cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	outfile << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	//Render X axis of pixels.
	for (int j = image_height - 1; j >= 0; --j) {
		//shows how many lines in the image have left to be rendered.
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		//Render Y axis of pixels.
		for (int i = 0; i < image_width; ++i) {
			auto u = double(i) / (image_width - 1);
			auto v = double(j) / (image_height - 1);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
			color pixel_color = ray_color(r, world);
			write_color(std::cout, pixel_color);
			write_color(outfile, pixel_color);
		}
	}
	std::cerr << "\nDone.\n";
	outfile.close();
}