#pragma once
#include <SFML/Graphics.hpp>

#include "Geral.hpp"


enum directions { down, right, up, left };


///////////////////////////////////////////////////////////
// Jogavel
///////////////////////////////////////////////////////////
class Pinguim {
private:
    float X, Y;                                     // Posicao
    sf::IntRect direcao;
    sf::IntRect dir[4];                             // Direcao
    std::array<bool, 4> control_keys;               // Estado anterior
    bool morto;                                     // Vivo ou Morto
    float velocidade;                               // Velocidade eixo X
    sf::Texture texture;                            // Textura
    sf::Sprite sprite;

public:
    Pinguim();
    void Controle_Update();
    void desenhar(sf::RenderWindow& window);
    void set_dead();
    bool get_dead() const;
    sf::FloatRect get_rect() const;
    float get_eixo_y() const;                       // Para saber se passou de fase
    void reset_ping_pos();                          // Para resetar se passar de fase
    void set_velocidade(float vel);                 // Altera velocidade se estiver sobre bloco
};
Pinguim :: Pinguim()
: X(MAPA_LARGURA / 2.f),
    Y(MAPA_ALTURA - offset_Mapa * CELL_SIZE),
    texture(),           // cria a textura
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
void Pinguim :: Controle_Update() 
{
    if(morto == 1){
        X = MAPA_LARGURA / 2.f;
        Y = MAPA_ALTURA - offset_Mapa * CELL_SIZE;
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
void Pinguim :: desenhar(sf::RenderWindow& window) 
{
    sprite.setPosition({X,Y});
    sprite.setTextureRect(direcao);
    window.draw(sprite); // agora desenha o mesmo sprite da classe
}
void Pinguim :: set_dead()
{
    morto = true;
}
bool Pinguim :: get_dead() const
{
    return morto;
}
sf::FloatRect Pinguim :: get_rect() const
{
    return sf::FloatRect(
        sf::Vector2f(X, Y),           // posição (float)
        sf::Vector2f(CELL_SIZE, CELL_SIZE)  // tamanho
    );
}
float Pinguim :: get_eixo_y() const
{
    return Y;
}
void Pinguim :: reset_ping_pos()
{
    X = MAPA_LARGURA / 2.f;
    Y = MAPA_ALTURA - offset_Mapa * CELL_SIZE;
    velocidade = 0;
}
void Pinguim :: set_velocidade(float vel)
{
    velocidade = vel;
}


///////////////////////////////////////////////////////////
// Coletavel
///////////////////////////////////////////////////////////
class PinguimColetavel {
private:
    char tipo;                                  // Tipo
    float X, Y;                                 // Posicao
    float velocidade;                           // Velocidade eixo X
    sf::Texture texture;
    sf::Sprite sprite;

public:
    PinguimColetavel(float x, float y, char type);
    void Controle_Update();
    void desenhar(sf::RenderWindow& window);
    sf::FloatRect get_rect() const;
    void set_velocidade(float vel);
    char get_tipo_pinguim() const;
};
PinguimColetavel :: PinguimColetavel(float x, float y, char type) :
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
void PinguimColetavel :: Controle_Update() 
{
    X += velocidade;
    
}
void PinguimColetavel :: desenhar(sf::RenderWindow& window) 
{
    std::string caminho;
    switch (tipo) {
    case 'A':
        if (!texture.loadFromFile("Sprites/pinguim_A.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::" << caminho << std::endl;
        }
        break;
    case 'B':
        if (!texture.loadFromFile("Sprites/pinguim_B.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::" << caminho << std::endl;
        }
        break;
    case 'C':
        if (!texture.loadFromFile("Sprites/pinguim_C.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::" << caminho << std::endl;
        }
        break;
    case 'D':
        if (!texture.loadFromFile("Sprites/pinguim_D.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::" << caminho << std::endl;
        }
        break;
    case 'E':
        if (!texture.loadFromFile("Sprites/pinguim_E.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::" << caminho << std::endl;
        }
        break;
    case 'F':
        if (!texture.loadFromFile("Sprites/pinguim_F.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::" << caminho << std::endl;
        }
        break;
    case 'G':
        if (!texture.loadFromFile("Sprites/pinguim_G.png")) {
            std::cerr << "ERROR::COULD NOT LOAD FILE::" << caminho << std::endl;
        }
        break;
    default:
        break;
}
    sf::Sprite fake (texture);
    fake.setPosition({X,Y});
    fake.setTextureRect(sf::IntRect({0, 0}, {32, 32}));
    window.draw(fake); // agora desenha o mesmo sprite da classe
}
sf::FloatRect PinguimColetavel :: get_rect() const
{
    return sf::FloatRect(
        sf::Vector2f(X, Y),           // posição (float)
        sf::Vector2f(CELL_SIZE, CELL_SIZE)  // tamanho
    );
}
void PinguimColetavel :: set_velocidade(float vel)
{
    velocidade = vel;
}
char PinguimColetavel :: get_tipo_pinguim() const
{
    return tipo;
}


