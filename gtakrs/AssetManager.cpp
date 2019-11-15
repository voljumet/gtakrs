#include "AssetManager.h"

/// Klasse for å laste inn bilder og teksturer

namespace GTA{
    void AssetManager::LoadTexture(const std::string& name, const std::string& fileName) {      /// Load Texture function
        sf::Texture tex;

        if (tex.loadFromFile(fileName)){
            this->_textures[name] = tex;
        }
    }
    sf::Texture &AssetManager::GetTexture(const std::string& name) {             /// Use Texture function
        return this->_textures.at(name);
    }

    void AssetManager::LoadFont(const std::string& name, const std::string& fileName) {      /// Load Font function
        sf::Font font;

        if (font.loadFromFile(fileName)){
            this->_fonts[name] = font;
        }
    }
    sf::Font &AssetManager::GetFont(const std::string& name) {        /// Use Font function
        return this->_fonts.at(name);
    }

    void AssetManager::LoadSound(const std::string &name, const std::string &fileName) {
        sf::SoundBuffer sound;

        if (sound.loadFromFile(fileName)){
            this->_sounds[name] = sound;
        }
    }
    sf::SoundBuffer &AssetManager::GetSound(const std::string &name) {
        return this->_sounds.at(name);
    }
}