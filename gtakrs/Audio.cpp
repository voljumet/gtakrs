#include <iostream>
#include "DEFINITIONS.h"
#include "Audio.h"

///dank airhorn som en begynnelse
sf::Sound Audio::loadhorn(){
    bufferhorn.loadFromFile(AIRHORN_FILEPATH);
    soundhorn.setBuffer(bufferhorn);
    return soundhorn;
}


sf::Sound Audio::loadgunshot() {
    buffergunshot.loadFromFile(GUNHSOT_FILEPATH);
    gunshot.setBuffer(buffergunshot);
    return gunshot;
}

sf::Sound Audio::loadfootstep() {
    bufferfootstep.loadFromFile(GUNHSOT_FILEPATH);
    footstep.setBuffer(bufferfootstep);
    return footstep;
}

sf::Sound Audio::loadcardoor() {
    buffercardoor.loadFromFile(CARDOOR_FILEPATH);
    cardoor.setBuffer(buffercardoor);
    return cardoor;
}



void Audio::loadall() {
    loadhorn();
    loadgunshot();
    loadfootstep();
    loadcardoor();
    loadsong();

}


void Audio::playhorn() {
    soundhorn.play();
}

void Audio::playgunshot() {
    gunshot.play();
}

void Audio::playfootsteps() {
    footstep.play();
}

void Audio::playcardoor() {
    cardoor.play();
}


void Audio::loadsong() {
    song.openFromFile(SONG);
}

void Audio::playsong() {
    song.play();
}

//når man skal bruke audio måman først lage en instans av audio, så kan man loade en lyd med load functionen
//så spiller man lyden men play functionen
//etterhvert kan man samle alle load functionene i en slik at det ser bedre ut




