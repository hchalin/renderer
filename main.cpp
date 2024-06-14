#include <iostream>
#include "vec3.h"
#include "color.h"

color ray_color(const ray & r){
  return color(0,0,0);
}

int main() {
  // Image
  auto aspect_ratio = 16.0 / 9.0;
  int image_width = 400;

  // Calculate the image height, and ensure that it's at least 1.
  int image_height = int(image_width / aspect_ratio);
  image_height = (image_height < 1) ? 1 : image_height;

  // Camera
  auto focal_length = 1.0;
  auto viewport_height = 2.0;
  auto viewport_width = viewport_height * (double(image_width)/image_height);
  auto camera_center = point3(0,0,0);

  // Calculate the vectors across the horizontal and down the vertical viewport edge's
  auto viewport_u = vec3(viewport_width, 0, 0);
  auto viewport_v = vec3(0, - viewport_height, 0);

  // Calculate the horizontal and vertical delta vectors from pixel to pixel
  auto pixel_delta_u = viewport_u / image_width;
  auto pixel_delta_v = viewport_v / image_height;

  // Calculate the location of the upper left pixel 
  auto viewport_upper_left = camera_center 
                            - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
  auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Render
  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
      std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
      for (int i = 0; i < image_width; i++) {
        auto pixel_color =  color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
        write_color(std::cout, pixel_color);
    }
      
  }
  std::clog << "\rDone.                 \n";
}




