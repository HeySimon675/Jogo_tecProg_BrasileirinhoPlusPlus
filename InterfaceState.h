
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 17/11/2019.
//

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Header



//--------------------------------------------------------------------------------------------------------------------//
//Classe Interface para usar e trocar states.
class GameState;

class InterfaceState {
public:
    void inicializar();
    void executar();
    void changeState(GameState* pState);

private:
    GameState* state;
};

