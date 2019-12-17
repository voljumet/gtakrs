#include "InputManager.h"

/// This class is used for inputs,
/// if mouse clicked in the menu,
/// controlls for player can be placed here too

namespace GTA{
    bool InputManager::IsSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow &window){       /// Mouse clicked ....
        if (sf::Mouse::isButtonPressed(button)){
            sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

            if(tempRect.contains(sf::Mouse::getPosition(window))){
                return true;
            }
        }
        return false;
    }

    sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window){      /// Get mouse position
        return sf::Mouse::getPosition(window);
    }
}