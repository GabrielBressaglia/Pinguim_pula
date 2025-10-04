#pragma once
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Geral.hpp"
#include "Pinguim.hpp"
#include "BlocoDeGelo.hpp"

#include "../Estrutura_De_Dados/ListaEncadeada.hpp"

/////////////////////////////////////////////////////////////////
// Aqui é onde os osbtaculos são gerados
// Ele usa a ckasse BlocoDeGelo para criar um vetor com os obstáculos
// Eles sao desenhados na função de desenhar
// No update, é verificado se houve ou nao intesecção com rapaz!!
/////////////////////////////////////////////////////////////////

class OrganizadorObstaculos
{
    std::vector<BlocoDeGelo> Obstaculos;
	std::vector<PinguimColetavel> Coletaveis;

public:

    OrganizadorObstaculos(unsigned int i_level);
    void desenhar(sf::RenderWindow& window);
    void generate_level(unsigned int i_level);
    void atualizarPosicao(Pinguim& ping, ListaEncadeada& lista);
};
OrganizadorObstaculos::OrganizadorObstaculos(unsigned int i_level)
{
	generate_level(i_level);
}

void OrganizadorObstaculos::desenhar(sf::RenderWindow& window)
{
	for (BlocoDeGelo& bloc : Obstaculos)
		bloc.desenhar(window);
	for (PinguimColetavel& pC : Coletaveis)
        pC.desenhar(window);
}

void OrganizadorObstaculos::generate_level(unsigned int i_level)
{
	Obstaculos.clear();
	Coletaveis.clear();

	switch (i_level)
	{
		/*
		Aqui é uma bomba no processamenta, colocar tudo no vetor pode (COM certeza é kkkkk) ser ruim
		Mesmo assim, aqui é possível desenhar cada fase.
		Também simplifica a lógica de cair na água
		*/

		// DA PONTA DE CIMA PARA A PONTA DE BAIXO

		// FASE 1
		case 0:
		{
			Obstaculos.push_back(BlocoDeGelo(0, 0, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 1, 1, 'A'));
			Obstaculos.push_back(BlocoDeGelo(6, 2, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 3, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(10, 4, 1, 'D'));
			Obstaculos.push_back(BlocoDeGelo(0, 5, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 6, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(8, 7, 1, 'B'));
			Obstaculos.push_back(BlocoDeGelo(0, 8, 0, 'D'));
			Obstaculos.push_back(BlocoDeGelo(5, 9, 1, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 10, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 11, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(7, 12, 1, 'D'));
			Obstaculos.push_back(BlocoDeGelo(0, 13, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 14, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 15, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 16, 0, 'A'));

			// Coletaveis
			Coletaveis.push_back(PinguimColetavel(8, 12, 'B'));
			Coletaveis.push_back(PinguimColetavel(0, 8, 'A'));
			break;
		}
		// FASE 2
		case 1:
		{
			Obstaculos.push_back(BlocoDeGelo(0, 0, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 1, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(9, 2, 1, 'B'));
			Obstaculos.push_back(BlocoDeGelo(0, 3, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 4, 0, 'D'));
			Obstaculos.push_back(BlocoDeGelo(0, 5, 0, 'D'));
			Obstaculos.push_back(BlocoDeGelo(0, 6, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 7, 1, 'B'));
			Obstaculos.push_back(BlocoDeGelo(0, 8, 0, 'D'));
			Obstaculos.push_back(BlocoDeGelo(0, 9, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 10, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 11, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 12, 0, 'D'));
			Obstaculos.push_back(BlocoDeGelo(12, 13, 1, 'D'));
			Obstaculos.push_back(BlocoDeGelo(3, 14, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 15, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 16, 0, 'A'));

			// Coletaveis
			Coletaveis.push_back(PinguimColetavel(2, 5, 'E'));
			Coletaveis.push_back(PinguimColetavel(0, 10, 'D'));

			break;
		}
		// FASE 3
		case 2:
		{
			Obstaculos.push_back(BlocoDeGelo(0, 0, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 1, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(9, 2, 1, 'B'));
			Obstaculos.push_back(BlocoDeGelo(0, 3, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 4, 0, 'D'));
			Obstaculos.push_back(BlocoDeGelo(7, 5, 0, 'D'));
			Obstaculos.push_back(BlocoDeGelo(11, 6, 1, 'D'));
			Obstaculos.push_back(BlocoDeGelo(0, 7, 1, 'B'));
			Obstaculos.push_back(BlocoDeGelo(0, 8, 0, 'D'));
			Obstaculos.push_back(BlocoDeGelo(0, 9, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(4, 10, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(5, 11, 1, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 12, 0, 'D'));
			Obstaculos.push_back(BlocoDeGelo(12, 13, 1, 'D'));
			Obstaculos.push_back(BlocoDeGelo(3, 14, 0, 'C'));
			Obstaculos.push_back(BlocoDeGelo(0, 15, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 16, 0, 'A'));

			// Coletaveis
			Coletaveis.push_back(PinguimColetavel(0, 3, 'C'));
			Coletaveis.push_back(PinguimColetavel(4, 10, 'F'));

			break;
		}
		// FASE 4
		case 3:
		{
			Obstaculos.push_back(BlocoDeGelo(0, 0, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 1, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 2, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 3, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 4, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 5, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 6, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 7, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 8, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 9, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 10, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 11, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 12, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 13, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 14, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 15, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 16, 0, 'A'));

			// Coletaveis
			Coletaveis.push_back(PinguimColetavel(4, 10, 'G'));

			break;
		}
		// DEFAULT
		default:{
			Obstaculos.push_back(BlocoDeGelo(0, 0, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 1, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 2, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 3, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 4, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 5, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 6, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 7, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 8, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 9, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 10, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 11, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 12, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 13, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 14, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 15, 0, 'A'));
			Obstaculos.push_back(BlocoDeGelo(0, 16, 0, 'A'));
            break;
		}
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
void OrganizadorObstaculos::atualizarPosicao(Pinguim& ping, ListaEncadeada& lista)
{
    for (BlocoDeGelo& bloc : Obstaculos)
        bloc.atualizarPosicao();

	for (PinguimColetavel& pC : Coletaveis)
    {
        bool sobre_bloco_coletavel = false;

        for (BlocoDeGelo& bloc : Obstaculos)
        {
            if (pC.get_rect().findIntersection(bloc.get_rect()))
            {
                pC.set_velocidade(bloc.get_velocidade());
                sobre_bloco_coletavel = true;
                break;
            }
        }

        if (!sobre_bloco_coletavel)
            pC.set_velocidade(0);

        pC.handleInput(); // move o coletável de acordo com a velocidade
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
		for (size_t i = 0; i < Coletaveis.size(); i++)
		{
			if (Coletaveis[i].get_rect().findIntersection((ping.get_rect())))
			{
				bool ok;
				lista.adicionarEmOrdem(Coletaveis[i], ok);
				if(ok)
					Coletaveis.erase(Coletaveis.begin() + i); // apaga o índice certo
				break;
			}
		}
    }
}