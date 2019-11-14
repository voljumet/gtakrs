#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace GTA{
    class AssetManager{
    public:
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
