
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 19/11/2019.
//

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Header
#include "Jogador_1.h"
#include "Jogador_2.h"
#include "ListaEntidades.h"


//--------------------------------------------------------------------------------------------------------------------//
//classe
class GameState {

//--------------------------------------------------------------------------------------------------------------------//
//ATRIBUTOS//
private:
    ListaEntidades* listaEntidades;
protected:

	//Sera StateNovoJogo que irá definir quantos jogadores vão estar na partida
    static Jogador_1* pJ1;
    static Jogador_2* pJ2;

//--------------------------------------------------------------------------------------------------------------------//
//METODOS//
public:
    GameState();
    ~GameState();
protected:

    //os metodos de inicialização para GameState serão colocados na construtora
    virtual void inicializar()= 0;

    virtual void executar() = 0;
    virtual void changeState(GameState* pState) = 0;
    virtual GameState* getInstance() = 0;
};

