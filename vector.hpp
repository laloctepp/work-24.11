#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "planar.hpp"
#include "point.hpp"

struct Vector:Planar {
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;
  Vector(Point a, Point b);
  virtual ~Vector() = default;
  private:
    Point a;
    Point b;
};

#endif
