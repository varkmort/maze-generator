#ifndef COORD_HPP
#define COORD_HPP

#include <type_traits>

class Coord {
public:
	size_t x;
	size_t y;

	friend bool operator==(Coord, Coord);

    Coord up();
    Coord down();
    Coord left();
    Coord right();
};


namespace std {
    template <>
    struct hash<Coord> {
        std::size_t operator()(const Coord &c) const {
            using std::size_t;
            using std::hash;
            return (hash<size_t>()(c.x) ^ (hash<size_t>()(c.y) << 1));
        }
    };

}

#endif // !COORD_HPP