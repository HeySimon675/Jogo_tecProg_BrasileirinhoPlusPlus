
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Last Update 11/11 12hrs
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Fase_B

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Fase.h"

//--------------------------------------------------------------------------------------------------------------------//
//Entidades da Fase
#include "Inimigo_Boss.h"
//#include "Obstaculo_caixa.h"


//--------------------------------------------------------------------------------------------------------------------//
//Classe Fase_B//
class Fase_B : public Fase {
private:

//--------------------------------------------------------------------------------------------------------------------//
//constantes	
    static const String FASE_FILE;
    static const int FASE_WIDTH;
    static const int FASE_HEIGHT;

//--------------------------------------------------------------------------------------------------------------------//
//funções
    void criaEntidade(char aux, Vector2f pos);
    void criaInimigoBoss(Vector2f pos);

public:
	Fase_B(ListaEntidades* lista = nullptr, Jogador_1* jogador1 = nullptr, Jogador_2* jogador2 = nullptr);
	~Fase_B();
	void inicializa();

};
