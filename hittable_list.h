#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

// file include
#include "hittable.h"
#include "rtweekend.h"
// Preproccesor
#include <vector>

class hittable_list : public hittable {

  public:

    // both 'objects' and 'object' are smart pointers
    std::vector<shared_ptr<hittable>> objects;

    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    void clear(){objects.clear();}

    // add the hittable to the hittable_list
    void add(shared_ptr<hittable> object){
      objects.push_back(object);
    }

    // Check for hit
    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec)
    const override {
      hit_record temp_rec;
      bool hit_anything = false; // hit state
      auto closest_so_far = ray_tmax;

     for (const auto& object : objects){
        if (object->hit(r, ray_tmin, ray_tmax, rec)){
          hit_anything = true;
          closest_so_far = temp_rec.t;
          rec = temp_rec;
        }
     }
    }

};




#endif HITTABLE_LIST_H
