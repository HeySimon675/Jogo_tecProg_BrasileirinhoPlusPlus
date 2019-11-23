
//--------------------------------------------------------------------------------------------------------------------//
//Implementado por:
    //Coradassi - 95%
    //Simão     - 5%
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Entidade

//Deriva as Classes:
//Projetil_Tipo_1
//Projetil_Tipo_2

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Entidade.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Projetil//
class Projetil : public Entidade {

private:
    RectangleShape body;
    static const float VELOCIDADE_PADRAO;
    static const Vector2f TAMANHO_PADRAO;
    Vector2f vel;
    float speed;
    float posicao_X_inicial;
    float posicao_Y_inicial;
    bool dead;
    bool left;

public:
    Projetil(Vector2f size = TAMANHO_PADRAO, float speed = VELOCIDADE_PADRAO * 1);
    ~Projetil();
    void inicializaProjetil(Vector2f size);
    void update(const float deltaTime);
    void draw();
    void calculaMovimento();
    bool getDead() {return dead;}
    bool setDead(bool d) {dead = d;}
    void setPosicao(Vector2f posicao);
    Vector2f getPosition(){ return body.getPosition();}
    Vector2f getHalfSize(){ return (body.getSize()/2.0f);}
    void move (float dx, float dy){body.move(dx,dy);}
    void setLeft(bool l){left = l;}


};

