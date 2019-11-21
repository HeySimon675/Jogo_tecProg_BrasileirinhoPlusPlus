
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 09/11/19.

#include "Jogador.h"

//--------------------------------------------------------------------------------------------------------------------//
//CONSTANTES
const Vector2f Jogador::TAMANHO_PADRAO = Vector2f(50.0f,50.0f);

Jogador::Jogador(Vector2f position)
{
    inicializaJogador(position);
}

Jogador::~Jogador()
{
}


void Jogador::inicializaJogador(Vector2f position)
{
    inicializaPersonagem(position,TAMANHO_PADRAO);

}



