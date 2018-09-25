#include "grid.h"
#include "random.h"
#include "size.h"
#include "coord.h"
#include <functional>
#include <iostream>
#include <vector>

int main() {
  using rl::Coord;
  using rl::Grid;
  using rl::Size;
  Grid<char> map = Grid<char>(Size(80, 20), '.');
  // map.forEach([&](const Coord &c) { map.set(c, '.'); });
  map.fill('.');
  map.set(Coord(3, 4), '#');
  map.forEachLine([&](const std::vector<char>& line) {
    for (char c : line) {
      std::cout << c;
    }
    std::cout << std::endl;
  });
  return 0;
}
