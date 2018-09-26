#include "grid.h"
#include "random.h"
#include "size.h"
#include "coord.h"
#include <functional>
#include <iostream>
#include <vector>
#include <memory>
#include <utility>

int main() {
  using rl::Coord;
  using rl::Grid;
  using rl::Size;
  std::unique_ptr<Grid<char>> map = std::make_unique<Grid<char>>(Size(80, 20), '*');
  map->fill('.');
  Coord c = Coord(12, 4);
  (*map)[Coord(3, 4)] = '#';
  (*map)[std::move(c)] = '*';
  for (auto&& c : *map) {
    if (c.y() != 0 && c.x() == 0) {
      std::cout << std::endl;
    }
    std::cout << (*map)[c];
  }
  return 0;
}
