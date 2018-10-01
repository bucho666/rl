#include <iostream> // TODO
//#include <unordered_set>
//#include <memory>
#include "rl.h"

/*

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

void
Celluar::initialize(int birthProbability) {
  lives_ = std::make_unique<std::unordered_set<Coord>>();
  for (auto&& c : size_) {
    if (size_.borderOn(c) == false && Random::number(0, 99) >= birthProbability) {
      lives_->insert(c);
    }
  }
}

void
Celluar::iterate(int surviceLimit, int birthLimit) {
  auto nextGeneration = std::make_unique<std::unordered_set<Coord>>();
  for (auto&& c : size_) {
      if (size_.borderOn(c)) continue;
      if (livesHas(c)) {
        if (countLiveNeighbours(c) < birthLimit) nextGeneration->insert(c);
      } else {
        if (countLiveNeighbours(c) < surviceLimit) nextGeneration->insert(c);
      }
  }
  lives_.swap(nextGeneration);
}

int
Celluar::countLiveNeighbours(const Coord& center) const {
  int count = 0;
  for (auto &&c : Direction::AROUND) {
    auto n = c + center;
    if (size_.outbound(n)) continue;
    if (livesHas(n) == false) count++;
  }
  return count;
}

void
Celluar::generate(int birthProbability, int generation, int surviceLimit, int birthLimit) {
  initialize(birthProbability);
  while(generation--) {
    iterate(surviceLimit, birthLimit);
  }
}
*/

namespace rl {

int
celluar_demo() {
  using std::cout;
  using std::endl;
  Size size = Size(60, 30);
  Grid map = Grid(size, '#');
  Celluar celluar = Celluar(size);
  celluar.generate(45, 5, 4, 5);
  for (auto&& c : celluar) map[c] = '.';
  for (auto&& c : map) {
    cout << map[c];
    if (c.x() == size.width() - 1) {
      cout << endl;
    }
  }
  return 0;
}

}

int
main() {
  return rl::celluar_demo();
}
