#ifndef MAZE_BUILDER_HPP
#define MAZE_BUILDER_HPP



#include "Map.hpp"
#include "BuildWorker.hpp"

class MazeBuilder {
public:
	MazeBuilder();
	void makeFast();
	void makeSlow();
	void build(Map& place,Coord start);
	~MazeBuilder();
private:
	BuildWorker *executor;
};

#endif // !MAZE_BUILDER_HPP