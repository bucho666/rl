#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <algorithm>

namespace rl {

class Random {
public:
  static int number(const int min, const int max);

  template<class T>
  inline static void shuffle(T& list) {
    std::shuffle(list.begin(), list.end(), source);
  }

private:
  static std::mt19937 source;
};

} // namespace rl

#endif
