#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <cmath>

namespace GTA{


class Collider {
public:
    Collider(sf::Sprite &body);

    ~Collider();


    void Move (float dx, float dy) const {body.move(dx , dy);}
    bool Check_Collision( const Collider & other, float push);
    sf::Vector2f GetPosition () const { return body.getPosition();}
    sf::Vector2f GetHalfSize() const { return body.getScale();}


private:
    sf::Sprite& body;

};

}

