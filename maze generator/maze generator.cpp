#include <iostream>

#include "Map.hpp"
#include "MazeBuilder.hpp"

//commit merge pull push pullrequest

int main()
{
	Map q(20,80);
	MazeBuilder mb;
	mb.setMap(&q);
	mb.setStartPoint({ 5,10 });
	mb.build();
	std::cout << q;
	return 0;
}