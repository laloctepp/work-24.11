#include "planar.hpp"
#include "point.hpp"
#include "vector.hpp"

Vector::Vector(Point a, Point b):
  Planar(),
  a(a),
  b(b)
{}

int Vector::x() const {
  return b.x() -  a.x();
}

int Vector::y() const {
  return b.y() - a.y();
}

int Vector::abs_sqr() const {
  return x() * x() + y() * y();
}

