#ifndef WFC_HPP
#define WFC_HPP

#include "BuildWorker.hpp"

namespace Mazes {
	
	class WFC :public BuildWorker {
	public:
		virtual void construct(Map& place, Coord start);
		virtual void massonary(Map& place);
		virtual void roadwork(Map& place);
		~WFC() {}
	private:
		Map* data;
		Coord startPoint;
	};
   
}
#endif // !WFC_HPP