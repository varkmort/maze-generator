#include <iostream>
#include <unordered_set>

#include "Map.hpp"
#include "MazeBuilder.hpp"



int main()
{
	Map q(20,80);
	MazeBuilder mb;
	mb.setMap(&q);
	mb.setStartPoint({ 10,10 });
	mb.build();
	std::cout << q;
	return 0;
}