#include "bar.h"
#include <cmath>
Bar::Bar(int startTime):m_startTime(startTime) {

    for(int bar = 0; bar < 3; bar++){
        m_text[bar] = sf::Text(gameBar[bar], ResourcesManager::inctance().getFont(), 30);
    }
    m_timer.restart().asSeconds();
}

void Bar::draw(sf::RenderWindow& window, const Values& val){

    //Create the timer
    std::stringstream remainTime;
    float elapse = m_startTime - round(m_timer.getElapsedTime().asSeconds());
    remainTime.str("");
    remainTime << elapse;
    if(elapse <= 0){
        m_bar[0] = sf::Text("Time over!", ResourcesManager::inctance().getFont(), 100);
    } else {
        m_bar[0] = sf::Text(m_text[0].getString() + remainTime.str().c_str(), ResourcesManager::inctance().getFont(), 100);
        //+ remainTime.str()
    }

    //Create the score
    std::stringstream score;
    score.str("");
    score << val.getScore();
    m_bar[1] = sf::Text(m_text[1].getString() + score.str().c_str(), ResourcesManager::inctance().getFont(), 100);

    //Create the life
    std::stringstream life;
    life.str("");
    life << val.getLife();
    m_bar[2] = sf::Text(m_text[2].getString() + life.str().c_str(), ResourcesManager::inctance().getFont(), 100);

    for(int bar = 0; bar < 3; bar++){
        m_bar[bar].setFillColor(sf::Color(500, 160, 28));
        m_bar[bar].setOutlineThickness(2);
        m_bar[bar].setOutlineColor(sf::Color(600, 100, 28));
        m_bar[bar].setPosition(2000, 150 + 200 * bar);
        window.draw(m_bar[bar]);
    }
}