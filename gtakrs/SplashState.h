#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace GTA{
    class SplashState : public  State{
    public:
        explicit SplashState(GameDataRef data);

        void Init() override;

        void HandleInput() override;
        void Update(float dt) override;
        void Draw( float dt) override;

    private:
        GameDataRef _data;
        sf::Clock _clock;
        sf::Sprite _background;
    };
}