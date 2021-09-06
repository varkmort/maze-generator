#pragma once

#include <iostream>
#include <cstring>
#include "Tile.hpp"
struct Coord {
	size_t x;
	size_t y;
	friend bool operator==(Coord, Coord);
	friend bool operator<(Coord, Coord);
	friend bool operator>(Coord, Coord);
};
class Map {
public:
	Map(const size_t length, const size_t width);
	Map(const Map &other);
	Map(Map &&other);
	~Map();
	void setWall(Coord);
	void setFlor(Coord);
	bool isWall(Coord);
	friend std::ostream& operator<<(std::ostream &out, const Map &map);
	friend std::istream& operator>>(std::istream &in, const Map &map);

private:
	bool isInner(Coord);
	Tile **map;
	const size_t length;
	const size_t width;
};

