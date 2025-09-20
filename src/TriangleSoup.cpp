#include "TriangleSoup.h"
#include "Ray.h"
// Hint
#include "first_hit.h"

bool TriangleSoup::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  t = INFINITY;
  double temp_t = INFINITY;
  Eigen::Vector3d temp_n;
  bool has_hit = false;

  for (auto triangle : triangles){
    if(triangle->intersect(ray, min_t, temp_t, temp_n)){
      has_hit = true;
      if (temp_t < t){
        t = temp_t;
        n = temp_n;
      }
    }
  }
  return has_hit;
  ////////////////////////////////////////////////////////////////////////////
}



