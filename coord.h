#pragma once

namespace rl {

class Coord {
public:
  Coord(int x, int y) {
    x_ = x;
    y_ = y;
  }
  Coord(Coord &&) = default;

  inline int x() const { return x_; };
  inline int y() const { return y_; };

private:
  int x_;
  int y_;
};

}
