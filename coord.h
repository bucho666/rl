#ifndef COORD_H
#define COORD_H

#include <vector>
#include <array>

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

  std::array<Coord, 4> cross() const;
  std::array<Coord, 8> around() const;

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
  static const Coord HERE,
              N, E, W, S,
              NE, SE, SW, NW,
              UP, DOWN, LEFT, RIGHT;
  static const std::vector<Coord> CROSS;
  static const std::vector<Coord> AROUND;
};

} // namespace rl

namespace std {
template<>
class hash<rl::Coord> {
public:
  size_t operator ()( const rl::Coord& coord ) const {
    return coord.x() | coord.y() << 16;
  }
};

}

#endif
