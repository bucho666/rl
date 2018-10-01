#include "size.h"
#include "coord.h"

namespace rl {

CoordIterator Size::begin() const {
  return CoordIterator(Coord(0, 0), width_);
}

CoordIterator Size::end() const {
  return CoordIterator(Coord(0, height_), width_);
}

bool Size::borderOn(const Coord& coord) const {
  short x = coord.x();
  short y = coord.y();
  return x == 0 || y == 0 || x == width_ - 1 || y == height_ - 1;
}

bool Size::outbound(const Coord& coord) const {
  short x = coord.x();
  short y = coord.y();
  return x < 0 || y < 0 || x >= width_ || y >= height_;
}

}
