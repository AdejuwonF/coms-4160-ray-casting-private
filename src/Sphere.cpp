#include "Sphere.h"
#include "Ray.h"
#include <cmath>
#include <iostream>
bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  // TODO(Maybe): Could optimize to avoid recomputing values.
  Eigen::Vector3d center_to_ray = ray.origin - center;
  double discriminant = (ray.direction.dot(center_to_ray) * ray.direction.dot(center_to_ray)) - 
  ray.direction.dot(ray.direction) * (center_to_ray.dot(center_to_ray) - radius*radius);
  if (discriminant >= 0) {
    double discriminnant_root = sqrt(discriminant);
    // Use min
    double t1 = (-ray.direction.dot(center_to_ray) + discriminnant_root) / ray.direction.dot(ray.direction);
    double t2 = (-ray.direction.dot(center_to_ray) - discriminnant_root) / ray.direction.dot(ray.direction);
    t1 = t1 >= min_t ? t1 : INFINITY;
    t2 = t2 >= min_t ? t2 : INFINITY;
    t = std::min(t1, t2);
    if (t == INFINITY){
      return false;
    }
    Eigen::Vector3d intersect = ray.origin + ray.direction*t;
    n = (intersect - center) / radius;
    return true;
  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}

