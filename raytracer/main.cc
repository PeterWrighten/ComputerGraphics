#include "color.hpp"
#include "vec3.hpp"
#include "ray.hpp"

#include<iostream>
using namespace std;

double hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b*b - 4*a*c;
    if(discriminant < 0) {
        return -1.0;
    } else {
        return (-b - sqrt(discriminant) / (2.0 * a));
    }
}

color ray_color(const ray &r) { //simple camera
    auto t = hit_sphere(point3(0, 0, -1), 0.5, r);
    if(t > 0.0) {
        vec3 N = unit_vector(r.at(t) - vec3(0, 0, -1));
        return color(N.x() + 1, N.y() + 1, N.z() + 1) * 0.5;
    }
    vec3 unit_direction = unit_vector(r.direction());
    t = (unit_direction.y() + 1.0) * 0.5;
    return color(1.0, 1.0, 1.0) * (1 - t) + color(0.5, 0.7, 1.0) * t;
}

int main() {

    //Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int width = 400;
    const int height = static_cast<int>(width / aspect_ratio);

    //Camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);



    cout<< "P3\n" << width << ' ' << height << "\n255\n";

    for (int j = height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < width; ++i) {
            auto u = double(i)/(width - 1);
            auto v = double(j)/(height - 1);
            ray r(origin, lower_left_corner + horizontal * u + vertical * v - origin);
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
            // auto r = double(i) / (width-1);
            // auto g = double(j) / (height-1);
            // auto b = 0.25;
            // int ir = static_cast<int>(255.999 * r);
            // int ig = static_cast<int>(255.999 * g);
            // int ib = static_cast<int>(255.999 * b);

            // cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::cerr << "\nDone. \n";

}