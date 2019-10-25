//
// Created by Peshang Alo on 24/10/2019.
//

#ifndef CAR_COLLIDER_H
#define CAR_COLLIDER_H

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <cmath>

class Collider {
public:
    Collider(sf::RectangleShape &body);

    ~Collider();


    void Move (float dx, float dy) const {body.move(dx , dy);}
    bool Check_Collision( const Collider & other, float push);
    sf::Vector2f GetPosition () const { return body.getPosition();}
    sf::Vector2f GetHalfSize() const { return body.getSize() / 2.0f;}


private:
    sf::RectangleShape& body;

};


#endif //CAR_COLLIDER_H
