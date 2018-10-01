#pragma once

#include "coord.h"
#include <vector>

namespace rl {

const Coord Direction::HERE = Coord(0, 0);
const Coord Direction::N  = Coord( 0, -1);
const Coord Direction::E  = Coord( 1,  0);
const Coord Direction::W  = Coord(-1,  0);
const Coord Direction::S  = Coord( 0,  1);
const Coord Direction::NE = Coord( 1, -1);
const Coord Direction::SE = Coord( 1,  1);
const Coord Direction::SW = Coord(-1,  1);
const Coord Direction::NW = Coord(-1, -1);
const Coord Direction::UP = Direction::N;
const Coord Direction::DOWN = Direction::S;
const Coord Direction::LEFT = Direction::W;
const Coord Direction::RIGHT = Direction::E;
const std::vector<Coord> Direction::CROSS = {
  Direction::N, Direction::E, Direction::W, Direction::S
};
const std::vector<Coord> Direction::AROUND = {
  Direction::N, Direction::NE, Direction::E, Direction::SE,
  Direction::S, Direction::SW, Direction::W, Direction::NW
};

}
