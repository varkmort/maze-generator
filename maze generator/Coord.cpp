#include "Coord.hpp"

namespace Mazes {
	bool operator==(Coord a, Coord b) {
		return a.x == b.x && a.y == b.y;
	}

	Coord Coord::up() {
		return Coord{this->x, this->y - 1};
	}

	Coord Coord::down() {
		return Coord{this->x , this->y + 1};
	}

	Coord Coord::left() {
		return Coord{this->x - 1, this->y};
	}

	Coord Coord::right() {
		return Coord{this->x + 1, this->y};
	}
}