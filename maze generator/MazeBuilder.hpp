#pragma once

#include "Map.hpp"
#include <random>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <stack>

class MazeBuilder {
public:
	MazeBuilder(Map *map = nullptr, Coord startPoint = { 0u, 0u});
	void setMap(Map *map);
	void setStartPoint(Coord);
	void build();
	void free();
	Map *getMap()const;
	Coord getStartPoint()const;
	bool isMazeComplite();
private:
	std::vector<Coord> getDirections(Coord);
	Coord up(Coord coord);
	Coord down(Coord coord);
	Coord left(Coord coord);
	Coord right(Coord coord);
	bool isPossibleWay(Coord coord);
	Map *data;
	Coord startPoint;
	Coord current;
	std::stack<Coord> path;
    std::unordered_set<Coord> visited;
};

