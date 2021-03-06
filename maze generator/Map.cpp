#include "Map.hpp"

namespace Mazes {

	Map::Map(const long long length, const long long width)
		:length(length),
		width(width) {
		map = new Tile[length * width];
	}

	Map::Map(const Map &other)
		:length(other.length),
		width(other.width) {
		map = new Tile[length * width];
		memcpy(this->map, other.map, sizeof(Tile) * width * length);
	}

	Map::Map(Map &&other)noexcept
		:length(other.length),
		width(other.width) {
		this->map = other.map;
		other.map = nullptr;
	}

	Map::~Map() {
		if (!map) {
			delete[] map;
		}
	}

	void Map::setWall(Coord coord) {
		map[coord.y * width + coord.x].setState(Tile::State::wall);
	}

	void Map::setFlor(Coord coord) {
		map[coord.y * width + coord.x].setState(Tile::State::floor);
	}

	bool Map::isWall(Coord coord) {
		if (!isInner(coord)) {
			return true;
		}
		else {
			return map[coord.y * width + coord.x].isWall();
		}
	}

	bool Map::isInner(Coord coord) {
		return ((coord.y < length) && (coord.y >= 0)) &&
			((coord.x >= 0) && (coord.x < width));
	}



	std::ostream &operator<<(std::ostream &out, const Map &map) {
		for (long long i = 0; i < map.length; i++) {
			for (long long j = 0; j < map.width; j++) {
				if (map.map[i * map.width + j].isWall()) {
					out << char(0xDB);
				}
				else {
					out << char(0xB0);
				}
			}
			if (i < map.length - 1) {
				out << '\n';
			}
		}
		return out;
	}

	std::istream &operator>>(std::istream &in, const Map &map) {
		return in;
	}
}