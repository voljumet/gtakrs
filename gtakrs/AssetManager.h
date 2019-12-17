#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <list>
#include"DEFINITIONS.h"

namespace GTA{
    class AssetManager{
    public:
        std::list<sf::Sound> sounds;
        sf::SoundBuffer bufferhorn, buffergunshot, bufferfootstep, buffercardoor,
        bufferbutton, buffercrash, buffercardeath, bufferempty, bufferspas, buffertesla;

        sf::Sound soundhorn, gunshot, footstep, cardoor, button, carcrash, cardeath, empty, spas, tesla;
        sf::Music song;
        sf::Music computersounds;

        void loadsong();
        void loadcomputer();
        void playcomputer();

        sf::Sound loadhorn();
        sf::Sound loadgunshot();
        sf::Sound loadfootstep();
        sf::Sound loadcardoor();
        sf::Sound loadbuttonpress();
        sf::Sound loadcarcrash();
        sf::Sound loadcardeath();
        sf::Sound loadempty();
        sf::Sound loadspas();
        sf::Sound loadtesla();

        void loadall();

        AssetManager()= default;
        ~AssetManager()= default;

        void LoadTexture( const std::string& name, const std::string& fileName);
        void LoadFont( const std::string& name, const std::string& fileName);
        void PlaySound(sf::Sound);

        sf::Texture &GetTexture(const std::string& name);
        sf::Font &GetFont(const std::string& name);

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}
