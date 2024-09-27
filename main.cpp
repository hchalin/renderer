
#include "header.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

// FIXME: there is a problem in the main fn
int main()
{
  hittable_list world;

  // shared_ptr<type>(color(x,y,y), gloss)
  auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
  auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
  auto material_left = make_shared<metal>(color(0.8, 0.8, 0.8), 0.1); // no gloss
  auto material_right = make_shared<metal>(color(0.8, 0.6, 0.2), 0.4);
  // auto material_top = make_shared<metal>(color(0.8, 0.8, 0.8), 1.0); // full gloss

  world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
  world.add(make_shared<sphere>(point3(0.0, 0.0, -1.2), 0.5, material_center));
  world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, material_left));
  world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, material_right));
  // world.add(make_shared<sphere>(point3(0.0, 1.0, -1.2), 0.3, material_top));

  camera cam;

  cam.aspect_ratio = 16.0 / 9.0;
  cam.image_width = 400; // Note: original is 400
  cam.samples_per_pixel = 100;
  cam.max_depth = 50;

  // Medium quality
  //cam.aspect_ratio = 16.0 / 9.0;
  //cam.image_width = 800; // Note: original is 400
  //cam.samples_per_pixel = 100;
  //cam.max_depth = 50;

  // High quality
  //  cam.aspect_ratio      = 16.0 / 9.0;
  //     cam.image_width       = 1200;
  //     cam.samples_per_pixel = 500;
  //     cam.max_depth         = 50;

  cam.render(world);
}
