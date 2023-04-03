#include "DetailedTiles.hpp"

namespace Mazes {

    Path::Path()
    {
        this->setState(Tile::State::floor);
    }

    Border::Border() {
        this->setState(Tile::State::wall);
    }

    Field::Field() {
        this->setState(Tile::State::floor);
    }

}