
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 17/11/2019.
//

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Header
#include "GameState.h"


//--------------------------------------------------------------------------------------------------------------------//
//Classe Interface para usar e trocar states.
class GameState;

class InterfaceState {

public:
    InterfaceState();
    ~InterfaceState();

    void inicializar(); //cria e chama os Menus
    void executar();    //inicia o state novo jogo e a partir dele, chama state fase
    void pausar();      //chamado a partir de fase, e retorna a fase


private:
    friend class GameState;
    void changeState(GameState* pState);
    GameState* state;
};

