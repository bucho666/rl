#ifndef SPACE_H
#define SPACE_H

#include <unordered_set>

class Coord;

namespace rl {

class Space {
public:
  auto begin() { return spaces_.begin(); }
  auto end() { return spaces_.end(); }
  inline void add(const Coord& c) { spaces_.insert(c); }
  inline bool at(const Coord& c) const { return spaces_.find(c) != spaces_.end(); }
  inline size_t size() const { return spaces_.size(); }
  inline void swap(Space& other) { spaces_.swap(other.spaces_); }

private:
  std::unordered_set<Coord> spaces_;
};

}

#endif
