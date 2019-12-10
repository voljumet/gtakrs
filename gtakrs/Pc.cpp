
#include "Pc.h"

void Pc::spawnPc() {
    pcTexture.loadFromFile(CRT_SCREEN);
    pc.setTexture(pcTexture);
    pc.setPosition(pcPox, pcPoy);
    pc.setScale(0.09, 0.09);

    hasPc = false;
}

sf::Sprite &Pc::getPc(){
    return pc;
}

float Pc::getPcPox() const {
    return pcPox;
}

float Pc::getPcPoy() const {
    return pcPoy;
}
