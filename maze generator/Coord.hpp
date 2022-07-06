#ifndef COORD_HPP
#define COORD_HPP

#include <type_traits>
namespace Mazes {
    class Coord {
    public:
        long long x;
        long long y;

        Coord():Coord(0ll, 0ll) {
        }
        Coord(long long x, long long y):x(x), y(y) {
        }

        friend bool operator==(Coord, Coord);

        Coord up();
        Coord down();
        Coord left();
        Coord right();
    };
}

namespace std {
    template <>
    struct hash<Mazes::Coord> {
        std::size_t operator()(const Mazes::Coord &c) const {
            using std::size_t;
            using std::hash;
            return (hash<size_t>()(c.x) ^ (hash<size_t>()(c.y) << 1));
        }
    };

}

#endif // !COORD_HPP