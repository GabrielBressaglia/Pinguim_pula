#include <iostream>
#include <SFML/Graphics.hpp>

#include "Cabecalhos/Geral.hpp"
#include "Cabecalhos/Pinguim.hpp"
#include "Cabecalhos/OrganizadorObstaculos.hpp"

int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({MAPA_LARGURA,MAPA_ALTURA}), "Pinguim_Pinguim");
	window->setFramerateLimit(60);

    Pinguim p;
    OrganizadorObstaculos OrgObs(0);
    // Loop principal
	while (window->isOpen()) {

		while (const std::optional event = window->pollEvent()) {

			if (event->is<sf::Event::Closed>()) {

				window->close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {

				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {

					window->close();
				}
			}
		}
        
        p.handleInput();
        OrgObs.atualizarPosicao(p);

		//Render
		window->clear(sf::Color(0, 0, 255)); // Azul

		//Drawing
        OrgObs.desenhar(*window);
        p.desenhar(*window);

		window->display();
	}
	delete window;
	return 0;
}