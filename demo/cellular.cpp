#include <iostream> // TODO
#include <unordered_set>
#include "rl.h"

namespace rl {

class Celluar {
public:
  Celluar(Size size) : size_(size) {}
  auto begin() { return lives_.begin(); }
  auto end() { return lives_.end(); }
  auto initialize(int birthProbability) {
    for (auto&& c : size_) {
      if (size_.borderHas(c)) continue;
      if (Random::number(0, 99) < birthProbability) lives_.insert(c);
    }
    return (*this);
  }

private:
  Size size_;
  std::unordered_set<Coord> lives_;
};

int
celluar_demo() {
  using std::cout;
  using std::endl;
  Size size = Size(80, 20);
  Grid map = Grid(size, '#');
  Celluar celluar = Celluar(Size(80, 20)).initialize(45);
  for (auto&& c : celluar) map[c] = '.';
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

