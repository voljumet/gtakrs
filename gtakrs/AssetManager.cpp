#include "AssetManager.h"

/// Klasse for å laste inn bilder og teksturer

namespace GTA {

    /// Load Texture function
    void AssetManager::LoadTexture(const std::string &name, const std::string &fileName) {
        sf::Texture tex;
        if (tex.loadFromFile(fileName)) { this->_textures[name] = tex; }
    }

    /// Use Texture function
    sf::Texture &AssetManager::GetTexture(const std::string &name) {
        return this->_textures.at(name);
    }

    /// Load Font function
    void AssetManager::LoadFont(const std::string &name, const std::string &fileName) {
        sf::Font font;
        if (font.loadFromFile(fileName)) {
            this->_fonts[name] = font;
        }
    }

    /// Use Font function
    sf::Font &AssetManager::GetFont(const std::string &name) { return this->_fonts.at(name); }

    ///Takes in a sf::Sound object and plays it
    void AssetManager::PlaySound(const sf::Sound sound) {
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

    sf::Sound AssetManager::loadempty() {
        bufferempty.loadFromFile(EMPTY);
        empty.setBuffer(bufferempty);
        empty.setVolume(100);
        return empty;
    }

    sf::Sound AssetManager::loadspas() {
        bufferspas.loadFromFile(SPAS12);
        spas.setBuffer(bufferspas);
        return spas;
    }

    sf::Sound AssetManager::loadtesla() {
        buffertesla.loadFromFile(TESLA);
        tesla.setBuffer(buffertesla);
        return tesla;
    }

    void AssetManager::loadsong() {
        song.openFromFile(SONG);
        song.setLoop(true);
    }

    void AssetManager::loadcomputer() {
        computersounds.openFromFile(COMPUTERSOUNDS);
    }

    void AssetManager::playcomputer() {
        computersounds.play();
    }

    void AssetManager::loadall() {
        loadhorn();
        loadgunshot();
        loadfootstep();
        loadcardoor();
        loadbuttonpress();
        loadcarcrash();
        loadcardeath();
        loadempty();
        loadspas();
        loadtesla();

        loadsong();
        loadcomputer();
    }
}
