/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** NanoTekSpice
*/

#ifndef ICOMPONENT_HPP
    #define ICOMPONENT_HPP

    #include <SFML/Graphics.hpp>
    #include "NtsException.hpp"
    #include "Tristate.hpp"

namespace nts {

    class Pin;

    enum class Mode {
        OutputMode,
        InputMode,
        UnusedMode,
        DualMode,
    };

    class IComponent {
        public :
            virtual ~IComponent() noexcept = default;
            virtual void simulate(std::size_t tick) noexcept = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin,
                nts::IComponent &other, std::size_t otherPin) = 0;
            virtual Pin &getPin(size_t) = 0;

            // Sfml
            virtual Pin &getNPin(size_t n) = 0;
            virtual sf::Vector2f getNPinPos(size_t n) = 0;
            virtual void setPos(sf::Vector2f pos) = 0;
            virtual sf::Vector2f getPos() const = 0;
            virtual sf::RectangleShape &getChipset() = 0;
            virtual sf::Vector2f getSize() = 0;

            virtual void draw(sf::RenderWindow &window) = 0;
    };
}

#endif
