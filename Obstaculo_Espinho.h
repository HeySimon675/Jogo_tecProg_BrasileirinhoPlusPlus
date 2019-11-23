
//--------------------------------------------------------------------------------------------------------------------//
//Implementado por:
//Coradassi - 85%
//Simão     - 15%
#pragma once

//--------------------------------------------------------------------------------------------------------------------//
#include "Obstaculo.h"

class Obstaculo_Espinho : public Obstaculo
{
public:
    Obstaculo_Espinho(Vector2f position = POSICAO_PADRAO);
    virtual ~Obstaculo_Espinho();


private:
    static const int id;
    const int getID(){return id;}
};

