
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 21/11/2019.
//

#include "State_Fase.h"

//State_Fase* State_Fase::_instance = nullptr;

//--------------------------------------------------------------------------------------------------------------------//
//CONSTRUÇÃO

State_Fase::State_Fase(){

}

State_Fase::~State_Fase(){


}

void State_Fase::inicializar() {
	//TODO: Para fins de testes, Fase é quem irá alocar um Jogador_1, mas na implementação final isso fica em StateNJ
	//pJ1 = new Jogador_1;
	//pJ1->inicializainicializaJogador_1(Vector2f(5,5), Vector2f(50.0f, 50.0f),true,100.0f, 50.0f,Keyboard::Right,
	//									 Keyboard::Left, Keyboard::Up);

}

void State_Fase::executar() {}

void State_Fase::changeState(GameState *pState) {

}

/*
State_Fase *State_Fase::getInstance() {
    return getState();
}


State_Fase* State_Fase::getState(){
	if(!_instance){
		_instance = new State_Fase;
	}
	return _instance;
}
*/