
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

private:
//--------------------------------------------------------------------------------------------------------------------//
//ATRIBUTOS//
    static GameState* _instance;
    static Jogador_1* pJ1;
    static Jogador_2* pJ2;


    GameState();
    ~GameState();
public:
    static GameState* getState();

protected:
    virtual void inicializar();
    virtual void executar();
    virtual void changeState(GameState* pState);


};

