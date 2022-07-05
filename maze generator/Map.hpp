#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <cstring>

#include "Tile.hpp"
#include "Coord.hpp"

class Map {
public:
	Map(const long long length, const long long width);
	Map(const Map &other);
	Map(Map &&other)noexcept;
	virtual ~Map();
	void setWall(Coord);
	void setFlor(Coord);
	bool isWall(Coord);
	friend std::ostream& operator<<(std::ostream &out, const Map &map);
	//friend std::istream& operator>>(std::istream &in, const Map &map);

private:
	bool isInner(Coord);
	Tile *map;
	const long long length;
	const long long width;
};

#endif // !MAP_HPP