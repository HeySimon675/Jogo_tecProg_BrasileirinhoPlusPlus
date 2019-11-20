
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 18/11/2019.
//

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Header



#include "GameState.h"

//--------------------------------------------------------------------------------------------------------------------//
//classe
class State_NovoJogo : public GameState{
private:
    static State_NovoJogo* _instance;
    State_NovoJogo();

public:
    static State_NovoJogo* getState();
    ~State_NovoJogo();
};

