#include "coord.h"
#include "size.h"
#include "random.h"
#include "cellular.h"

namespace rl {

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

}
