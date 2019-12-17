#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace GTA{
    class ControlsState : public State{
        GameDataRef _data;
        sf::View view;

        sf::Sprite _backButton;
        sf::Sprite _background;
        sf::Sprite _logo;

    public:
        explicit ControlsState(GameDataRef data);

        void Init() override;

        void HandleInput() override;
        void Update(float dt) override;
        void Draw(float dt) override;
        void UpdateView(const float &dt);

    };
}