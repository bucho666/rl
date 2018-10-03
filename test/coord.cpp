#include "../coord.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

namespace rl {

class CoordTest : public ::testing::Test{};
class CoordIteratorTest : public ::testing::Test{};

TEST_F(CoordTest, Equal) {
  EXPECT_EQ(Coord(1, 2), Coord(1, 2));
  EXPECT_NE(Coord(1, 2), Coord(2, 3));
  EXPECT_NE(Coord(1, 2), Coord(1, 3));
  EXPECT_NE(Coord(1, 2), Coord(0, 2));
}

TEST_F(CoordTest, Greater) {
  EXPECT_TRUE(Coord(1 ,2) < Coord(2, 2));
  EXPECT_TRUE(Coord(2 ,2) < Coord(1, 3));
}

TEST_F(CoordTest, Getter) {
  Coord c = Coord(1, 2);
  EXPECT_EQ(c.x(), 1);
  EXPECT_EQ(c.y(), 2);
}

TEST_F(CoordTest, PlusMinus) {
  Coord a = Coord(1, 2);
  Coord b = Coord(3, 4);
  EXPECT_EQ(a + b, Coord(4, 6));
  EXPECT_EQ(b - a, Coord(2, 2));
  EXPECT_EQ(a - b, Coord(-2, -2));
}

TEST_F(CoordTest, PlusMinusEqual) {
  Coord a = Coord(1, 2);
  a += Coord(3, 4);
  EXPECT_EQ(a, Coord(4, 6));
  a -= Coord(1, 2);
  EXPECT_EQ(a, Coord(3, 4));
}

TEST_F(CoordTest, Around) {
  Coord center = Coord(2, 2);
  std::vector<Coord> result, expect = {
    Coord(2, 1), Coord(3, 1), Coord(3, 2),
    Coord(3, 3), Coord(2, 3), Coord(1, 3),
    Coord(1, 2), Coord(1, 1),
  };
  for (auto&& c : center.around()) result.push_back(c);
  EXPECT_EQ(result.size(), expect.size());
  EXPECT_TRUE(std::equal(result.cbegin(), result.cend(), expect.cbegin()));
}

TEST_F(CoordTest, Cross) {
  Coord center = Coord(2, 2);
  std::vector<Coord> result, expect = {
    Coord(2, 1), Coord(3, 2), Coord(2, 3), Coord(1, 2),
  };
  for (auto&& c : center.cross()) result.push_back(c);
  EXPECT_EQ(result.size(), expect.size());
  EXPECT_TRUE(std::equal(result.cbegin(), result.cend(), expect.cbegin()));
}


TEST_F(CoordIteratorTest, Asterisk) {
  CoordIterator itr = CoordIterator(Coord(1, 2), 3);
  EXPECT_EQ(*itr, Coord(1, 2));
}

TEST_F(CoordIteratorTest, Incriment) {
  CoordIterator itr = CoordIterator(Coord(1, 2), 3);
  ++itr;
  EXPECT_EQ(*itr, Coord(2, 2));
  ++itr;
  EXPECT_EQ(*itr, Coord(0, 3));
}

TEST_F(CoordIteratorTest, IncrimentHasLeft) {
  CoordIterator itr = CoordIterator(Coord(2, 2), 3, 1);
  ++itr;
  EXPECT_EQ(*itr, Coord(1, 3));
}

TEST_F(CoordIteratorTest, NotEqual) {
  CoordIterator itr = CoordIterator(Coord(1, 2), 3);
  EXPECT_FALSE(itr != CoordIterator(Coord(1, 2), 3));
  EXPECT_TRUE(itr != CoordIterator(Coord(3, 2), 4));
  EXPECT_FALSE(itr != CoordIterator(Coord(1, 2), 4));
}

}
