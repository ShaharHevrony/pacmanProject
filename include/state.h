#pragma once
#include "values.h"

class Pacman;
class Demon;
class Door;

class State {
public:
    State(Values& values);

    virtual ~State() = default;

    virtual void handleCollision(Pacman& pacman, Demon& demon) = 0;

    virtual void handleCollision(Pacman& pacman, Door& door)   = 0;

    bool getSuperState () const;

    void setSuperState (bool state);

protected:
    Values& m_val;

private:
    bool m_super = false;

    sf::Sprite m_pacman;
};

class SuperPacman: public State{
public:
    SuperPacman(Values& values);

    virtual void handleCollision(Pacman& pacman, Demon& demon){}

    virtual void handleCollision(Pacman& pacman, Door& door);
};

class RegularPacman: public State {
public:
    RegularPacman(Values& values);

    virtual void handleCollision(Pacman& pacman, Demon& demon);

    virtual void handleCollision(Pacman& pacman, Door& door);
};