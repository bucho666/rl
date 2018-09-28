#include "../coord.h"
#include "../size.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

namespace rl {

class SizeTest : public ::testing::Test{};

TEST_F(SizeTest, Getter) {
  Size s = Size(1, 2);
  EXPECT_EQ(s.width(), 1);
  EXPECT_EQ(s.height(), 2);
}

TEST_F(SizeTest, Equal) {
  Size s = Size(1, 2);
  EXPECT_EQ(s, Size(1, 2));
}

TEST_F(SizeTest, For) {
  using std::vector;
  Size s = Size(2, 2);
  vector<Coord> result, expect = {
    Coord(0, 0), Coord(1, 0),
    Coord(0, 1), Coord(1, 1),
  };
  for (auto&& c : s) {
    result.push_back(c);
  }
  EXPECT_EQ(result.size(), expect.size());
  EXPECT_TRUE(std::equal(expect.cbegin(), expect.cend(), result.cbegin()));
}

TEST_F(SizeTest, BorderHas) {
  Size s = Size(3, 3);
  EXPECT_TRUE(s.borderHas(Coord(0, 0)));
  EXPECT_TRUE(s.borderHas(Coord(1, 0)));
  EXPECT_TRUE(s.borderHas(Coord(2, 0)));
  EXPECT_TRUE(s.borderHas(Coord(0, 1)));
  EXPECT_FALSE(s.borderHas(Coord(1, 1)));
  EXPECT_TRUE(s.borderHas(Coord(2, 1)));
  EXPECT_TRUE(s.borderHas(Coord(0, 2)));
  EXPECT_TRUE(s.borderHas(Coord(1, 2)));
  EXPECT_TRUE(s.borderHas(Coord(2, 2)));
}

}
