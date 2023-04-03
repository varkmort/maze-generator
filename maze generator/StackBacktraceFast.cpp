#include "StackBacktraceFast.hpp"

namespace Mazes {

    void StackBacktraceFast::construct(Map &place, Coord start) {
        std::random_device generator;
        init(&place, start);
        while (!isMazeComplite()) {
            path.push(current);
            visited.insert(current);
            auto directions = getDirections(current);
            while (!directions.size()) {
                if (isMazeComplite()) {
                    break;
                } 
                current = path.top();
                
                if (path.size()>1) {
                    path.pop();
                }
                directions = getDirections(current);
            }
            if (directions.size() > 1) {
                std::shuffle(
                    directions.begin(),
                    directions.end(),
                    generator
                );
                std::uniform_int_distribution<int> distribution(
                    1,
                    static_cast<int>(directions.size() - 1)
                );
                auto del = distribution(generator);
                for (size_t i = 1; i <= del; i++) {
                    place.setWall(directions[i]);
                }
            }
            if (!directions.empty()) {
                current = directions.front();
            }
        }
    }

    void StackBacktraceFast::massonary(Map &place) {
        fillLake(place);
        removePillars(place);
    }

    void StackBacktraceFast::roadwork(Map &place) {
        //to-do нужно чтоб были реализованы анализаторы 
    }

    void StackBacktraceFast::init(Map *place, Coord start) {
        data = place;
        current = start;
        startPoint = start;
        //makeBorder(place, start);
    }

    void StackBacktraceFast::makeBorder(Map* place, Coord start)    {
        Coord tmp{ 0,0 };
        while (!(place->isWall(tmp)))
        {
            place->setWall(tmp);
            tmp.x++;
        }
        tmp.x--;
        tmp.y++;
        while (!(place->isWall(tmp)))
        {
            place->setWall(tmp);
            tmp.y++;
        }
        tmp.y--;
        tmp.x--;
        while (!(place->isWall(tmp)))
        {
            place->setWall(tmp);
            tmp.x--;
        }
        tmp.x++;
        tmp.y--;
        while (!(place->isWall(tmp)))
        {
            place->setWall(tmp);
            tmp.y--;
        }
    }

    void StackBacktraceFast::fillLake(Map& place){
        for (long long i = 0; i < place.width(); i++) {
            for (long long j = 0; j < place.length(); j++)
            {
                if (!(visited.contains({ i,j })) && !(place.isWall({ i,j }))) {
                    place.setWall({ i,j });
                }
            }
        }
    }

    void StackBacktraceFast::removePillars(Map& place){
        while (place.hasPillars()){
            for (long long i = 0; i < place.width(); i++) {
                for (long long j = 0; j < place.length(); j++) {
                    if (place.isPillar({ i,j })) {
                        place.setFlor({ i,j });
                    }
                }
            }            
        }
    }

   

    void StackBacktraceFast::finish() {
        data = nullptr;
        startPoint = current = {0,0};
    }

    std::vector<Coord> StackBacktraceFast::getDirections(Coord coord) {
        std::vector<Coord> result;
        result.reserve(4);
        auto directions = {
            coord.up(),
            coord.down(),
            coord.left(),
            coord.right()
        };
        for (const auto &dirrection : directions) {
            if (isPossibleWay(dirrection)) {
                result.push_back(dirrection);
            }
        }
        return result;
    }

    bool StackBacktraceFast::isMazeComplite() {
        return bool(current == startPoint && getDirections(current).empty());
    }

    bool StackBacktraceFast::isPossibleWay(Coord coord) {
        return !data->isWall(coord) && !visited.contains(coord);
    }
}