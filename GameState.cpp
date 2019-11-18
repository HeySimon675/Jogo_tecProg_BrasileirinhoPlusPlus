
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 18/11/2019.
//

#include "GameState.h"

GameState *GameState::getState() {
    if(!_instance){
        _instance = new GameState();
        return _instance;
    } else{
        return _instance;
    }
}

void GameState::inicializar() {

}

void GameState::executar() {

}

void GameState::changeState(GameState *pState) {

}
