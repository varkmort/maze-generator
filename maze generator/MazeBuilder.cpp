#include "MazeBuilder.hpp"


#include <random>
#include <chrono>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>

MazeBuilder::MazeBuilder(Map *map, Coord startPoint):data(map), startPoint(startPoint){}

void MazeBuilder::setMap(Map *map) {
    data = map;
}

void MazeBuilder::setStartPoint(Coord coord) {
    startPoint = coord;
}

void MazeBuilder::build() {
    std::stack<Coord> path;
    std::set<Coord> visited;
    //add current position in stack
    path.push(startPoint);
    //get possible directions
    //reserve 1 dirrection
    //1-n rest fill with walls
    //make step
    //back to 1 until we have atleast 1 direction per step
    //else backtrack until we got step with 1 or more dirrection
    //end when we back to start and have 0 direction
}

void MazeBuilder::free() {
    data = nullptr;
}

Map *MazeBuilder::getMap() const {
    return data;
}

Coord MazeBuilder::getStartPoint() const {
    return startPoint;
}
