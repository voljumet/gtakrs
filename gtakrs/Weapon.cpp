#include "Weapon.h"

void GTA::Weapon::Gun_init() {

    gunTexture.loadFromFile(GLOCK);
    gun.setTexture(gunTexture);

    gun.setPosition(gun_posX, gun_posY);
    gun.setScale(0.07, 0.07);

    hasweapon = false;



}

void GTA::Weapon::Gun_randompos() {



}