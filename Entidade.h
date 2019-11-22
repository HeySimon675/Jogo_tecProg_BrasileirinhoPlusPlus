
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 27/10/19.
//Implementado por:
    //Simão - 100%

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "GerenciadorGrafico.h"

//--------------------------------------------------------------------------------------------------------------------//
//Namespace's
using namespace sf;

//--------------------------------------------------------------------------------------------------------------------//
//Classe Entidade//

class Entidade {
private:
    bool _active;
protected:
    static GerenciadorGrafico* gerenciadorGrafico;
    virtual const int getID() {};


public:
    Entidade();
    virtual ~Entidade();
    bool isActive() { return _active;}
    virtual void setPositionNeutra(Vector2f position) {};
    virtual void setPosition(Vector2f position) = 0;

//meotodos de controle
    void desativar();
    void ativar();

//Metodos de loop//
    virtual void update(float deltaTime) = 0;
    virtual void draw() = 0;

//--------------------------------------------------------------------------------------------------------------------//
//CONSTATNTES

};
