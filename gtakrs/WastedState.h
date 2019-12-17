#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace GTA{
    class WastedState : public  State{
        GameDataRef _data;
        sf::View view;
        sf::Clock _clock;
        sf::Sprite _background;

    public:
        explicit WastedState(GameDataRef data);

        void Init() override;

        void HandleInput() override;
        void Update(float dt) override;
        void Draw( float dt) override;
        void UpdateView(const float &dt);
    };
}