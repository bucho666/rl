#include <iostream>
#include "rl.h"

namespace rl {

int
celluar_demo() {
  using std::cout;
  using std::endl;
  Size size = Size(60, 30);
  Grid map = Grid(size, '#');
  Celluar celluar = Celluar(size);
  celluar.generate(45, 5, 4, 5);
  for (auto&& c : celluar.mostWideSpace()) map[c] = '.';
  for (auto&& c : map) {
    cout << map[c];
    if (c.x() == size.width() - 1) {
      cout << endl;
    }
  }
  return 0;
}

}

int
main() {
  return rl::celluar_demo();
}

