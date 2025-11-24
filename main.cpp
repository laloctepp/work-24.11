#include <iostream>

struct Planar {
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const = 0;
  virtual ~Planar() = default;
};

Planar * make (std::istream& is);
Planar * make(size_t pl)
void draw(Planar * pl);
void free_planars(Planar ** pls, size_t k);
Planar * mostLeft (Planar ** pls, size_t k);

int main()
{
  Planar * pls[10] = {};
  size_t k = 0;
  for (size_t i = 0; i < 10; ++i) {
    try {
      pls[k] = make(i%2)
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
