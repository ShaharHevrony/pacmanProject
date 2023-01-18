#pragma once
#include "playGame.h"
#include "resourcesManager.h"
#include "values.h"
#include "menu.h"
#include "createLevel.h"
#include <SFML/Graphics.hpp>


class Controller {
public:
    Controller();

    ~Controller() = default;

    void run();

    void create();

    //function that handel the case in a mouse button
    void handleMouseButton(sf::Event::MouseButtonEvent& event);

    void handleMouseMoved(sf::Event::MouseMoveEvent& event);



private:
    sf::RenderWindow m_window;

    PlayGame m_playGame;

    sf::Texture m_texture[4];

    std::vector<sf::Sprite> m_menu;

    sf::Text m_text;

    sf::Texture m_backgroundTexture;

    sf::Sprite m_backgroundSprite;

    int  m_tempButton = 0;
};

