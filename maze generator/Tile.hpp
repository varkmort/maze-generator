#pragma once

class Tile {
public:
    enum State {
        floor,
        wall
    };
    Tile();
    State getState()const;
    void setState(State state);
    bool isWall();
private:
    State state_;
};

