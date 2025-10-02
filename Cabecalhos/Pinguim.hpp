#pragma once
#include <SFML/Graphics.hpp>
#include <array>

#include "Geral.hpp"


// EU PRECISO PENSAR E CRIAR UMA BASE E AS OUTRAS HERDAREM
// MAS FUNCIONA!

enum directions { down, right, up, left };


class Pinguim {
private:
    // Posicao
    float X, Y;
    sf::IntRect direcao;
    // Direcao
    sf::IntRect dir[4];

    // Estado anterior
    std::array<bool, 4> control_keys;

    // Vivo ou Morto
    bool morto;

    // Velocidade eixo X
    float velocidade;
    
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Pinguim()
    : X(MAPA_LARGURA / 2.f),
      Y(MAPA_ALTURA - 1 * CELL_SIZE),
      texture(),          // cria a textura
      sprite(texture),     // inicializa o sprite já ligado à textura
      control_keys{false, false, false, false},
      morto(false),
      velocidade(0)
    {
        if (!texture.loadFromFile("Sprites/pinguim_principal.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/Bill.png" << std::endl;
        }

        for (int i = 0; i < 4; ++i) {
            dir[i] = sf::IntRect({32 * i, 0}, {32, 32}); // O SEGUNDO ARGUMENTO é O TAMNHO
        }

        direcao = dir[down];
        sprite.setTextureRect(direcao);
        sprite.setOrigin({0,0});
        sprite.setPosition({X,Y});
        sprite.setColor(sf::Color(sf::Color::White));
    }
    void handleInput() 
    {
        if(morto == 1){
            X = MAPA_LARGURA / 2.f;
            Y = MAPA_ALTURA - 1 * CELL_SIZE;
            morto = false;
            velocidade = 0;
            return;
        }
        if (0 == control_keys[0] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) {
            X += 0;
            Y += CELL_SIZE;
			direcao = dir[down];
		}
		else if (0 == control_keys[1] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
            X += 0;
            Y -= CELL_SIZE;
			direcao = dir[up];
		}
		else if (0 == control_keys[2] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) {
            X += CELL_SIZE;
            Y += 0;
			direcao = dir[right];
		}
		else if (0 == control_keys[3] && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) {
            X -= CELL_SIZE;
            Y += 0;
			direcao = dir[left];
		}
        // Atualiza o estado anterior
        // Faz com que ele movimente apenas CELULA A CELULA
        control_keys[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S);
		control_keys[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W);
		control_keys[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D);
		control_keys[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A);

        X += velocidade;
        
    }
    void desenhar(sf::RenderWindow& window) 
    {
        sprite.setPosition({X,Y});
        sprite.setTextureRect(direcao);
        window.draw(sprite); // agora desenha o mesmo sprite da classe
    }
    void set_dead()
    {
        morto = true;
    }
    bool get_dead()
    {
        return morto;
    }
    sf::FloatRect get_rect() const
    {
        return sf::FloatRect(
            sf::Vector2f(X, Y),           // posição (float)
            sf::Vector2f(CELL_SIZE, CELL_SIZE)  // tamanho
        );
    }
    // Para saber se passou de fase
    float get_eixo_y() const
    {
        return Y;
    }
    // Para resetar se passar de fase
    void reset_ping_pos()
    {
        X = MAPA_LARGURA / 2.f;
        Y = MAPA_ALTURA - 1 * CELL_SIZE;
        velocidade = 0;
    }

    // Para saber se esta ou nao sobre obstaculo
    void set_velocidade(float vel)
    {
        velocidade = vel;
    }
};

class PinguimColetavel {
private:
    // Tipo
    char tipo;

    // Posicao
    float X, Y;

    // Velocidade eixo X
    float velocidade;
    
    sf::Texture texture;
    sf::Sprite sprite;

public:
    PinguimColetavel(float x, float y, char type) :
    X(x * CELL_SIZE),
    Y(y * CELL_SIZE),
    tipo(type),
    texture(),
    sprite(texture)
    {
        if (!texture.loadFromFile("Sprites/pinguim_principal.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/Bill.png" << std::endl;
        }

        sprite.setTextureRect(sf::IntRect({0, 0}, {32, 32}));
        sprite.setOrigin({0,0});
        sprite.setPosition({X,Y});
        sprite.setColor(sf::Color(0x6495EDFF));

    }
    void handleInput() 
    {
        X += velocidade;
        
    }
    void desenhar(sf::RenderWindow& window) 
    {
        if (!texture.loadFromFile("Sprites/pinguim_principal.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/Bill.png" << std::endl;
        }

        sf::Sprite fake (texture);
        fake.setPosition({X,Y});
        fake.setTextureRect(sf::IntRect({0, 0}, {32, 32}));
        window.draw(fake); // agora desenha o mesmo sprite da classe
    }
    sf::FloatRect get_rect() const
    {
        return sf::FloatRect(
            sf::Vector2f(X, Y),           // posição (float)
            sf::Vector2f(CELL_SIZE, CELL_SIZE)  // tamanho
        );
    }
    // Para resetar se passar de fase
    void reset_ping_pos()
    {
        X = MAPA_LARGURA / 2.f;
        Y = MAPA_ALTURA - 1 * CELL_SIZE;
        velocidade = 0;
    }
    // Para saber se esta ou nao sobre obstaculo
    void set_velocidade(float vel)
    {
        velocidade = vel;
    }
};