
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 21/11/2019.
//

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Header
#include "GameState.h"

//--------------------------------------------------------------------------------------------------------------------//
//classe
class State_Fase : public GameState{
private:
	//static State_Fase* _instance;
	State_Fase();
	~State_Fase();

	void inicializar();
    void executar();
    void changeState(GameState* pState);
    //State_Fase* getInstance();
public:
    //State_Fase* getState();
};
