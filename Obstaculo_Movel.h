
//--------------------------------------------------------------------------------------------------------------------//
//Implementado por:
//Coradassi - 85%
//Simão     - 15%
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
#include "Obstaculo.h"

class Obstaculo_Movel: public Obstaculo
{
public:
    Obstaculo_Movel(Vector2f position = POSICAO_PADRAO);
    virtual ~Obstaculo_Movel();

private:
    static const int id;
};

