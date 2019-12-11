
#include "objectSpawn.h"

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

bool objectSpawn::isHasPc() const {return hasPc;}
bool objectSpawn::isHasBurger() const {return hasBurger;}
bool objectSpawn::isHasSniper() const {return hasSniper;}



