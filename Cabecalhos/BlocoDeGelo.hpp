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

    // Tipo do bloco
    char tipo;

    // largura
    unsigned largura;

    // Textura
    sf::Texture texture;
    sf::Sprite sprite;

public:
    BlocoDeGelo(unsigned pos_x, unsigned pos_y, bool direction, char type);

    void atualizarPosicao();
    void desenhar(sf::RenderWindow& window);
    sf::FloatRect get_rect() const;
    float get_velocidade();
};

BlocoDeGelo :: BlocoDeGelo(unsigned pos_x, unsigned pos_y, bool direction, char type) :
    X(pos_x * CELL_SIZE), 
    Y(pos_y * CELL_SIZE),
    sentido(direction),
    texture(),      
    sprite(texture),
    tipo(type)
{
    switch (type)
    {
    case 'A':
        dir = sf::IntRect({0, 0}, {static_cast<int>(MAPA_LARGURA), 32});
        velocidade = 0 * VELOCIDADE_COMUM;
        largura = static_cast<unsigned>(MAPA_LARGURA);
        break;
    case 'B':
        dir = sf::IntRect({0, 0}, {32, 32});
        velocidade = 3 * VELOCIDADE_COMUM;
        largura = 32;
        break;
    case 'C':
        dir = sf::IntRect({0, 0}, {64, 32});
        velocidade = 2 * VELOCIDADE_COMUM;
        largura = 64;
        break;
    case 'D':
        dir = sf::IntRect({0, 0}, {128, 32});
        velocidade = 1 * VELOCIDADE_COMUM;
        largura = 128;
        break;
    default:
        break;
    }
    // Se viaja para esquerda
    if(direction == 0)
        velocidade = -1 * velocidade;
    // Se viaja para direta
    else
        velocidade = velocidade;

    // define o tamanho do cubo de gelo
    sprite.setTextureRect(dir); // Primeiro argumento é a posicao, o segundo o tamanho
    sprite.setOrigin({0,0});
    sprite.setPosition({X,Y});
    sprite.setColor(sf::Color(sf::Color::White));
}
void BlocoDeGelo::atualizarPosicao()
{
    X += velocidade;

    // Se sair pela direita
    if (X >= MAPA_LARGURA - largura) {
        X = MAPA_LARGURA - largura;
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
    switch (tipo)
    {
    case 'A':
        if (!texture.loadFromFile("Sprites/gelo 0.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/Bill.png" << std::endl;
         }
        break;
    case 'B':
        if (!texture.loadFromFile("Sprites/gelo 1.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/Bill.png" << std::endl;
        }
        break;
    case 'C':
        if (!texture.loadFromFile("Sprites/gelo 2.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/Bill.png" << std::endl;
        }
        break;
    case 'D':
        if (!texture.loadFromFile("Sprites/gelo 3.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/Bill.png" << std::endl;
        }
        break;
    default:
        break;
    }
    sf::Sprite fake (texture);
    
    fake.setPosition({X,Y});
    fake.setTextureRect(dir);
    window.draw(fake);
}

// size é temp, precisa decidir o tamanho de cada um dps
sf::FloatRect BlocoDeGelo::get_rect() const
{
    if (tipo == 'A')
    {
        // largura do mapa inteira
        return sf::FloatRect(
            sf::Vector2f(X, Y),
            sf::Vector2f(static_cast<float>(MAPA_LARGURA), 32.f)
        );
    }
    else if (tipo == 'B')
    {
        return sf::FloatRect(
            sf::Vector2f(X, Y),
            sf::Vector2f(32.f, 32.f)
        );
    }
    else if (tipo == 'C')
    {
        return sf::FloatRect(
            sf::Vector2f(X, Y),
            sf::Vector2f(64.f, 32.f)
        );
    }
    else if (tipo == 'D')
    {
        return sf::FloatRect(
            sf::Vector2f(X, Y),
            sf::Vector2f(128.f, 32.f)
        );
    }

    // fallback padrão (CELL_SIZE x CELL_SIZE)
    return sf::FloatRect(
        sf::Vector2f(X, Y),
        sf::Vector2f(CELL_SIZE, CELL_SIZE)
    );
}

float BlocoDeGelo :: get_velocidade()
{
    return velocidade;
}
