#include <iostream>
#include <SFML/Graphics.hpp>

#include "Cabecalhos/Geral.hpp"
#include "Cabecalhos/Pinguim.hpp"
#include "Cabecalhos/OrganizadorObstaculos.hpp"

int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({MAPA_LARGURA,MAPA_ALTURA}), "Pinguim_Pinguim");
	window->setFramerateLimit(60);

	unsigned int level_nivel = 0;

    Pinguim p;
    OrganizadorObstaculos OrgObs(level_nivel);
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

		// Verifica se passou de fase
		if(p.get_eixo_y() <= 0){
			// incrementa a fase
			level_nivel++;
			OrgObs.generate_level(level_nivel);
			p.reset_ping_pos();
		}


		//Render
		window->clear(sf::Color(0, 0, 148)); // Azul

		//Drawing
        OrgObs.desenhar(*window);
        p.desenhar(*window);

		window->display();
	}
	delete window;
	return 0;
}