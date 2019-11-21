
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 19/11/2019.
//

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Header
#include "Jogador_1.h"
#include "Jogador_2.h"


//--------------------------------------------------------------------------------------------------------------------//
//classe
class GameState {

//--------------------------------------------------------------------------------------------------------------------//
//ATRIBUTOS//
private:
    static GameState* _instance;
protected:
    
	//Sera StateNovoJogo que irá definir quantos jogadores vão estar na partida
    static Jogador_1* pJ1;
    static Jogador_2* pJ2;

//--------------------------------------------------------------------------------------------------------------------//
//METODOS//
private:
    GameState();
    ~GameState();
public:
    static GameState* getState();

protected:
    virtual void inicializar();
    virtual void executar();
    virtual void changeState(GameState* pState);


};

