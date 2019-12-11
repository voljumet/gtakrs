#include "Weapon.h"

void GTA::Weapon::Gun_init() {

    gunTexture.loadFromFile(GLOCK);
    gun.setTexture(gunTexture);

    gun.setPosition(gun_posX, gun_posY);
    gun.setScale(0.07, 0.07);

    shotgunTexture.loadFromFile(SHOTGUN);
    shotgun.setTexture(shotgunTexture);

    shotgun.setPosition(shotgun_posX, shotgun_posY);
    shotgun.setScale(0.25, 0.25);


    hasweapon = false;
    hasshotgun = false;

}

void GTA::Weapon::Gun_randompos() {



}