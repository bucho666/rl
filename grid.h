#pragma once
#include <functional>
#include <vector>
#include "coord.h"
#include "size.h"
namespace rl {

template <typename T>
class Grid {
public:
  Grid(const Size &size, const T& initialValue) {
    using std::vector;
    using vectT = vector<T>;
    map_ = vector<vectT>(size.height(), vectT(size.width(), initialValue));
  }

  void set(const Coord &coord, const T& value) {
    map_[coord.y()][coord.x()] = value;
  }

  inline void fill(const T& v) {
    forEach([&](const Coord &c) { set(c, v); });
  }

  T& get(const Coord &coord) const {
    return map_[coord.y()][coord.x()];
  }

  void forEach(std::function<void(const Coord &)> f) const {
    for (size_t y = 0, height = map_.size(); y < height; y++) {
      for (size_t x = 0, width = map_[y].size(); x < width; x++) {
        f(Coord(x, y));
      }
    }
  }

  inline void forEachLine(std::function<void(const std::vector<T> &)> f) {
    for (const auto &line : map_) {
      f(line);
    }
  }

private:
  std::vector<std::vector<char>> map_;
};

}
