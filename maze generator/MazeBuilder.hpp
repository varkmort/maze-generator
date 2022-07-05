#ifndef MAZE_BUILDER_HPP
#define MAZE_BUILDER_HPP

#include <random>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <stack>

#include "Map.hpp"

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
	bool isPossibleWay(Coord coord);
	Map *data;
	Coord startPoint;
	Coord current;
	std::stack<Coord> path;
    std::unordered_set<Coord> visited;
};

#endif // !MAZE_BUILDER_HPP