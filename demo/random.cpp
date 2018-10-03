#include <iostream>
#include <vector>
#include "random.h"

namespace rl {

class RandomDemo {
public:
  void run() {
    randomNumberDemo();
    shuffleDemo();
  }

private:
  void shuffleDemo() {
    std::cout << "<shuffle 1 to 6>" << std::endl;
    std::vector<int> list = {1, 2, 3, 4, 5, 6};
    Random::shuffle(list);
    for (auto&& n : list) {
      std::cout << n << " ";
    }
    std::cout << std::endl;
  }

  void randomNumberDemo() {
    std::cout << "<random number 1 to 10>" << std::endl;
    for (auto i = 0; i < 10; i++) {
      std::cout << Random::number(1, 10) << " ";
    }
    std::cout << std::endl;
  }
};

} // namespace rl

int
main() {
  rl::RandomDemo().run();
  return 0;
}
