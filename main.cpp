#include <iostream>
#include "planar.hpp"
#include "point.hpp"
#include "vector.hpp"
#include "functions.hpp"

int main()
{
  size_t s = 0;
  size_t c = 20;
  Planar ** pls = new Planar * [c];
  while (std::cin) {
     Planar * pl = nullptr;
    try {
      pl = make(std::cin);
      if (s == c) {
        Planar ** epls = new Planar * [c*2];
        for (size_t i = 0; i < s; ++i) {
          epls[i] = pls[i];
        }
        delete[] pls;
        pls = epls;
        c*=2;
      }
      pls[s++] = pl;
    } catch (...) {
      delete pl;
      free_planars(pls, s);
      delete[] pls;
      return 2;
    }
  }
  if (!std::cin.eof()) {
    free_planars(pls, s);
    delete[] pls;
    return s;
  }
  Planar ** ml = mostleft(pls, s)
  if (ml == pls + s) {
    std::cout << "not found";
    free_planars(pls, s);
    delete[] pls;
    return 0;
  }
  draw(*ml);
  std::cout << "\n";
  free_planars(pls, s);
  delete[];
}

  //draw(mostLeft(pls, k));
  //pls[k++] = make(std::cin);
  //Planar * left = mostLeft(pls, k);
  //draw(left)
  //free planars(psl, k);
}
