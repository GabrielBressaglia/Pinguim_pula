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
		/*
		Aqui é uma bomba no processamenta, colocar tudo no vetor pode (COM certeza é kkkkk) ser ruim
		Mesmo assim, aqui é possível desenhar cada fase.
		Também simplifica a lógica de cair na água
		*/
		case 0:
		{
			/*
				Criar outros penguins aqui:
				Criar uma outra classe para eles e colocar eles com a mesma lógica que meu pinguim normal
			*/
			Obstaculos.push_back(BlocoDeGelo(0, 0, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 1, 1, 'B'));
			Obstaculos.push_back(BlocoDeGelo(0, 2, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 3, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 4, 0, 'D'));
			Obstaculos.push_back(BlocoDeGelo(0, 5, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 6, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 7, 1, 'B'));
			Obstaculos.push_back(BlocoDeGelo(0, 8, 0, 'D'));
			Obstaculos.push_back(BlocoDeGelo(0, 9, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 10, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 11, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 12, 1, 'D'));
			Obstaculos.push_back(BlocoDeGelo(0, 13, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 14, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 15, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 16, 0, 'A'));

			// Separar isso ??
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
            ping.set_dead();
        }
    }
}