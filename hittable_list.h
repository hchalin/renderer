#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

// file include
#include "hittable.h"

// Preproccesor
#include <vector>
#include <memory>

// namespaces
using std::make_shared;
using std::shared_ptr; // smart pointer

class hittable_list : public hittable {

  public:
    std::vector<shared_ptr<hittable>> objects;

    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    void clear(){objects.clear();}

    void add(shared_ptr<hittable> object){
      objects.push_back(object);
    }

};




#endif HITTABLE_LIST_H
