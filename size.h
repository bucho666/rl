#pragma once

#include <functional>

namespace rl {

class Coord;
class CoordIterator;

class Size {
public:
  Size(short width, short height) : width_(width), height_(height){}
  inline bool operator==(const Size& other) const {
    return width_ == other.width_ && height_ == other.height_;
  }

  inline short width() const {
    return width_;
  }

  inline short height() const {
    return height_;
  }

  CoordIterator begin() const;
  CoordIterator end() const;
  bool borderOn(const Coord& coord) const;
  bool outbound(const Coord& coord) const;

private:
  short width_;
  short height_;
};

}
