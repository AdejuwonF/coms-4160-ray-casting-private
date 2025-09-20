#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  double denom = ray.direction.dot(normal);
  if (denom == 0) { // orthagonal
    return false;
  }
  t = (point - ray.origin).dot(normal) / denom;
  n = normal;
  return t >= min_t;
  ////////////////////////////////////////////////////////////////////////////
}

