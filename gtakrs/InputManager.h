#pragma once

#include <SFML/Graphics.hpp>

namespace GTA{
    class InputManager{
    public:
        InputManager()= default;
        ~InputManager()= default;

        static bool IsSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow &window);
        static sf::Vector2i GetMousePosition(sf::RenderWindow &window);
    };
}