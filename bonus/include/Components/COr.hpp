/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentCOr
*/

#ifndef COMPONENTCOR_HPP_
#define COMPONENTCOR_HPP_

#include "ABasicComponent.hpp"

namespace nts {
    class COr: public ABasicComponent {
        public:
            COr(sf::Vector2f pos, sf::Font &font, const std::string &name);
            ~COr() = default;
        private:
            void simulateComponent() override;
    };
}

#endif /* !COMPONENTCOR_HPP_ */
