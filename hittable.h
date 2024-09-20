#ifndef HITTABLE_H
#define HITTABLE_H

// Tell the compiler that class will be defined later
class material;

// This class will act as a box to hold a bunch of arguments
class hit_record
{
public:
  point3 p;
  vec3 normal;
  shared_ptr<material> mat; // Material pointer
  double t; // time
  bool front_face;

  void set_face_normal(const ray &r, const vec3 &outward_normal)
  {
    // Set the hit record normal vector
    front_face = dot(r.direction(), outward_normal) < 0;
    normal = front_face ? outward_normal : -outward_normal;
  }
};

class hittable
{
public:
  virtual ~hittable() = default;

  virtual bool hit(const ray &r, interval ray_t, hit_record &rec) const = 0; // pure virtual fn - "const = 0"
};

#endif
