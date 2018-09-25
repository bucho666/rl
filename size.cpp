#include "size.h"
#include "coord.h"

namespace rl {

void Size::forEach(std::function<void(const Coord &)> f) const {
  for (int y = 0; y < height_; y++) {
    for (int x = 0; x < width_; x++) {
      f(Coord(x, y));
    }
  }
}

}
