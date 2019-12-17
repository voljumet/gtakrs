#include "Weapon.h"

namespace GTA{
    void Weapon::Gun_init() {

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

    void Weapon::setGunPosX(float gunPosX) { gun_posX = gunPosX; }
    void Weapon::setGunPosY(float gunPosY) { gun_posY = gunPosY; }
    void Weapon::setGun(const sf::Sprite &gun) { Weapon::gun = gun; }
    void Weapon::setShotgunPosX(float shotgunPosX) { shotgun_posX = shotgunPosX; }
    void Weapon::setShotgunPosY(float shotgunPosY) { shotgun_posY = shotgunPosY; }
    void Weapon::setShotgun(const sf::Sprite &shotgun) { Weapon::shotgun = shotgun; }
    void Weapon::setHasweapon(bool hasweapon) { Weapon::hasweapon = hasweapon; }
    void Weapon::setShotammo(int shotammo) { Weapon::shotammo = shotammo; }
    void Weapon::setHasshotgun(bool hasshotgun) { Weapon::hasshotgun = hasshotgun; }
    void Weapon::setGunammo(int gunammo) { Weapon::gunammo = gunammo ; }

    sf::Sprite &Weapon::getGun()  { return gun; }
    sf::Sprite &Weapon::getShotgun()  { return shotgun; }

    float Weapon::getGunPosX() const { return gun_posX; }
    float Weapon::getGunPosY() const { return gun_posY; }
    float Weapon::getShotgunPosX() const { return shotgun_posX; }
    float Weapon::getShotgunPosY() const { return shotgun_posY; }

    int Weapon::getShotammo() const { return shotammo; }
    int Weapon::getGunammo() const { return gunammo; }

    bool Weapon::isHasweapon() const { return hasweapon; }
    bool Weapon::isHasshotgun() const { return hasshotgun; }
}
