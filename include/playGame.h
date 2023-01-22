#pragma once
#include <vector>
#include <memory>

#include "values.h"
#include "board.h"
#include "resourcesManager.h"
#include "bar.h"
class PlayGame {
public:
    PlayGame(sf::RenderWindow& window, bool& sound);

    void play();

    void print();

    void playLevel();

    void gameOver();

    void LoadFile(std::vector<std::string>);

    void dealWithCollision(bool& isFreeze);

    bool changeSound();

    void handleMouseMoved(sf::Event::MouseMoveEvent& event);

    void handleMouseButton(sf::Event::MouseButtonEvent& event);

private:
    int m_level;

    BoardLimits m_boardLimits;

    bool m_sound;

    std::vector<std::unique_ptr<StaticObject>> m_staticObj;

    std::vector<std::unique_ptr<DynamicObject>> m_dynamicObj;

    Board* m_board;

    sf::RenderWindow* m_window;

    Bar m_bar;

    sf::Clock m_giftTime;

    Values m_val;

    sf::Music m_music;

    sf::Vector2f m_pacLocation;

    sf::Sprite m_backButton;

    sf::Sprite m_soundButton;
};

