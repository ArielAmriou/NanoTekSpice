/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** NanoTekSpice
*/

#ifndef ICOMPONENT_HPP
    #define ICOMPONENT_HPP

    #include "NanoTekSpice.hpp"
    #include "NtsException.hpp"
    #include "Tristate.hpp"

namespace nts {

    class Pin;

    enum class Mode {
        OutputMode,
        InputMode
    };
    class IComponent {
        public :
            virtual ~IComponent() noexcept = default;
            virtual void simulate(std::size_t tick) noexcept = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin,
                nts::IComponent &other, std::size_t otherPin) = 0;
            virtual nts::Mode getPinMode(std::size_t pin) = 0;
            virtual std::string getName() const = 0;
            virtual Pin &getPin(size_t) = 0;
            virtual std::size_t getNbPin() const = 0;
            virtual std::size_t getLastUpdateTick() const = 0;
    };
}

#endif
