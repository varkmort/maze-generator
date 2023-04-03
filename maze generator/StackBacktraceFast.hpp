#ifndef STACK_BACKTRACE_FAST_HPP
#define STACK_BACKTRACE_FAST_HPP

#include <random>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <stack>


#include "BuildWorker.hpp"
namespace Mazes {
	class StackBacktraceFast: public BuildWorker {
	public:
		virtual void construct(Map &place, Coord start) override;
		virtual void massonary(Map &place)override;
		virtual void roadwork(Map &place)override;
		~StackBacktraceFast() {}
	private:
		void init(Map *, Coord start);
		void makeBorder(Map*, Coord start);
		void fillLake(Map& place);
		void removePillars(Map& place);
		void finish();
		std::vector<Coord> getDirections(Coord);
		bool isPossibleWay(Coord coord);
		bool isMazeComplite();
		Map *data;
		Coord startPoint;
		Coord current;
		std::stack<Coord> path;
		std::unordered_set<Coord> visited;
	};
}




#endif // !STACK_BACKTRACE_FAST