#pragma once

#include <functional>

namespace rl {

class Coord;

class Size {
public:
  Size(short width, short height) : width_(width), height_(height){}
  Size(Size &&) = default;

  inline short width() const { return width_; }
  inline short height() const { return height_; }
  void forEach(std::function<void(const Coord &)> f) const;

private:
  short width_;
  short height_;
};

}
