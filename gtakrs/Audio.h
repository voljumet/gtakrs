#pragma once
#include <SFML/Audio.hpp>
#include "Game.h"

namespace GTA {
    class Audio {
    public:

        sf::SoundBuffer bufferhorn, buffergunshot, bufferfootstep, buffercardoor, bufferbutton;
        //soundbuffer er en buffer som må laste lyder inn i minnet før det kan brukes

        sf::Sound soundhorn, gunshot, footstep, cardoor, button;
        //Sound er den faktiske lyden som gjør ting

        sf::Music song;
        sf::Music computersounds;

        void loadsong();

        void playsong();

        void loadcomputer();

        void playcomputer();




        sf::Sound loadhorn();

        sf::Sound loadgunshot();

        sf::Sound loadfootstep();

        sf::Sound loadcardoor();

        sf::Sound loadbuttonpress();

        void loadall();

        //laster inn lydeffekt fra minnet og returnerer det
        // bør lastes inn i begynnelsen når spillet starter oppp slik at den er klar

        // spiller av lydeffekten
        void playhorn();

        void playgunshot();

        void playfootsteps();


        void playcardoor();

        void playbuttonpress();
    private:
        GameDataRef _data;


    };

}

