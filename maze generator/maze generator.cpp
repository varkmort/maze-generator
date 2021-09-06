#include <iostream>


#include "Map.hpp"




int main()
{
	Map q(20,80);
	for (size_t i = 0; i < 20; i++) {
		q.setWall({ i,i });
	}
	std::cout << q;
	return 0;
}