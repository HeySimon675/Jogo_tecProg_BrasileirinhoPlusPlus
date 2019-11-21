
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 18/11/2019.
//

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Header
#include "ListaEntidades.h"


//--------------------------------------------------------------------------------------------------------------------//
//classe
class GameState {

private:
    static GameState* _instance;
    GameState();
    ListaEntidades* listaEntidades;
public:
    static GameState* getState();
    ListaEntidades* getLista();

protected:
    virtual void inicializar();
    virtual void executar();
    virtual void changeState(GameState* pState);
};

