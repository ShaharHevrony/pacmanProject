#pragma once
#include <vector>
#include <memory>

#include "values.h"
#include "board.h"
#include "resourcesManager.h"
#include "bar.h"
class PlayGame {
public:
    PlayGame(sf::RenderWindow& window);

    void play();

    void print();

    void playLevel();

    void gameOver();

    void LoadFile(std::vector<std::string>);

    void dealWithCollision(bool& isFreeze);

private:
    int m_level;

    BoardLimits m_boardLimits;

    std::vector<std::unique_ptr<StaticObject>> m_staticObj;

    std::vector<std::unique_ptr<DynamicObject>> m_dynamicObj;

    Board* m_board;

    sf::RenderWindow* m_window;

    Bar m_bar;

    sf::Clock m_giftTime;

    sf::Vector2f m_pacLocation;

    Values m_val;
};

