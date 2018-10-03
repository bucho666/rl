#include "coord.h"
#include "size.h"
#include "random.h"
#include "cellular.h"

namespace rl {

std::unordered_set<Coord>::iterator
Celluar::begin() {
  return lives_->begin();
}

std::unordered_set<Coord>::iterator
Celluar::end() {
  return lives_->end();
}

bool
Celluar::at(const Coord& c) const {
  return lives_->at(c);
}

void
Celluar::initialize(int birthProbability) {
  lives_ = std::make_unique<Space>();
  for (auto&& c : size_) {
    if (size_.borderOn(c) == false && Random::number(0, 99) >= birthProbability) {
      lives_->add(c);
    }
  }
}

void
Celluar::iterate(int surviceLimit, int birthLimit) {
  auto nextGeneration = std::make_unique<Space>();
  for (auto&& c : size_) {
      if (size_.borderOn(c)) continue;
      if (at(c)) {
        if (countLiveNeighbours(c) < birthLimit) nextGeneration->add(c);
      } else {
        if (countLiveNeighbours(c) < surviceLimit) nextGeneration->add(c);
      }
  }
  lives_.swap(nextGeneration);
}

int
Celluar::countLiveNeighbours(const Coord& center) const {
  int count = 0;
  for (auto &&c : center.around()) {
    if (size_.outbound(c)) continue;
    if (at(c) == false) count++;
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

Space
Celluar::mostWideSpace() const {
  Space mostWideSpace;
  Space filled;
  for (auto&& c : (*lives_)) {
    Space s;
    fill(s, filled, c);
    if (mostWideSpace.size() < s.size()) mostWideSpace.swap(s);
  }
  return mostWideSpace;
}

void
Celluar::fill(Space& space, Space& filled, const Coord coord) const {
  if (at(coord) == false || filled.at(coord)) return;
  filled.add(coord);
  space.add(coord);
  for (auto&& d : coord.around()) fill(space, filled, d);
}

}
