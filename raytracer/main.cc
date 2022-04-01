#include "color.h"
#include "vec3.h"

#include<iostream>
using namespace std;

int main() {
    const int height = 256;
    const int width = 256;

    cout<< "P3\n" << width << ' ' << height << "\n255\n";

    for (int j = height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < width; ++i) {
            color pixel_color(double(i)/(width - 1), double(j)/(height - 1), 0.25);
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