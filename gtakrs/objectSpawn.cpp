
#include "objectSpawn.h"
namespace GTA{
    void objectSpawn::spawnPc() {
        pcTexture.loadFromFile(CRT_SCREEN);
        pc.setTexture(pcTexture);
        pc.setPosition(pcPox, pcPoy);
        pc.setScale(0.09, 0.09);
        hasPc = false;
    }

    void objectSpawn::spawnBurger() {
        burgerTexture.loadFromFile(SNIPER);
        burger.setTexture(burgerTexture);
        burger.setPosition(burgerPox, burgerPoy);
        burger.setScale(0.09, 0.09);
        hasBurger = false;
    }

    void objectSpawn::spawnSniper() {
        sniperTexture.loadFromFile(BURGER);
        sniper.setTexture(sniperTexture);
        sniper.setPosition(sniperPox, sniperPoy);
        sniper.setScale(0.09, 0.09);
        hasSniper = false;
    }


    sf::Sprite &objectSpawn::getPc(){return pc;}
    sf::Sprite &objectSpawn::getBurger() {return burger;}
    sf::Sprite &objectSpawn::getSniper() {return sniper;}

    float objectSpawn::getBurgerPox() {return burgerPox;}
    float objectSpawn::getBurgerPoy() {return burgerPoy;}
    float objectSpawn::getSniperPox() {return sniperPox;}
    float objectSpawn::getSniperPoy() {return sniperPoy;}
    float objectSpawn::getPcPox() {return pcPox;}
    float objectSpawn::getPcPoy() {return pcPoy;}

    void objectSpawn::setHasPc(bool hasPc) {objectSpawn::hasPc = hasPc;}
    void objectSpawn::setHasBurger(bool hasBurger) {objectSpawn::hasBurger = hasBurger;}
    void objectSpawn::setHasSniper(bool hasSniper) {objectSpawn::hasSniper = hasSniper;}
    void objectSpawn::setSniperPox(float sniperPox) {objectSpawn::sniperPox = sniperPox;}
    void objectSpawn::setSniperPoy(float sniperPoy) {objectSpawn::sniperPoy = sniperPoy;}
    void objectSpawn::setBurgerPox(float burgerPox) {objectSpawn::burgerPox = burgerPox;}
    void objectSpawn::setBurgerPoy(float burgerPoy) {objectSpawn::burgerPoy = burgerPoy;}
    void objectSpawn::setPcPoy(float pcPoy) {objectSpawn::pcPoy = pcPoy;}
    void objectSpawn::setPcPox(float pcPox) {objectSpawn::pcPox = pcPox;}
}
