#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"

namespace GTA{
    class WorldState : public  State{
    public:
        double x = (SCREEN_HEIGHT/2);
        double y = (SCREEN_WIDTH/2);
        explicit WorldState(GameDataRef data);

        void Init() override;

        void HandleInput() override;
        void Update(float dt) override;
        void Draw( float dt) override;

    private:
        GameDataRef _data;

        sf::Sprite _background;

        sf::Sprite _player;
    };
}