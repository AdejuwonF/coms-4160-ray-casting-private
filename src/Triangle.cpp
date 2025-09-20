#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Dense>
bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d corner_a, corner_b, corner_c;
  corner_a = std::get<0>(corners);
  corner_b = std::get<1>(corners);
  corner_c = std::get<2>(corners);

  // Matrix that serves as a base for many of the others
  Eigen::Matrix3d component_matrix;
  component_matrix.col(0) = corner_a;
  component_matrix.col(1) = corner_a;
  component_matrix.col(2) = ray.direction;

  Eigen::Matrix3d A = component_matrix;
  A.col(0) -= corner_b;
  A.col(1) -= corner_c;
  double A_determinant = A.determinant();

  // Matrices for the numerator of fractions used to compute beta, gamma and t
  Eigen::Matrix3d t_numerator; 
  t_numerator.col(0) = corner_a - corner_b;
  t_numerator.col(1) = corner_a - corner_c;
  t_numerator.col(2) = corner_a - ray.origin;
  t = t_numerator.determinant() / A_determinant;
  if (t < min_t){
    return false;
  }

  Eigen::Matrix3d gamma_numerator = component_matrix;
  gamma_numerator.col(0) -= corner_b;
  gamma_numerator.col(1) -= ray.origin;
  double gamma = gamma_numerator.determinant() / A_determinant;
  if (gamma < 0 || gamma > 1){
    return false;
  }
  Eigen::Matrix3d beta_numerator = component_matrix;
  beta_numerator.col(0) -= ray.origin;
  beta_numerator.col(1) -= corner_c;
  double beta = beta_numerator.determinant() / A_determinant;
  if (beta < 0 || beta > 1 - gamma){
    return false;
  }
  n = (corner_b - corner_a).cross(corner_c - corner_a).normalized();

  return true;
  ////////////////////////////////////////////////////////////////////////////
}


