
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 19/11/2019.
//

#include "GameState.h"

//--------------------------------------------------------------------------------------------------------------------//
//construção//

//singleton
GameState* GameState::_instance = nullptr;
Jogador_1* GameState::pJ1 = nullptr;
Jogador_2* GameState::pJ2 = nullptr;

GameState *GameState::getState() {
    if(!_instance){
        _instance = new GameState;
    }
        return _instance;
}

void GameState::GameState(){

}

void GameState::~GameState(){

}

//--------------------------------------------------------------------------------------------------------------------//
void GameState::inicializar() {}

void GameState::executar() {}

void GameState::changeState(GameState *pState) {}
