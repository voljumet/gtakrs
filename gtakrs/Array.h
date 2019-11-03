#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>

namespace GTA {

class Array : public sf::Drawable, public sf::Transformable, public sf::Texture {
    public:


    private:

        sf::VertexArray m_vertices;
        sf::Texture m_tileset;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
            /// apply the transform
            states.transform *= getTransform();

            /// apply the tileset texture
            states.texture = &m_tileset;

            /// draw the vertex array
            target.draw(m_vertices, states);
        }

    };

}