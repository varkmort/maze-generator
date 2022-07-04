#include <iostream>

#include "Map.hpp"
#include "MazeBuilder.hpp"



int main()
{
	Map q(58, 235);//58,235 - fhd fullscrean
	MazeBuilder mb;
	mb.setMap(&q);
	mb.setStartPoint({ 2,5 });
	mb.build();
	std::cout << q;
	return 0;
}