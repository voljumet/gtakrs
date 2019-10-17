#include "InputManager.h"

/// Denne klassen blir brukt til inputs,
/// hvis man klikker med musen i menyen,
/// her bør også piltaster plasseres for å kontrollere karakteren

namespace GTA{
    bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window){
        if (sf::Mouse::isButtonPressed(button)){
            sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

            if(tempRect.contains(sf::Mouse::getPosition(window))){
                return true;
            }
        }
        return false;
    }

    sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window){
        return sf::Mouse::getPosition(window);
    }
}