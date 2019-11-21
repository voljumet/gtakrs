#include "Collision_Detection.h"
#include "colliderTest.h"

namespace GTA {


    void GTA::Collision_Detection::Check_Collision(sf::Sprite &sprite1, sf::Sprite &sprite2, bool move) {

        while (GTA::PixelPerfectTest(sprite1, sprite2)) {
            float carposx = sprite1.getPosition().x;
            float carposy = sprite1.getPosition().y;
            float car2posx = sprite2.getPosition().x;
            float car2posy = sprite2.getPosition().y;
            if (move) {

                sprite1.setPosition(carposx + dx / 100.0, carposy + dy / 100.0);
                sprite2.setPosition(car2posx - dx / 100.0, car2posy - dy / 100.0);
            } else {
                sprite1.setPosition(carposx + dx / 100.0, carposy + dy / 100.0);

            }
            dx = carposx - car2posx;
            dy = carposy - car2posy;


            if (!GTA::PixelPerfectTest(sprite1, sprite2)) break;
        }
    }
}