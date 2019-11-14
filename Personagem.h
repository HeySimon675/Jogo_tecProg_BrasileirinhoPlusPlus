
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
    sf::RectangleShape body;
    sf::Vector2f vel;
    float speed;
    float jump_height;
    bool canJump;
	float deltaTime;

    /**booleano para dizer se sofreu dano ou não**/
    bool dead;

public:

//--------------------------------------------------------------------------------------------------------------------//
//Metodos//

public:
    Personagem(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height);
    Personagem();
    virtual ~Personagem();

    void inicializaPersonagem(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height);
    virtual void calculaMovimento(const float deltaTime) = 0;
    void draw();
    void update(float deltaTime);
    const bool isDead();
    void setPositionx(const float positionx);

};

