#include "WFC.hpp"

namespace Mazes {

	void WFC::construct(Map& place, Coord start)
	{	
		this->data = &place;
		this->startPoint = start;


	}
}