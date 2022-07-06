#ifndef BUILD_WORKER_HPP
#define BUILD_WORKER_HPP

#include "Coord.hpp"
#include "Map.hpp"

class BuildWorker {
public:
	virtual void construct(Map &place, Coord start) = 0;
	virtual void massonary(Map &place) = 0;
	virtual void roadwork(Map &place) = 0;
};

#endif // !BUILD_WORKER_HPP