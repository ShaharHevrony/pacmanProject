#pragma once
#include <vector>
#include <memory>

#include "values.h"
#include "board.h"
#include "resourcesManager.h"
#include "bar.h"
class PlayGame {
public:
    PlayGame(sf::RenderWindow& window, int level, bool& sound, Values& m_val);

    void print(Values& val);

    void playLevel(Values& m_val);

    void gameOver(int i);

    void LoadFile(std::vector<std::string>, Values& val);

    void dealWithCollision(bool& isFreeze, Values& val);

    void handleMouseMoved(sf::Event::MouseMoveEvent& event);

    void handleMouseButton(sf::Event::MouseButtonEvent& event);

    bool getBack();

    void setBack();

    bool getEndAllLevels();

    void setEndAllLevels();

    void setTime();

    bool timeOver() const;

private:
    int m_level;

    bool m_time = false;

    bool m_timeUp = false;

    bool  m_isFirstRound = true;

    bool m_endLevel = false;

    bool m_endGame = false;
    
    bool m_back = false;

    bool m_sound;


    BoardLimits m_boardLimits;

    sf::Clock m_timer;

    std::vector<std::unique_ptr<StaticObject>> m_staticObj;

    std::vector<std::unique_ptr<DynamicObject>> m_dynamicObj;

    Board* m_board;

    sf::RenderWindow* m_window;

    Bar m_bar;

    sf::Clock m_giftTime;

    sf::Music m_music;

    sf::Vector2f m_pacLocation;

    sf::Sprite m_backButton;

    sf::Sprite m_soundButton;
};

