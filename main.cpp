#include <iostream>

struct Planar {
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const = 0;
  virtual ~Planar() = default;
};

Planar * make (std::istream& is);
Planar * make(size_t id);
void draw(Planar * pl);
void free_planars(Planar ** pls, size_t k);
Planar * mostLeft (Planar ** pls, size_t k);

struct Point:Planar {
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;
  Point(int xx, int yy);
  virtual ~Point() = default;
  private:
    int data[2];
};

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

int main()
{
  Planar * pls[10] = {};
  size_t k = 0;
  for (size_t i = 0; i < 10; ++i) {
    try {
      pls[k] = make(i%2);
    }
    catch (...) {
    free_planars(pls, k);
    return 2;
    }
    k++;
  }
  draw(mostLeft(pls, k));
  //pls[k++] = make(std::cin);
  //Planar * left = mostLeft(pls, k);
  //draw(left)
  //free planars(psl, k);
}


Planar * make(size_t id) {
  Planar * r = nullptr;
  switch (id) {
    case 0:
      r = new Point(0,0);
      break;
    default:
      throw std::logic_error("bad id");
  }
  return r;
}

void free_planars(Planar ** pls, size_t k) {
  for (size_t i = 0; i < k; ++i) {
    delete pls[i];
  }
}

void draw(Planar * pl) {
  std::cout << pl->x();
  std::cout << " ";
  std::cout << pl->y() << "\n";
}

Point::Point(int xx, int yy):
  Planar(),
  data{xx, yy}
{}

int Point::x() const {
  return data[0];
}

int Point::y() const {
  return data[1];
}

int Point::abs_sqr() const {
  return x() * x() + y() * y();
}

int Vector::x() const {
  return b.x() -  a.x();
}

int Vector::y() const {
  return b.y() - a.y();
}

int Vector::abs_sqr() const {
  return x() * x() + y() * y();
}
