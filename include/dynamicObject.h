#pragma once
#include "object.h"
#include "values.h"

class DynamicObject: public Object {
public:
    DynamicObject(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type, Values& values);

    virtual void move(float time, sf::Vector2f pacLocation) = 0;

    virtual void handleCollision(Object& object)                   = 0;

    virtual void handleCollision(Pacman& pacman)                   = 0;

    virtual void handleCollision(Demon& demon)                     = 0;

    virtual void handleCollision(Cookie& cookie)                   = 0;

    virtual void handleCollision(Door& door)                       = 0;

    virtual void handleCollision(Gift& gift)                       = 0;

    virtual void handleCollision(Key& key)                         = 0;

    virtual void handleCollision(Wall& wall);

    void moving(sf::Vector2f direction, float time, sf::Vector2f pacLocation);

    int getNextRow() const;

    int getNextCol() const;

    bool getCollided() const;

    void setCollided();

    void setPosition(sf::Vector2f position);

    sf::Vector2f getOriginPosition();

    sf::Vector2f getLastPosition() const;

    bool getRestartDemon() const;

    void setRestartDemon();

protected:
    sf::Vector2f getPosition() const;

    sf::Rect<float> getGlobalBounds() const;

    void setLastPosition(sf::Vector2f position);


private:
    sf::Vector2f m_lastPosition;

    sf::Vector2f m_originPosition;

    bool m_collided = false;

    bool m_restarDemon = false;

    int m_nextRow;

    int m_nextCol;
};
