/*
** EPITECH PROJECT, 2026
** NanoTekSpice
** File description:
** Sfml
*/

#ifndef SFMLHPP
    #define SFMLHPP

#include <SFML/Graphics.hpp>
#include "Event.hpp"
#include "Utils.hpp"
#include "RightToolBar.hpp"
#include "Variables.hpp"
#include "ChangeState.hpp"
#include "SimulateToolBar.hpp"
#include "Map.hpp"
#include "QuitScreen.hpp"

namespace nts
{
    constexpr int EPISUCCESS = 0;
    constexpr int EPIERROR = 84;

    class Sfml {
        public:
            Sfml(sf::Font &font, std::string filename);
            ~Sfml() {};

            void run();

            ComponentMap &getMap() {return _components;}

        private:
            void drawComponents(ComponentMap &components);
            void drawChangeState();
            void handleResize(sf::Event event, sf::RenderWindow &window);
            sf::RenderWindow _window;
            ComponentMap _components;
            Variables _variables;
            Event _event;
            std::vector<std::function<void (sf::Event, sf::RenderWindow &)>> _otherEvents;
            sf::VertexArray _line;
            RightToolBar _rightToolBar;
            ChangeState _changeState;
            SimulateToolBar _simulateToolBar;
            sf::View _gameView;
            sf::RectangleShape _background;
            Map _map;
            QuitScreen _quitScreen;
    };
}

#endif