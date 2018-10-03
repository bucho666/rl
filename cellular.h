#ifndef CELLULAR_H
#define CELLULAR_H

#include "space.h"
#include <memory>
#include <unordered_set>

class Size;
class Coord;

namespace rl {

class Celluar {
public:
  Celluar(Size size) : size_(size) {}
  std::unordered_set<Coord>::iterator begin();
  std::unordered_set<Coord>::iterator end();
  void generate(int birthProbability, int generation, int surviceLimit, int birthLimit);
  Space mostWideSpace() const;

private:
  void initialize(int birthProbability);
  void iterate(int surviceLimit, int birthLimit);
  int countLiveNeighbours(const Coord& c) const;
  bool at(const Coord& c) const;
  void fill(Space& space, Space& filled, const Coord coord) const;
  Size size_;
  std::unique_ptr<Space> lives_;
};

}

#endif
