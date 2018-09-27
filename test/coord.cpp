#include "../coord.h"
#include <gtest/gtest.h>

namespace rl {

class CoordTest : public ::testing::Test{};

TEST_F(CoordTest, Equal) {
  EXPECT_EQ(Coord(1, 2), Coord(1, 2));
  EXPECT_NE(Coord(1, 2), Coord(2, 3));
  EXPECT_NE(Coord(1, 2), Coord(1, 3));
  EXPECT_NE(Coord(1, 2), Coord(0, 2));
}

}
