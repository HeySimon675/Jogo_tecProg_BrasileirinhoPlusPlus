
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 18/11/2019.
//

#include "State_NovoJogo.h"


State_NovoJogo* State_NovoJogo::_instance = nullptr;

State_NovoJogo* State_NovoJogo::getState() {
    if(!_instance){
        _instance = new State_NovoJogo();
    }
    return _instance;
}

State_NovoJogo::State_NovoJogo() {

}

State_NovoJogo::~State_NovoJogo() {

}
