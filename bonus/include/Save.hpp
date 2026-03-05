/*
** EPITECH PROJECT, 2026
** bonus
** File description:
** Save
*/

#ifndef SAVEHPP
    #define SAVEHPP

    #include "Utils.hpp"
    #include "Variables.hpp"

namespace nts {
    class Save {
        public:
            static void run(ComponentMap &components, std::string name, Variables &_variables);
        private:
            static std::vector<std::size_t> initCounter(ComponentMap &components);
            static std::size_t findId(std::string, std::vector<std::size_t> &);
            static std::string findLinkName(ComponentMap &components, std::vector<std::size_t> id, std::reference_wrapper<IComponent>);
    };
}


#endif