#include "Weapon.h"

void Weapon::Gun_init() {

    gunTexture.loadFromFile(GLOCK);
    gun.setTexture(gunTexture);

    gun.setPosition(gun_posX, gun_posY);
    gun.setScale(0.07, 0.07);



}

void Weapon::Gun_randompos() {


}