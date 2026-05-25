#include "color.h"
#include "vec3.h"

#include <iostream>
#include <cstdint>
#include <fstream>

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    std::ofstream output("image.ppm", std::ios::binary);
    output << "P6\n" << image_width << " " << image_height << "\n255\n";

    for (int i = 0; i < image_height; i++) {
        std::clog << "\rScanlines remaining: " << (image_height - i) << ' ' << std::flush;
        for (int j = 0; j < image_width; j++) {
            auto pixel_color = color(double(j) / (image_width - 1), double(i) / (image_height - 1), 0.0);

            std::uint8_t r = static_cast<std::uint8_t>(255.999 * pixel_color.x());
            std::uint8_t g = static_cast<std::uint8_t>(255.999 * pixel_color.y());
            std::uint8_t b = static_cast<std::uint8_t>(255.999 * pixel_color.z());

            output.write(reinterpret_cast<const char*>(&r), 1);
            output.write(reinterpret_cast<const char*>(&g), 1);
            output.write(reinterpret_cast<const char*>(&b), 1);
        }

        std::clog << "\rScanlines remaining: " << (image_height - i - 1) << ' ' << std::flush;
    }

    std::clog << "\rDone.                 \n";

    return 0;
}