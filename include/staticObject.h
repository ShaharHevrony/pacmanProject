#pragma once
#include "object.h"

class StaticObject: public Object{
public:
    StaticObject(sf::Texture* texture, const sf::Vector2f& position, float tileSize, char type);

    virtual void handleCollision(Object& object) = 0;

    virtual void handleCollision(Pacman& pacman) = 0;

    virtual void handleCollision(Demon& demon)   = 0;

    virtual void handleCollision(Cookie& cookie) {}

    virtual void handleCollision(Door& door) {}

    virtual void handleCollision(Gift& gift) {}

    virtual void handleCollision(Key& key) {}

    virtual void handleCollision(Wall& wall) {}

    bool getDelete() const;

    void setDelete();

protected:
    sf::Rect<float> getGlobalBounds() const;

private:
        bool m_isDelete = false;

};