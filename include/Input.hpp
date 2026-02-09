/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** ComponentInput
*/

#ifndef COMPONENTINPUT_HPP_
#define COMPONENTINPUT_HPP_

#include "AComponent.hpp"

constexpr std::vector<std::pair<std::optional<nts::IComponent &>, nts::Mode>> DEFAULT = {
    {{}, nts::Output}
};

namespace nts {
    class Input: public AComponent {
        public:
            Input();
    };
}

#endif /* !COMPONENTINPUT_HPP_ */
