#include <iostream>

struct Planar {
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const = 0;
  virtual ~Planar() = default;
};

Planar * make (std::istream& is);
Planar * mostLeft (Planar ** pls, size_t k);

int main()
{
  Planar * pls[10] = {};
  size_t k = 0;
  //pls[k++] = make(std::cin);
  //Planar * left = mostLeft(pls, k);
  //draw(left)
  //free planars(psl, k);
}
