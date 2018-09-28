#include "../coord.h"
#include <gtest/gtest.h>

namespace rl {

class CoordTest : public ::testing::Test{};
class CoordIteratorTest : public ::testing::Test{};

TEST_F(CoordTest, Equal) {
  EXPECT_EQ(Coord(1, 2), Coord(1, 2));
  EXPECT_NE(Coord(1, 2), Coord(2, 3));
  EXPECT_NE(Coord(1, 2), Coord(1, 3));
  EXPECT_NE(Coord(1, 2), Coord(0, 2));
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

TEST_F(CoordIteratorTest, NotEqual) {
  CoordIterator itr = CoordIterator(Coord(1, 2), 3);
  EXPECT_FALSE(itr != CoordIterator(Coord(1, 2), 3));
  EXPECT_TRUE(itr != CoordIterator(Coord(3, 2), 4));
  EXPECT_FALSE(itr != CoordIterator(Coord(1, 2), 4));
}

}
