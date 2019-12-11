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

float GTA::Weapon::getGunPosX() const {
    return gun_posX;
}

void GTA::Weapon::setGunPosX(float gunPosX) {
    gun_posX = gunPosX;
}

float GTA::Weapon::getGunPosY() const {
    return gun_posY;
}

void GTA::Weapon::setGunPosY(float gunPosY) {
    gun_posY = gunPosY;
}

 sf::Sprite &GTA::Weapon::getGun()  {
    return gun;
}

void GTA::Weapon::setGun(const sf::Sprite &gun) {
    Weapon::gun = gun;
}

float GTA::Weapon::getShotgunPosX() const {
    return shotgun_posX;
}

void GTA::Weapon::setShotgunPosX(float shotgunPosX) {
    shotgun_posX = shotgunPosX;
}

float GTA::Weapon::getShotgunPosY() const {
    return shotgun_posY;
}

void GTA::Weapon::setShotgunPosY(float shotgunPosY) {
    shotgun_posY = shotgunPosY;
}

 sf::Sprite &GTA::Weapon::getShotgun()  {
    return shotgun;
}

void GTA::Weapon::setShotgun(const sf::Sprite &shotgun) {
    Weapon::shotgun = shotgun;
}

bool GTA::Weapon::isHasweapon() const {
    return hasweapon;
}

void GTA::Weapon::setHasweapon(bool hasweapon) {
    Weapon::hasweapon = hasweapon;
}

int GTA::Weapon::getShotammo() const {
    return shotammo;
}

void GTA::Weapon::setShotammo(int shotammo) {
    Weapon::shotammo = shotammo;
}

int GTA::Weapon::getGunammo() const {
    return gunammo;
}

void GTA::Weapon::setGunammo(int gunammo) {
    Weapon::gunammo = gunammo ;
}


bool GTA::Weapon::isHasshotgun() const {
    return hasshotgun;
}

void GTA::Weapon::setHasshotgun(bool hasshotgun) {
    Weapon::hasshotgun = hasshotgun;
}
