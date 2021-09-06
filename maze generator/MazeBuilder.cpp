#include "MazeBuilder.hpp"




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
    current=startPoint;
    while (!isMazeComplite())
    {
        //get possible directions
        auto directions = getDirections(current);
        while(!directions.size() || isMazeComplite()){
            current = path.top();
            path.pop();
            directions = getDirections(current);
        }
        if(directions.size()>1){
            std::shuffle(directions.begin(),directions.end(),generator);
            std::uniform_int_distribution<int> distribution(0,directions.size()-1);
            auto it = directions.rbegin();
            switch(distribution(generator)){
                case 3:
                    data->setWall(*it);
                    ++it;
                case 2:
                    data->setWall(*it);
                    ++it;
                case 1:
                    data->setWall(*it);
                    ++it;
                default:
                break;
            }
        }
        //make step
        path.push(current);
        visited.insert(current);
        current = *directions.begin();
    }
    
    
}

void MazeBuilder::free() {
    while(!path.empty())path.pop();
    visited=std::set<Coord>();
    data = nullptr;
}

Map *MazeBuilder::getMap() const {
    return data;
}

Coord MazeBuilder::getStartPoint() const {
    return startPoint;
}

std::vector<Coord> MazeBuilder::getDirections(Coord coord){
    std::vector<Coord> result;
    for(auto &dirrection:{up(coord), down(coord), left(coord), right(coord)}){
        if(isPossibleway(dirrection)){
            result.push_back(dirrection);
        }   
    }
   return result;   
}

bool MazeBuilder::isMazeComplite(){
    return bool(current==startPoint && !getDirections(current).size());
}

bool MazeBuilder::isPossibleway(Coord coord){
    return !data->isWall(coord) && !visited.contains(coord);
}

Coord MazeBuilder::up(Coord coord){return coord.x+=1,coord;}
Coord MazeBuilder::down(Coord coord){return coord.x-=1,coord;}
Coord MazeBuilder::left(Coord coord){return coord.y-=1,coord;}
Coord MazeBuilder::right(Coord coord){return coord.y+=1,coord;}