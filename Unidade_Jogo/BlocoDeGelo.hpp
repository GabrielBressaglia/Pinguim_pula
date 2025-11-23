#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Geral.hpp"


class BlocoDeGelo{
private:
    bool sentido;                                   // Possui apenas duas direcoes ou positivo ou negativo
    sf::IntRect dir;
    float X, Y;                                     // Posicao
    float velocidade;                               // Velocidade que vai atualizar
    char tipo;                                      // Tipo do bloco
    unsigned largura;                               // largura
    sf::Texture texture;
    sf::Sprite sprite;

public:
    BlocoDeGelo(unsigned pos_x, unsigned pos_y, bool direction, char type);         // ctor, posso adicionar um sem arg
    void atualizarPosicao();
    void desenhar(sf::RenderWindow& window);
    sf::FloatRect get_rect() const;
    float get_velocidade() const;
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

// A subtracao eh feita com a finalidade do pinguim nao ficar em uma posicao muito alem do bloco
// Isso eh uma implicacao entre o movimento int do pinguim e float do bloco de gelo
// Juntamento com o fato dessa funcao retornar um valor floar
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
            sf::Vector2f(32 - 16, 32)
        );
    }
    else if (tipo == 'C')
    {
        return sf::FloatRect(
            sf::Vector2f(X, Y),
            sf::Vector2f(64 - 16, 32)
        );
    }
    else if (tipo == 'D')
    {
        return sf::FloatRect(
            sf::Vector2f(X, Y),
            sf::Vector2f(128- 16, 32)
        );
    }

    // Caso algum erro
    return sf::FloatRect(
            sf::Vector2f(X, Y),
            sf::Vector2f(CELL_SIZE - 12, CELL_SIZE)
        );
}

float BlocoDeGelo :: get_velocidade() const
{
    return velocidade;
}
