
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
    friend class GameState;
public:
    InterfaceState();
    ~InterfaceState();

    void inicializar();
    void executar();
    void changeState(GameState* pState);

private:
    GameState* state;
};

