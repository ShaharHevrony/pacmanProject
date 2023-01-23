//
// Created by Shahar Hevrony on 20/01/2023.
//

#include "state.h"
#include "door.h"

State::State(Values& values): m_val(values) {}

bool State::getSuperState() const {
    return m_super;
}

void State::setSuperState(bool state) {
    m_super = state;
}

Values State::getVal() const {
    return m_val;
}

SuperPacman::SuperPacman(Values& values):State(values) {
    setSuperState(true);
}

void SuperPacman::handleCollision(Pacman &pacman, Door &door) {
    door.setDelete();
}

RegularPacman::RegularPacman(Values& values):State(values) {
    setSuperState(false);
}

void RegularPacman::handleCollision(Pacman &pacman, Door &door) {
    pacman.setPosition(pacman.getLastPosition());
}
void RegularPacman::handleCollision(Pacman &pacman, Demon &demon) {
    pacman.setPosition(pacman.getOriginPosition());
    pacman.setRestartDemon();
    pacman.setCollided();
    getVal().setLife(DEC);
}
