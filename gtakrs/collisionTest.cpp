//
// Created by Peshang Alo on 24/10/2019.
//



#include "collisionTest.h"

// Initializer
Collider::Collider(sf::RectangleShape& body) :
//Member variable name;
        body(body)
{
}
Collider::~Collider() {

}

bool Collider::Check_Collision(const Collider& other, float push) {
    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();

    //By using deltaX / Y can this two shape detected from any side.
    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    /// Intersect calculation
    float IntersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float IntersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);


    /// Collision Detection
    if (IntersectX < 0.0f && IntersectY < 0.0f)
    {
        //Clamping process (Limit the push variable between 0 and 1)
        push = std::min(std::max(push, 0.0f),1.0f);

        if(IntersectX > IntersectY)
        {
            if(deltaX > 0.0f)
            {
                Move(IntersectX * (1.0f -  push), 0.0f);
                other.Move(-IntersectX * push, 0.0f);
            } else
            {

                Move(-IntersectX * (1.0f -push),0.0f);
                other.Move(IntersectX * push,0.0f);
            }
        } else
        {

            if(deltaY > 0.0f)
            {
                Move(0.0f,IntersectY * (1.0f -push));
                other.Move(0.0f,-IntersectY * push);
            } else
            {

                Move(0.0f,-IntersectY * (1.0f -push));
                other.Move(0.0f,IntersectY * push);
            }
        }

        return  true;}

    return false;
}
