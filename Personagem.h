
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 09/11/19.
//Last Update 09/11 12hrs
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Entidade

//Deriva as Classes:
    //Jogador
    //Inimigo

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Entidade.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Personagem//
class Personagem : public Entidade {
//--------------------------------------------------------------------------------------------------------------------//
//Parametros//
private:

protected:
    RectangleShape body;
    Vector2f vel;
    float speed;
    float jump_height;
    bool canJump;
	float deltaTime;

    /**booleano para dizer se sofreu dano ou não**/
    bool dead;


//--------------------------------------------------------------------------------------------------------------------//
//Metodos//

    void setPosition(Vector2f position);

public:
    Personagem(Vector2f position, Vector2f size, bool active, float speed, float jump_height);
    Personagem();
    virtual ~Personagem();

    void inicializaPersonagem(Vector2f position = POSICAO_PADRAO, Vector2f size = Vector2f(50,50), bool active = true, float sp = 100.0f, float jh = 50.0f);
    virtual void calculaMovimento(const float deltaTime) = 0;
    void draw();
    void update(float deltaTime);
    const bool isDead();
    void setPositionx(const float positionx);



//--------------------------------------------------------------------------------------------------------------------//
//Constantes//
    static const Vector2f POSICAO_PADRAO;
};

