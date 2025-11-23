#include <iostream>
#include <SFML/Graphics.hpp>

#include "Unidade_Jogo/Geral.hpp"
#include "Unidade_Jogo/Pinguim.hpp"
#include "Unidade_Jogo/OrganizadorObstaculos.hpp"
#include "Unidade_Jogo/DesenharInventario.hpp"
#include "Estrutura_De_Dados/ListaEncadeada.hpp"

int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({MAPA_LARGURA,MAPA_ALTURA}), "Pinguim_Pinguim");
	window->setFramerateLimit(60);

	unsigned int level_nivel = 0;

	ListaEncadeada list;

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
        
        p.Controle_Update();
        OrgObs.atualizarPosicao(p, list);

		// Verifica se passou de fase
		if(p.get_eixo_y() <= 0){
			// incrementa a fase
			level_nivel++;
			OrgObs.generate_level(level_nivel);
			p.reset_ping_pos();
		}
		// Caso morra, reseta o nivel
		if(p.get_dead() == 1){
			level_nivel = 0;
			OrgObs.generate_level(level_nivel);
			list.deleta();
		}


		//Render
		window->clear(sf::Color(0, 0, 148)); // Azul

		//Drawing
		Desenhar_inventario(*window, list);
        OrgObs.desenhar(*window);
        p.desenhar(*window);

		window->display();
	}
	delete window;
	return 0;
}