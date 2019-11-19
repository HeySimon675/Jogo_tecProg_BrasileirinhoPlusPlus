
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Last Update 11/11 12hrs
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
    sf::RectangleShape body;
    bool canMove;
    bool canHurt;

private:

//--------------------------------------------------------------------------------------------------------------------//
//Constantes//
	static const Vector2f TAMANHO_PADRAO;
	static const Vector2f POSICAO_PADRAO;
	
public:
    Obstaculo(Vector2f position = POSICAO_PADRAO, Vector2f size = TAMANHO_PADRAO, bool active = true);

	~Obstaculo();
	void inicializaObstaculo(Vector2f position, Vector2f size, bool active);
	void setCanMove(bool canMove);
	bool getCanMove();
	void setCanHurt(bool canHurt);
	bool getCanHurt();
	void draw();
//	Collider GetCollider();
	sf::Vector2f getPosition(){ return body.getPosition();}
    sf::Vector2f getHalfSize(){ return (body.getSize()/2.0f);}
    void move (float dx, float dy){body.move(dx,dy);}
};
