#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  bool has_hit = false;
  t = INFINITY;

  double temp_t;
  Eigen::Vector3d temp_n;

  for (int i = 0; i < objects.size(); i++){
    auto object = objects[i];
    if (object->intersect(ray, min_t, temp_t, temp_n)){
      has_hit = true;
      if (temp_t < t){
        t = temp_t;
        n = n;
        hit_id = i;
      }
    }
  }
  return has_hit;
  ////////////////////////////////////////////////////////////////////////////
}

