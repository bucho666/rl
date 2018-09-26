#pragma once

#include <functional>

namespace rl {

class Coord;
class CoordIterator;

class Size {
public:
  Size(short width, short height) : width_(width), height_(height){}
  Size(Size &&) = default;

  inline short width() const {
    return width_;
  }

  inline short height() const {
    return height_;
  }

  CoordIterator begin() const;
  CoordIterator end() const;

private:
  short width_;
  short height_;
};

}
