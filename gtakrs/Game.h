#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace GTA{
    struct    GameData{
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game{
    public:
        Game(int width, int height, const std::string& title);

        sf::Clock _clock;
        friend class WorldState;

        /// NØDVENDIG ? ???? ?
        friend class Map;
        /// _______________________

    private:
        const float dt = 1.0f / 60.0f;      ///<----------- FPS

        GameDataRef _data = std::make_shared<GameData>();

        void Run();
    };
}