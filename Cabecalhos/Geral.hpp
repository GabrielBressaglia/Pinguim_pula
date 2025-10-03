#pragma once

unsigned int CELL_SIZE = 32;
unsigned int CELL_CHUNCKS = 16;

unsigned int offset_Mapa = 5;

unsigned int MAPA_ALTURA = CELL_CHUNCKS * CELL_SIZE + offset_Mapa * CELL_SIZE;
unsigned int MAPA_LARGURA = CELL_CHUNCKS * CELL_SIZE;

float VELOCIDADE_COMUM = 1;