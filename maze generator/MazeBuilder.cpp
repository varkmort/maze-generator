#include "MazeBuilder.hpp"

#include "StackBacktraceFast.hpp"
#include "StackBacktraceSlow.hpp"

namespace Mazes {
    MazeBuilder::MazeBuilder() {
        this->executor = new StackBacktraceFast;
    }

    void MazeBuilder::makeFast() {
        delete executor;
        this->executor = new StackBacktraceFast;
    }

    void MazeBuilder::makeSlow() {
        delete executor;
        this->executor = new StackBacktraceSlow;
    }


    void MazeBuilder::build(Map &place, Coord start) {
        executor->construct(place, start);
        executor->massonary(place);
        executor->roadwork(place);
    }

    MazeBuilder::~MazeBuilder() {
        delete executor;
    }
}