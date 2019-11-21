
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 21/11/2019.
//

#include "State_Fase.h"

State_Fase* State_Fase::_instance = nullptr;

//--------------------------------------------------------------------------------------------------------------------//
void State_Fase::inicializar() {}

void State_Fase::executar() {}

void State_Fase::changeState(State_Fase *pState) {}

State_Fase* State_Fase::getInstance(){
	if(!_instance){
		_instance = new State_Fase;
	}
	return _instance;
}
