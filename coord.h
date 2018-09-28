#pragma once

#include <vector>

namespace rl {

class Coord {
public:
  Coord(short x, short y) : x_(x), y_(y) {}

  inline short x() const {
    return x_;
  };

  inline short y() const {
    return y_;
  };

  inline bool operator==(const Coord& other) const {
    return x_ == other.x_ && y_ == other.y_;
  }

  inline bool operator!=(const Coord& other) const {
    return x_ != other.x_ || y_ != other.y_;
  }

  inline bool operator<(const Coord &other) const {
    return y_ < other.y_ ? true : x_ < other.x_;
  }

  inline Coord operator+(const Coord& other) const {
    return Coord(x_ + other.x_, y_ + other.y_);
  }

  inline Coord operator-(const Coord& other) const {
    return Coord(x_ - other.x_, y_ - other.y_);
  }

  inline Coord& operator+=(const Coord& other) {
    x_ += other.x_;
    y_ += other.y_;
    return (*this);
  }

  inline Coord& operator-=(const Coord& other) {
    x_ -= other.x_;
    y_ -= other.y_;
    return (*this);
  }

private:
  short x_;
  short y_;
};

class CoordIterator {
public:
  CoordIterator(const Coord& c, short width, short left=0) : coord_(c), width_(width), left_(left) {};

  inline Coord& operator*() {
    return coord_;
  }

  inline void operator++() {
    static const Coord right = Coord(1, 0);
    coord_ = coord_.x() == width_ - 1 ? Coord(left_, coord_.y() + 1) : coord_ + right;
  }

  inline bool operator!=(const CoordIterator& i) const {
    return coord_ != i.coord_;
  }

private:
  Coord coord_;
  short width_;
  short left_;
};

class Direction {
public:
  const Coord HERE = Coord(0, 0),
              N  = Coord( 0, -1),
              E  = Coord( 1,  0),
              W  = Coord(-1,  0),
              S  = Coord( 0,  1),
              NE = Coord( 1, -1),
              SE = Coord( 1,  1),
              SW = Coord(-1,  1),
              NW = Coord(-1, -1),
              UP = N,
              DOWN = S,
              LEFT = W,
              RIGHT = E;
  const std::vector<Coord> CROSS = {N, E, W, S};
  const std::vector<Coord> AROUND = {N, NE, E, SE, S, SW, W, NW};
};

}

namespace std {
template<>
class hash<rl::Coord> {
public:
  size_t operator ()( const rl::Coord& coord ) const {
    return coord.x() | coord.y() << 16;
  }
};

}
