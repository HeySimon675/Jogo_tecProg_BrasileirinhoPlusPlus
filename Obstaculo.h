
//--------------------------------------------------------------------------------------------------------------------//
//Implementado por:
    //Coradassi - 85%
    //Simão     - 15%
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Entidade

//Deriva as Classes:
//Obstaculo_A
//Obstaculo_B
//Obstaculo_C

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Entidade.h"
//#include "Collider.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Obstaculo//
class Obstaculo : public Entidade{

protected:
    RectangleShape body;
    bool canMove;
    bool canHurt;
    float push;
public:
    void setPosition(Vector2f position);

//--------------------------------------------------------------------------------------------------------------------//
//Constantes//
protected:
    static const Vector2f TAMANHO_PADRAO;
    static const Vector2f POSICAO_PADRAO;

private:
	
public:
    Obstaculo(Vector2f position = POSICAO_PADRAO, Vector2f size = TAMANHO_PADRAO);

	~Obstaculo();
	void setCanMove(bool canMove);
	bool getCanMove();
	void setCanHurt(bool canHurt);
	bool getCanHurt();
    float getPush(){return push;}
	void draw();
//Metodos para Colisão
	Vector2f getPosition(){ return body.getPosition();}
    Vector2f getHalfSize(){ return (body.getSize()/2.0f);}
    void move (float dx, float dy){body.move(dx,dy);}
};
