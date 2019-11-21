
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 18/11/2019.
//

#include "GameState.h"

//singleton
GameState* GameState::_instance = nullptr;

GameState *GameState::getState() {
    if(!_instance){
        _instance = new GameState;
    }
        return _instance;
}


ListaEntidades *GameState::getLista() {
    return listaEntidades;
}

GameState::GameState() {
    listaEntidades = new ListaEntidades;
    //coloca no state inicial
    inicializar();
}

void GameState::inicializar() {}

void GameState::executar() {}

void GameState::changeState(GameState *pState) {}
