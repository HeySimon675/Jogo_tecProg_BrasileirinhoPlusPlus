
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 18/11/2019.
//

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Header



//--------------------------------------------------------------------------------------------------------------------//
//classe
class GameState {

private:
    static GameState* _instance;
public:
    //static GameState* getState();

protected:
    virtual void inicializar();
    virtual void executar();
    virtual void changeState(GameState* pState);


};

