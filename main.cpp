#include <iostream>
#include <SFML/Graphics.hpp>

#include "Cabecalhos/Geral.hpp"

enum directions { down, right, up, left };
int main() {
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({MAPA_LARGURA,MAPA_ALTURA}), "Tutorials");
	window->setFramerateLimit(60);

    // Posicao personagem
    float X = MAPA_LARGURA / 2.f;
    float Y = MAPA_ALTURA/ 1.0f - 10.0f;
    unsigned direcao;

    // Textura e Sprite
	sf::Texture texture;
	if (!texture.loadFromFile("Sprites/ExampleSprite.png")) {
		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/ExampleSprite.png" << std::endl;
		return -1;
	}
	sf::Sprite sprite(texture);
	sf::IntRect dir[4];
	for (int i = 0; i < 4; ++i) {

		dir[i] = sf::IntRect({ {32 * i, 0}, {32,32} });
	}
	sprite.setTextureRect(dir[down]);
	sprite.setOrigin({ 16,16 });
    sprite.setPosition({X,Y});
	sprite.setColor(sf::Color(0x6495EDFF));

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

        // Controle jogador
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) {
            X += 0;
            Y += 2;
			sprite.setTextureRect(dir[down]);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
            X += 0;
            Y -= 2;
			sprite.setTextureRect(dir[up]);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) {
            X += 2;
            Y += 0;
			sprite.setTextureRect(dir[right]);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) {
            X -= 2;
            Y += 0;
			sprite.setTextureRect(dir[left]);
		}
        sprite.setPosition({X,Y});

		//Render
		window->clear();

		//Drawing
		window->draw(sprite);

		window->display();
	}
	delete window;
	return 0;
}