#include <array>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Geral.hpp"
#include "Pinguim.hpp"
#include "BlocoDeGelo.hpp"
/////////////////////////////////////////////////////////////////
// Aqui é onde os osbtaculos são gerados
// Ele usa a ckasse BlocoDeGelo para criar um vetor com os obstáculos
// Eles sao desenhados na função de desenhar
// No update, é verificado se houve ou nao intesecção com rapaz!!
/////////////////////////////////////////////////////////////////

class OrganizadorObstaculos
{
    std::vector<BlocoDeGelo> Obstaculos;

public:

    OrganizadorObstaculos(unsigned char i_level);
    void desenhar(sf::RenderWindow& window);
    void generate_level(unsigned char i_level);
    void atualizarPosicao(Pinguim& ping);
};
OrganizadorObstaculos::OrganizadorObstaculos(unsigned char i_level)
{
	generate_level(i_level);
}

void OrganizadorObstaculos::desenhar(sf::RenderWindow& window)
{
	for (BlocoDeGelo& bloc : Obstaculos)
	{
		bloc.desenhar(window);
	}
}

void OrganizadorObstaculos::generate_level(unsigned char i_level)
{
	Obstaculos.clear();

	switch (i_level)
	{
		case 0:
		{
			Obstaculos.push_back(BlocoDeGelo(0, 0, 1));
			Obstaculos.push_back(BlocoDeGelo(2, 2, 0));

			Obstaculos.push_back(BlocoDeGelo(10, 10, 1));
			Obstaculos.push_back(BlocoDeGelo(11, 11, 0));
			break;
		}
		default:
            break;
    }
}
/*
	Caso a colisão mate o pinguim
	for (BlocoDeGelo& bloc : Obstaculos)
	{
		if (ping.get_rect().findIntersection(bloc.get_rect()))
		{
			ping.set_dead();
		}
	}
*/
void OrganizadorObstaculos::atualizarPosicao(Pinguim& ping)
{
    for (BlocoDeGelo& bloc : Obstaculos)
    {
        bloc.atualizarPosicao();
    }

    if (!ping.get_dead())
    {
        bool sobre_bloco = false;

        for (BlocoDeGelo& bloc : Obstaculos)
        {
            if (ping.get_rect().findIntersection(bloc.get_rect()))
            {
                // Pinguim está sobre o bloco
                ping.set_velocidade(bloc.get_velocidade());
                sobre_bloco = true;
                break; // já achou um bloco embaixo, não precisa checar os outros
            }
        }

        if (!sobre_bloco)
        {
            // Não está sobre nenhum bloco
            ping.set_velocidade(0);
        }
    }
}