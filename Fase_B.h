
//--------------------------------------------------------------------------------------------------------------------//
//Implementado por:
    //Simão - 100%
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Fase_B

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Fase.h"

//--------------------------------------------------------------------------------------------------------------------//
//Entidades da Fase
#include "Inimigo_Boss.h"
#include "Obstaculo_Movel.h"


//--------------------------------------------------------------------------------------------------------------------//
//Classe Fase_B//
class Fase_B : public Fase {
private:
    int numBoss;
//--------------------------------------------------------------------------------------------------------------------//
//constantes	
    static const String FASE_FILE;
    static const int FASE_WIDTH;
    static const int FASE_HEIGHT;
    static const int id;
    static const float FIM;
    void setFinalPosition(){finalPosition = FIM*50.0f;}
//--------------------------------------------------------------------------------------------------------------------//
//funções
    void criaEntidade(char aux, Vector2f pos);
    void criaInimigoBoss(Vector2f pos);
    void criaCaixa(vector2f pos);

public:
	Fase_B( Jogador_1* jogador1 = nullptr, Jogador_2* jogador2 = nullptr);
	~Fase_B();
	void inicializa();
    const int getID(){ return id;}

};
