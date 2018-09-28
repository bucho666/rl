#include "../grid.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

namespace rl {

class GridTest : public ::testing::Test{};

TEST_F(GridTest, Getter) {
  Grid<char> g = Grid(Size(2, 3), 'x');
  EXPECT_EQ(g.width(), 2);
  EXPECT_EQ(g.height(), 3);
  EXPECT_EQ(g.size(), Size(2, 3));
  for (auto&& c : g) {
    EXPECT_EQ(g[c], 'x');
  }
}

TEST_F(GridTest, Fill) {
  Grid<char> g = Grid(Size(2, 3), 'x');
  g.fill('*');
  for (auto&& c : g) {
    EXPECT_EQ(g[c], '*');
  }
}

TEST_F(GridTest, Set) {
  Grid<char> g = Grid(Size(2, 3), 'x');
  Coord p = Coord(1, 2);
  g[p] = '*';
  for (auto&& c : g) {
    EXPECT_EQ(g[c], c == p ? '*': 'x');
  }
}

TEST_F(GridTest, For) {
  using std::vector;
  Grid<char> g = Grid(Size(2, 3), 'x');
  vector<Coord> result, except = {
    Coord(0, 0), Coord(1, 0),
    Coord(0, 1), Coord(1, 1),
    Coord(0, 2), Coord(1, 2)
  };
  for (auto&& c : g) result.push_back(c);
  EXPECT_EQ(result.size(), except.size());
  EXPECT_TRUE(std::equal(result.cbegin(), result.cend(), except.cbegin()));
}

}
