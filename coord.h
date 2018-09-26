#pragma once

namespace rl {

class Coord {
public:
  Coord(short x, short y) : x_(x), y_(y) {}
  inline short x() const { return x_; };
  inline short y() const { return y_; };
  inline bool operator !=(const Coord& other) {
    return x_ != other.x_ || y_ != other.y_;
  }

private:
  short x_;
  short y_;
};

}
