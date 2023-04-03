#ifndef DETEILED_TITLES_HPP
#define DETEILED_TITLES_HPP

#include "Tile.hpp"

namespace Mazes {

    class Path :public Tile {
    public:
        Path();
    };

    class Border :public Tile {
    public:
        Border();
    };

    class Field:public Tile{
    public:
        Field();
    };


   
}
#endif //DETEILED_TITLES_HPP