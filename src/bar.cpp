#include "bar.h"
#include <cmath>
Bar::Bar(Values& values):m_val(values) {

    for(int bar = 0; bar < 4; bar++){
        m_text[bar] = sf::Text(gameBar[bar], ResourcesManager::inctance().getFont(), 20);
    }
    m_timer.restart().asSeconds();
}

void Bar::draw(sf::RenderWindow& window, const Values& val){

    float elapse = m_val.getTime() - round(m_timer.getElapsedTime().asSeconds());
    std::stringstream str[4];
    for (int i = 0; i < 4; i++){
        str[i].str("");
    }
    str[0] << m_val.getLevel();
    str[1] << elapse;
    str[2] << val.getScore();
    str[3] << val.getLife();
    for(int bar = 0; bar < 4; bar++){
        if(bar == 1 && elapse <= 0){
            m_bar[1] = sf::Text("Time over!", ResourcesManager::inctance().getFont(), 60);
        } else {
            m_bar[bar] = sf::Text(m_text[bar].getString() + str[bar].str().c_str(), ResourcesManager::inctance().getFont(),60);
        }
    }

    for(int bar = 0; bar < 4; bar++){
        m_bar[bar].setFillColor(sf::Color(255,255,240));
        m_bar[bar].setOutlineThickness(2);
        m_bar[bar].setOutlineColor(sf::Color(255,255,240));
        m_bar[bar].setPosition(1450, 160 + 100 * bar);
        window.draw(m_bar[bar]);
    }
}
