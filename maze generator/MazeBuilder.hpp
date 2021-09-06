#pragma once

#include"Map.hpp"


class MazeBuilder {
public:
	MazeBuilder(Map *map = nullptr, Coord startPoint = { 0u, 0u});
	void setMap(Map *map);
	void setStartPoint(Coord);
	void build();
	void free();
	Map *getMap()const;
	Coord getStartPoint()const;
private:
	Map *data;
	Coord startPoint;
};

