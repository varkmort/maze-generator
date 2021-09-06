#include "Coord.hpp"


bool operator==(Coord a, Coord b) {
	return a.x == b.x && a.y == b.y;
}
bool operator<(Coord a, Coord b) {
	bool result{ false };

	return ((a.x + a.y) != (b.x + b.y)) && (a.x + a.y < b.x + b.y);
}