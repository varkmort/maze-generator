#include "Coord.hpp"


bool operator==(Coord a, Coord b) {
	return a.x == b.x && a.y == b.y;
}

Coord Coord::up() {
	return {this->x, this->y - 1};
}

Coord Coord::down() {
	return {this->x , this->y + 1};
}

Coord Coord::left() {
	return {this->x - 1, this->y};
}

Coord Coord::right() {
	return {this->x + 1, this->y};
}