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
        sf::SoundBuffer bufferhorn, buffergunshot, bufferfootstep, buffercardoor, bufferbutton, buffercrash, buffercardeath, bufferempty, bufferspas;

        sf::Sound soundhorn, gunshot, footstep, cardoor, button, carcrash, cardeath, empty, spas;

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
        sf::Sound loadcarcrash();
        sf::Sound loadcardeath();
        sf::Sound loadempty();
        sf::Sound loadspas();

        void loadall();

        AssetManager()= default;
        ~AssetManager()= default;

        void LoadTexture( const std::string& name, const std::string& fileName);
        sf::Texture &GetTexture(const std::string& name);


        void LoadFont( const std::string& name, const std::string& fileName);
        sf::Font &GetFont(const std::string& name);

        void LoadSound( const std::string& name, const sf::Sound& soundobject);
        sf::Sound &GetSound(const std::string& name);

        void PlaySound(sf::Sound);

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
        std::map<std::string, sf::Sound> _sounds;
    };
}
