#include <iostream>
#include <SFML/Graphics.hpp>

#include "Unidade_Jogo/Geral.hpp"
#include "Unidade_Jogo/Pinguim.hpp"
#include "Unidade_Jogo/OrganizadorObstaculos.hpp"
#include "Unidade_Jogo/DesenharInventario.hpp"
#include "Estrutura_De_Dados/ListaEncadeada.hpp"
#include "Estrutura_De_Dados/FilaEncadeada.hpp"

bool InicioJogo = false;

int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({MAPA_LARGURA,MAPA_ALTURA}), "Pinguim_Pinguim");
	window->setFramerateLimit(60);

	unsigned int level_nivel = 0;

	ListaEncadeada list;
	Fila fila;
	bool ok;
	// Adiciona o pinguim principal para a lista
	fila.adicionar('I', ok);
	if(!ok)
		exit(1);

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
		// Verifica se o jogador comecou o jogo
        if(InicioJogo == false){
			InicioJogo = Desenhar_tela_inicial(*window);
			window->display();
		}
		// Se o jogador comecar o jogo
		// Inicia-se a fase
		else{
			p.Controle_Update();

			OrgObs.atualizarPosicao(p, list, fila);
			p.set_ping_type(fila.frente(ok));

			// Verifica se passou de fase
			if(p.get_eixo_y() <= 0){
				// incrementa a fase
				level_nivel++;
				OrgObs.generate_level(level_nivel);
				p.reset_ping_pos();
			}
			// Caso morra, reseta o nivel
			if(p.get_dead() == 1 && fila.vazia()){
				level_nivel = 0;
				OrgObs.generate_level(level_nivel);
				list.deleta();
				fila.adicionar('I', ok);
				if(!ok)
					exit(1);	
				InicioJogo = false;			
			}

			//Render
			window->clear(sf::Color(0, 0, 140)); // Azul

			//Drawing
			Desenhar_inventario(*window, list);
			OrgObs.desenhar(*window);
			// Para de desenhar quando o pinguim morre
			if(!p.get_dead())
				p.desenhar(*window);

			window->display();
		}
	}
	delete window;
	return 0;
}