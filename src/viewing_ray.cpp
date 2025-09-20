#include "viewing_ray.h"
#include <iostream>

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width, // number of pixels wide
  const int height, // number of pixels tall
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  double pixel_width = camera.width / static_cast<double>(width);
  double pixel_height = camera.height / static_cast<double>(height);

  Eigen::Vector3d image_top_left_corner = camera.e - camera.w*camera.d + 
                            (camera.height / 2.0)*camera.v - (camera.width / 2.0)*camera.u;

  // std::cout << camera.e << "\n" << camera.w << "\n" << camera.d << "\n" << camera.u << "\n" << camera.v << "\n\n";
  // std::cout << camera.width << ' ' << camera.height << " " << width << " " << height << "\n";
  // std::cout << image_top_left_corner << "\n\n\n";

  Eigen::Vector3d pixel_position = image_top_left_corner - 
        (i*pixel_height + pixel_height/2.0)*camera.v + (j*pixel_width + pixel_width/2.0)*camera.u;
  ray.origin = camera.e;
  ray.direction = pixel_position - camera.e;
  ////////////////////////////////////////////////////////////////////////////
}

