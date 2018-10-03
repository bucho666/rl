#ifndef GRID_H
#define GRID_H

#include <functional>
#include <vector>
#include "coord.h"
#include "size.h"
namespace rl {

template <typename T>
class Grid {
public:
  Grid(const Size &size, const T& initialValue) :
    map_(std::vector<std::vector<T>>(size.height(), std::vector<T>(size.width(), initialValue))) {}

  inline T& operator[](Coord coord) {
    return map_[coord.y()][coord.x()];
  }

  inline const T& operator[](Coord coord) const {
    return map_[coord.y()][coord.x()];
  }

  inline short width() const {
    return map_[0].size();
  }

  inline short height() const {
    return map_.size();
  }

  inline Size size() const {
    return Size(width(), height());
  }

  inline CoordIterator begin() const {
    return size().begin();
  }

  inline CoordIterator end() const {
    return size().end();
  }

  inline void fill(const T& v) {
    for (auto&& c : *this) (*this)[c] = v;
  }

private:
  std::vector<std::vector<char>> map_;
};

}

#endif
