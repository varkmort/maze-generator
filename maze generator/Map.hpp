#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <cstring>

#include <vector>
#include <memory>

#include "Tile.hpp"
#include "Coord.hpp"

namespace Mazes {
	class Map {
	public:
		Map(const long long length, const long long width);
		Map(const Map &other);
		virtual ~Map();
		void setWall(Coord);
		void setFlor(Coord);
		bool isWall(Coord);
		bool isPillar(Coord);
		bool hasPillars();
		long long length()const;
		long long width()const;
		friend std::ostream &operator<<(std::ostream &out, Map &map);
		//friend std::istream& operator>>(std::istream &in, const Map &map);

	private:
		
		bool isInner(Coord);
		std::vector<Tile> map_;
		const long long length_;
		const long long width_;
	};
}
#endif // !MAP_HPP