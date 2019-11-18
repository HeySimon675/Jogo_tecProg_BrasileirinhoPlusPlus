
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 18/11/2019.
//

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Header



//--------------------------------------------------------------------------------------------------------------------//
//classe
class GameState {
public:
    static GameState* getState();

private:
    static GameState* _instance;
protected:
    virtual void inicializar();
    virtual void executar();
    virtual void changeState(GameState* pState);


};

