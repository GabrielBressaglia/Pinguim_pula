#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "Geral.hpp"
#include "Pinguim.hpp"
#include "BlocoDeGelo.hpp"

#include "../Estrutura_De_Dados/ListaEncadeada.hpp"


bool Desenhar_tela_inicial(sf::RenderWindow& window)
{
    // posicao da tela de inicio
    sf::RectangleShape rectangleInit;
    rectangleInit.setSize(sf::Vector2f(static_cast<float>(MAPA_LARGURA), static_cast<float>(MAPA_ALTURA) ));
    rectangleInit.setFillColor(sf::Color(sf::Color::Black));
    rectangleInit.setPosition({0, 0});

    // Posicao do batao de inicio
    sf::RectangleShape playButton;
    playButton.setSize(sf::Vector2f(128, 64));
    playButton.setFillColor(sf::Color(sf::Color::White));
    playButton.setPosition({static_cast<float>(MAPA_LARGURA) / 2 - 64  , static_cast<float>(MAPA_ALTURA) / 2});


    window.draw(rectangleInit);
    window.draw(playButton);

    // get the local mouse position (relative to a window)
    sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window is a sf::Window

    if(playButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        return true;
    }
    else{
        return false;
    }
}

void Desenhar_inventario(sf::RenderWindow& window, ListaEncadeada& lista)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(static_cast<float>(MAPA_LARGURA), static_cast<float>(offset_Mapa * CELL_SIZE)));
    rectangle.setOutlineColor(sf::Color(0x210A0AFF));
    rectangle.setOutlineThickness(static_cast<int>(offset_Mapa * CELL_SIZE));
    rectangle.setPosition({0, static_cast<float>(MAPA_ALTURA)});

    window.draw(rectangle);

    std::vector<sf::Texture> texturas(7); // temos A e B por enquanto

    if (!texturas[0].loadFromFile("Sprites/pinguim_A.png"))
        std::cerr << "Erro ao carregar pinguim_A\n";

    if (!texturas[1].loadFromFile("Sprites/pinguim_B.png"))
        std::cerr << "Erro ao carregar pinguim_B\n";

    if (!texturas[2].loadFromFile("Sprites/pinguim_C.png"))
        std::cerr << "Erro ao carregar pinguim_E\n";

    if (!texturas[3].loadFromFile("Sprites/pinguim_D.png"))
        std::cerr << "Erro ao carregar pinguim_D\n";

    if (!texturas[4].loadFromFile("Sprites/pinguim_E.png"))
        std::cerr << "Erro ao carregar pinguim_E\n";

    if (!texturas[5].loadFromFile("Sprites/pinguim_F.png"))
        std::cerr << "Erro ao carregar pinguim_F\n";

    if (!texturas[6].loadFromFile("Sprites/pinguim_G.png"))
        std::cerr << "Erro ao carregar pinguim_G\n";
    
    std::vector<char> tipos = {'A','B', 'C', 'D', 'E', 'F', 'G'}; 

    int i = 0;
    for (char t : tipos) {
        int idx = t - 'A'; // converte 'A'->0, 'B'->1, etc.

        sf::Sprite sprite(texturas[idx]);
        sprite.setTextureRect(sf::IntRect({0,0}, {32,32}));
        sprite.setOrigin({0,0});
        sprite.setPosition({static_cast<float>(CELL_SIZE) + i*2*CELL_SIZE,
                            static_cast<float>(MAPA_ALTURA) - 2*CELL_SIZE});
        
        if (lista.contem(t))
            sprite.setColor(sf::Color::White);
        else
            sprite.setColor(sf::Color::Black);

        window.draw(sprite);
        i++;
    }
}