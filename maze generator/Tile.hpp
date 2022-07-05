#ifndef TITLE_HPP
#define TITLE_HPP


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

#endif // !TITLE_HPP