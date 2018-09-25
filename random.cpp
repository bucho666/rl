#include "random.h"
#include <random>
namespace rl {

int Random::number(const int min, const int max) {
  static std::mt19937 source = std::mt19937(std::random_device{}());
  std::uniform_int_distribution<int> r(min, max);
  return r(source);
}

} // namespace rl
