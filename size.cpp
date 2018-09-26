#include "size.h"
#include "coord.h"

namespace rl {

CoordIterator Size::begin() const {
  return CoordIterator(Coord(0, 0), width_);
}

CoordIterator Size::end() const {
  return CoordIterator(Coord(0, height_), width_);
}

}
