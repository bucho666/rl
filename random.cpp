#include "random.h"

namespace rl {

std::mt19937 Random::source = std::mt19937(std::random_device{}());

int Random::number(const int min, const int max) {
  std::uniform_int_distribution<int> r(min, max);
  return r(source);
}

} // namespace rl
