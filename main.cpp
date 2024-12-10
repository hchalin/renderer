
#include "header.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

int main()
{
  hittable_list world;
  /*
  // shared_ptr<type>(color(x,y,y), gloss)
  auto material_ground = make_shared<lambertian>(color(0.2, 0.8, 0.0));
  //auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
  auto material_center = make_shared<lambertian>(color(0.9, 0.2, 0.1));
  auto material_left = make_shared<dielectric>(1.5);
  auto material_bubble = make_shared<dielectric>(1.0 / 1.5);
  auto material_right = make_shared<metal>(color(0.8, 0.6, 0.2), 0.4);

  world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
  world.add(make_shared<sphere>(point3(0.0, 0.0, -1.2), 0.5, material_center));
  world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, material_left));
  world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.4, material_bubble));
  world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, material_right));
  //world.add(make_shared<sphere>(point3(0.0, 1.0, -1.2), 0.3, material_top));
  */
  // Testing
  auto R = std::cos(pi/4);      // R is used to place the spheres evenly in the center

  auto material_left  = make_shared<lambertian>(color(0,0,1));
  auto material_right = make_shared<lambertian>(color(1,0,0));

  world.add(make_shared<sphere>(point3(-R, 0, -1), R, material_left));
  world.add(make_shared<sphere>(point3( R, 0, -1), R, material_right));

  camera cam;         // Low quality camera
  //camera camH;      // High quality camera
  cam.vFov = 90;      // Not needed, here for readablility


  cam.aspect_ratio = 16.0 / 9.0;
  cam.image_width = 400; // Note: original is 400
  cam.samples_per_pixel = 100;
  cam.max_depth = 50;

  // Medium quality
  // cam.aspect_ratio = 16.0 / 9.0;
  // cam.image_width = 800; // Note: original is 400
  // cam.samples_per_pixel = 100;
  // cam.max_depth = 50;

  // High quality
  //camH.aspect_ratio = 16.0 / 9.0;
  //camH.image_width = 1200;
  //camH.samples_per_pixel = 500;
  //camH.max_depth = 50;

  cam.render(world);
}
