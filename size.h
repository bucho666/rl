#pragma once

#include <functional>

namespace rl {

class Coord;

// サイズ
class Size {
public:
  Size(int width, int height) {
    width_ = width;
    height_ = height;
  }
  Size(Size &&) = default;

  inline int width() const { return width_; }
  inline int height() const { return height_; }
  void forEach(std::function<void(const Coord &)> f) const;

private:
  int width_;
  int height_;
};

}
