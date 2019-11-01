

#include <SFML/Audio.hpp>


class Audio {

public:

     sf::SoundBuffer bufferhorn, buffergunshot, bufferfootstep, buffercardoor;
    //soundbuffer er en buffer som må laste lyder inn i minnet før det kan brukes

     sf::Sound soundhorn, gunshot, footstep, cardoor;
    //Sound er den faktiske lyden som gjør ting

    sf::Music song;

    void loadsong();

    void playsong();


      sf::Sound loadhorn();
      sf::Sound loadgunshot();
      sf::Sound loadfootstep();
      sf::Sound loadcardoor();

      void loadall();

    //laster inn lydeffekt fra minnet og returnerer det
    // bør lastes inn i begynnelsen når spillet starter oppp slik at den er klar



    // spiller av lydeffekten
     void playhorn();
     void playgunshot();
     void playfootsteps();
     void playcardoor();


};



