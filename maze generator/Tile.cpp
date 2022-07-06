#include "Tile.hpp"

namespace Mazes {
	Tile::Tile():state_(State::floor) {
	}

	Tile::State Tile::getState() const {
		return state_;
	}

	void Tile::setState(State state) {
		state_ = state;
	}

	bool Tile::isWall() {
		return static_cast<bool>(this->state_);
	}
}