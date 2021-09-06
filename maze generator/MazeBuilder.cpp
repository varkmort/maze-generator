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
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(1,6);
    int dice_roll = distribution(generator);
    std::stack<Coord> path;
    std::set<Coord> visited;
    Coord current{startPoint};
    while (false/*end when we back to start and have 0 direction*/)
    {
        //add current position in stack
        path.push(current);
        visited.insert(current);
        //get possible directions

        //reserve 1 dirrection
        //1-n rest fill with walls
        //make step
        //back to 1 until we have atleast 1 direction per step
        //else backtrack until we got step with 1 or more dirrection
    }
    
    
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
