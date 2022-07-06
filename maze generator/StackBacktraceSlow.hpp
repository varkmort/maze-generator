#ifndef STACK_BACKTRACE_SLOW_HPP
#define STACK_BACKTRACE_SLOW_HPP

#include <random>
#include <algorithm>
#include <vector>
#include <stack>

#include "BuildWorker.hpp"
namespace Mazes {
	class StackBacktraceSlow: public BuildWorker {
	public:
		virtual void construct(Map &place, Coord start);
		virtual void massonary(Map &place);
		virtual void roadwork(Map &place);
	private:
		void init(Map *, Coord start);
		void finish();
		std::vector<Coord> getDirections(Coord);
		bool isPossibleWay(Coord coord);
		bool isMazeComplite();
		Map *data;
		Coord startPoint;
		Coord current;
		std::stack<Coord> path;
		std::vector<Coord> visited;
	};
}
#endif // !STACK_BACKTRACE_SLOW_HPP