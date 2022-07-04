#include "Coord.hpp"


bool operator==(Coord a, Coord b) {
	return a.x == b.x && a.y == b.y;
}
