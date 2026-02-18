/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <map>
#include <string>
#include <memory>
#include "Tristate.hpp"
#include "IComponent.hpp"

namespace nts {

    using ComponentMap = std::map<std::string, std::pair<
        std::unique_ptr<nts::IComponent>, std::string>>;

    class Utils {
        public:
            static std::unique_ptr<nts::IComponent> &getComponent(ComponentMap &, std::string);
            static Tristate halfAdder(const Tristate a,
                const Tristate b, Tristate &carry);
    };
}

#endif /* !UTILS_HPP_ */
