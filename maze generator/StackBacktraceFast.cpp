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
                if (!path.empty()) {
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
        //to-do нужно чтоб были реализованы анализаторы 
    }

    void StackBacktraceFast::roadwork(Map &place) {
        //to-do нужно чтоб были реализованы анализаторы 
    }

    void StackBacktraceFast::init(Map *place, Coord start) {
        data = place;
        current = start;
        startPoint = start;
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
        return bool(current == startPoint && !getDirections(current).size());
    }

    bool StackBacktraceFast::isPossibleWay(Coord coord) {
        return !data->isWall(coord) && !visited.contains(coord);
    }
}