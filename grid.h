#pragma once
#include <functional>
#include <vector>
#include "coord.h"
#include "size.h"
namespace rl {

class GridIterator {
public:
  GridIterator(const Coord& c, short width) : coord_(c), width_(width) {};
  inline Coord& operator *() { return coord_; }
  inline void operator ++() {
    coord_ = coord_.x() == width_ - 1 ? Coord(0, coord_.y() + 1) : Coord(coord_.x() + 1, coord_.y());
  }
  inline bool operator !=(const GridIterator& i) { return coord_ != i.coord_; }

private:
  Coord coord_;
  short width_;
};

template <typename T>
class Grid {
public:
  Grid(const Size &size, const T& initialValue) :
    map_(std::vector<std::vector<T>>(size.height(), std::vector<T>(size.width(), initialValue))) {}
  inline T& operator[](Coord coord) { return map_[coord.y()][coord.x()]; }
  inline const T& operator[](Coord coord) const { return map_[coord.y()][coord.x()]; }
  inline short width() const { return map_[0].size(); }
  inline short height() const { return map_.size(); }
  inline Size size() const { return Size(width(), height()); }
  inline GridIterator begin() const {
    return GridIterator(Coord(0, 0), width());
  }

  inline GridIterator end() const {
    return GridIterator(Coord(0, map_.size()), width());
  }

  inline void fill(const T& v) {
    for (auto&& c : *this) (*this)[c] = v;
  }

private:
  std::vector<std::vector<char>> map_;
};

}
