#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <cmath>

#include "Geral.hpp"


class BlocoDeGelo{
private:
    // Possui apenas duas direcoes ou positivo ou negativo
    bool sentido;
    sf::IntRect dir;

    // Posicao
    float X, Y;

    // Velocidade que vai atualizar
    float velocidade;

    // Textura
    sf::Texture texture;
    sf::Sprite sprite;

public:
    BlocoDeGelo(unsigned pos_x, unsigned pos_y, bool direction);

    void atualizarPosicao();
    void desenhar(sf::RenderWindow& window);
    sf::FloatRect get_rect() const;
    float get_velocidade();
};

BlocoDeGelo :: BlocoDeGelo(unsigned pos_x, unsigned pos_y, bool direction) :
    X(pos_x * CELL_SIZE), 
    Y(pos_y * CELL_SIZE),
    sentido(direction),
    texture(),      
    sprite(texture)
{
    if (!texture.loadFromFile("Sprites/GELO_MADEIRA.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/Bill.png" << std::endl;
    }

    // Se viaja para esquerda
    if(direction == 0){
        dir = sf::IntRect({32 * 0, 0}, {32, 32});
        velocidade = -1 * VELOCIDADE_COMUM;
    }
    // Se viaja para direta
    else{
        dir = sf::IntRect({32 * 1, 0}, {32, 32});
        velocidade = VELOCIDADE_COMUM;
    }

    // define o tamanho do cubo de gelo
    sprite.setTextureRect(dir); // Primeiro argumento é a posicao, o segundo o tamanho
    sprite.setOrigin({0,0});
    sprite.setPosition({X,Y});
    sprite.setColor(sf::Color(0x6495EDFF));
}
void BlocoDeGelo::atualizarPosicao()
{
    X += velocidade;

    // Se sair pela direita
    if (X >= MAPA_LARGURA) {
        X = MAPA_LARGURA;
        velocidade = -velocidade;
    }
    // Se sair pela esquerda
    else if (X < 0) {
        X = 0;
        velocidade = -velocidade;
    }
}

/////////////////////////////////////
// Talvez isso nao seja apropriado...
/////////////////////////////////////
// |
// V
void BlocoDeGelo :: desenhar(sf::RenderWindow& window) 
{

    if (!texture.loadFromFile("Sprites/GELO_MADEIRA.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/Bill.png" << std::endl;
    }
    sf::Sprite fake (texture);
    
    fake.setPosition({X,Y});
    fake.setTextureRect(dir);
    window.draw(fake);
}

// size é temp, precisa decidir o tamanho de cada um dps
sf::FloatRect BlocoDeGelo :: get_rect() const
{
    return sf::FloatRect(
        sf::Vector2f(X, Y),
        sf::Vector2f(CELL_SIZE, CELL_SIZE)
    );
}

float BlocoDeGelo :: get_velocidade()
{
    return velocidade;
}
