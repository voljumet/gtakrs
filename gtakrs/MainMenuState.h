#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace GTA{
    class MainMenuState : public State{

    public:
        explicit MainMenuState(GameDataRef data);

        void Init() override;

        void HandleInput() override;
        void Update(float dt) override;
        void Draw(float dt) override;
        void UpdateView(const float &dt);

    private:
        GameDataRef _data;
        sf::View view;

        sf::Sprite _playButton;

        sf::Sprite _resumeButton;
        sf::Sprite _exitButton;

        sf::Sprite _title;
    };
}