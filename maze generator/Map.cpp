#include "Map.hpp"

namespace Mazes {

	Map::Map(const long long length, const long long width)
		:length_(length),
		width_(width),
		map_(length* width)
	{
		
	}

	Map::Map(const Map &other)
		:length_(other.length_),
		width_(other.width_),
		map_(other.map_)
	{}
	
	

	

	Map::~Map() {}

	void Map::setWall(Coord coord) {
		map_[coord.y * width_ + coord.x].setState(Tile::State::wall);
	}

	void Map::setFlor(Coord coord) {
		map_[coord.y * width_ + coord.x].setState(Tile::State::floor);
	}

	bool Map::isWall(Coord coord) {
		if (!isInner(coord)) {
			return true;
		}
		else {
			return map_[coord.y * width_ + coord.x].isWall();
		}
	}

	bool Map::isPillar(Coord start){
		int count{};
		if (isWall({ start.x + 1,start.y }))count++;
		if (isWall({ start.x + 1,start.y + 1 }))count++;
		if (isWall({ start.x + 1,start.y - 1 }))count++;

		if (isWall({ start.x,start.y + 1 }))count++;
		if (isWall({ start.x,start.y - 1 }))count++;

		if (isWall({ start.x - 1,start.y }))count++;
		if (isWall({ start.x - 1,start.y + 1 }))count++;
		if (isWall({ start.x - 1,start.y - 1 }))count++;
		return (count < 2 && isWall(start)) ? true : false;
	}

	bool Map::hasPillars()
	{
		for (long long i = 0; i < width(); i++) {
			for (long long j = 0; j < length(); j++) {
				if (isPillar({ i,j })) {
					return true;
				}
			}
		}
		return false;
	}
	

	long long Map::length() const{
		return length_;
	}

	long long Map::width() const{
		return width_;
	}

	bool Map::isInner(Coord coord) {
		return ((coord.y < length_) && (coord.y >= 0)) &&
			((coord.x >= 0) && (coord.x < width_));
	}




	std::ostream &operator<<(std::ostream &out, Map &map) {
		for (long long i = 0; i < map.length_; i++) {
			for (long long j = 0; j < map.width_; j++) {
				if (map.map_[i * map.width_ + j].isWall()) {
					out << char(0xDB);
				}
				else {
					out << char(0xB0);
				}
			}
			if (i < map.length_ - 1) {
				out << '\n';
			}
		}
		return out;
	}

	std::istream &operator>>(std::istream &in, const Map &map) {
		return in;
	}
}