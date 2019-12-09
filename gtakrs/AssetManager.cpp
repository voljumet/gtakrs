#include "AssetManager.h"

/// Klasse for å laste inn bilder og teksturer

namespace GTA {
    void
    AssetManager::LoadTexture(const std::string &name, const std::string &fileName) {      /// Load Texture function
        sf::Texture tex;

        if (tex.loadFromFile(fileName)) {
            this->_textures[name] = tex;
        }
    }

    sf::Texture &AssetManager::GetTexture(const std::string &name) {             /// Use Texture function
        return this->_textures.at(name);
    }

    void AssetManager::LoadFont(const std::string &name, const std::string &fileName) {      /// Load Font function
        sf::Font font;

        if (font.loadFromFile(fileName)) {
            this->_fonts[name] = font;
        }
    }

    sf::Font &AssetManager::GetFont(const std::string &name) {        /// Use Font function
        return this->_fonts.at(name);
    }

    void AssetManager::LoadSound(const std::string &name, const sf::Sound &fileName) {
        sf::Sound sound;

        this->_sounds[name] = sound;

    }

    sf::Sound &AssetManager::GetSound(const std::string &name) {
        return this->_sounds.at(name);
    }

    void AssetManager::PlaySound(const sf::Sound sound) {  ///Takes in a sf::Sound object and plays it
        sounds.push_back(sound);
        sounds.back().play();
    }






    sf::Sound AssetManager::loadhorn() {
        bufferhorn.loadFromFile(AIRHORN_FILEPATH);
        soundhorn.setBuffer(bufferhorn);
        return soundhorn;
    }

    sf::Sound AssetManager::loadgunshot() {
        buffergunshot.loadFromFile(GUNHSOT_FILEPATH);
        gunshot.setBuffer(buffergunshot);
        return gunshot;
    }

    sf::Sound AssetManager::loadfootstep() {
        bufferfootstep.loadFromFile(FOOTSTEP_FILEPATH);
        footstep.setBuffer(bufferfootstep);
        return footstep;
    }

    sf::Sound AssetManager::loadcardoor() {
        buffercardoor.loadFromFile(CARDOOR_FILEPATH);
        cardoor.setBuffer(buffercardoor);
        return cardoor;
    }
    sf::Sound AssetManager::loadbuttonpress() {
        bufferbutton.loadFromFile(BUTTONPRESS);
        button.setBuffer(bufferbutton);
        return button;
    }

    sf::Sound AssetManager::loadcarcrash(){
        buffercrash.loadFromFile(CARCRASH);
        carcrash.setBuffer(buffercrash);
        return carcrash;
    }

    sf::Sound AssetManager::loadcardeath() {
        buffercardeath.loadFromFile(CARDEATH);
        cardeath.setBuffer(buffercardeath);
        return cardeath;

    }

    void AssetManager::loadall() {
        loadhorn();
        loadgunshot();
        loadfootstep();
        loadcardoor();
        loadbuttonpress();
        loadcarcrash();
        loadcardeath();

        loadsong();
        loadcomputer();
    }

    void AssetManager::loadsong() {
        song.openFromFile(SONG);
    }

    void AssetManager::playsong() {
        song.play();
    }

    void AssetManager::loadcomputer() {
        computersounds.openFromFile(COMPUTERSOUNDS);
        computersounds.setVolume(10);
    }

    void AssetManager::playcomputer() {
        computersounds.play();
    }
}
