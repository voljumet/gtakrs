#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"


namespace GTA{
    class Hacking : public State {

        GameDataRef _data;
        sf::View view;

        sf::Sprite _background;
        sf::Text text, playertext;
        std::string playerinput;
        sf::Font font;

        AssetManager hackaudio;

        float posX, posY, size;
        bool correctpassword;
        int layer;

    public:
        explicit Hacking(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
        void UpdateView(const float &dt);
    };
}



