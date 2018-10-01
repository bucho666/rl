#ifndef CELLULAR_H
#define CELLULAR_H

#include <memory>
#include <unordered_set>

class Size;
class Coord;

namespace rl {

class Celluar {
public:
  Celluar(Size size) : size_(size) {}
  auto begin() { return lives_->begin(); }
  auto end() { return lives_->end(); }
  void generate(int birthProbability, int generation, int surviceLimit, int birthLimit);

private:
  void initialize(int birthProbability);
  void iterate(int surviceLimit, int birthLimit);
  int countLiveNeighbours(const Coord& c) const;
  inline bool livesHas(const Coord& c) const { return lives_->find(c) != lives_->end(); }
  Size size_;
  std::unique_ptr<std::unordered_set<Coord>> lives_;
};

}

#endif
