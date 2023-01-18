#pragma once
#include "object.h"
#include "values.h"

class DynamicObject: public Object {
public:
    DynamicObject(sf::Texture* texture, const sf::Vector2f& position, float tileSize,char type);

    virtual void move(float time, sf::Vector2f pacLocation) = 0;

    virtual void handleCollision(Object& object) = 0;

    virtual void handleCollision(Pacman& pacman) = 0;

    virtual void handleCollision(Demon& demon)   = 0;

    virtual void handleCollision(Cookie& cookie) = 0;

    virtual void handleCollision(Door& door)     = 0;

    virtual void handleCollision(Gift& gift)     = 0;

    virtual void handleCollision(Key& key)       = 0;

    virtual void handleCollision(Wall& wall);

    void moving(sf::Vector2f direction, float time, sf::Vector2f pacLocation);

    int getNextRow() const;

    int getNextCol() const;

    bool getIsDelete() const;

    void setDelete();

protected:
    sf::Vector2f getPosition() const;

    void setPosition(sf::Vector2f position);

    sf::Vector2f getLastPosition() const;

    sf::Rect<float> getGlobalBounds() const;

    void setLastPosition(sf::Vector2f position);

    sf::Vector2f getOriginPosition() const;

private:
    sf::Vector2f m_lastPosition;

    sf::Vector2f m_originPosition;

    bool m_isDelete = false;

    int m_nextRow;

    int m_nextCol;
};