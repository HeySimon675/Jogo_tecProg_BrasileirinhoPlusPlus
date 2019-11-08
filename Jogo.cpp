
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 27/10/2019//
// Update 04/11 - 11hrs
#include "Jogo.h"
#include "math.h"   //temporario
#include "Collider.h"//temporario
//--------------------------------------------------------------------------------------------------------------------//
//Inicializações de Variaveis
Jogo* Jogo::_instance = nullptr;



//--------------------------------------------------------------------------------------------------------------------//
//Metodo Singleton//
Jogo *Jogo::getJogo() {
    if(!_instance){
        _instance = new Jogo;
    }
    return _instance;
}

//--------------------------------------------------------------------------------------------------------------------//
//construtora Privada//
Jogo::Jogo() {
    inicializa();
}   //end Construtora

//--------------------------------------------------------------------------------------------------------------------//
//destrutora//

Jogo::~Jogo() {

}   //end Destrutora

//--------------------------------------------------------------------------------------------------------------------//
//inicializadores//
void Jogo::inicializa() {
    g = GerenciadorGrafico::getGerGrafico();
}
//--------------------------------------------------------------------------------------------------------------------//
//metodos principais//
void Jogo::executar() {
//todo Loop Principal
//Função que irá conter o loop principal, chamando os metodos principais das classes agregadas em jogo
//--------------------------------------------------------------------------------------------------------------------//
//teste
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
//--------------------------------------------------------------------------------------------------------------------//
//FIM TESTE//
//--------------------------------------------------------------------------------------------------------------------//
//implementação do prototipo//
/*
  //Prototipo marcado como comentario
    //criando o player//
    Texture playerTx;
    IntRect rect;
    rect.height = 156;
    rect.width = 175;
    rect.left = 0;
    rect.top = 0;
    playerTx.loadFromFile("../Textures/Jogador_1_texture.png");
    RectangleShape player(Vector2f(155,155));
    player.setTexture(&playerTx);
    player.setTextureRect(rect);
    float speed =100;
    Vector2f velocity(0,0);
    bool canjump=true;
    View view;
    Collider playerCollider(&player);
    player.setPosition(Vector2f(50,50));

    //plataforma
    RectangleShape plataforma(Vector2f(10000,145));
    plataforma.setFillColor(Color::Green);
    plataforma.setPosition(Vector2f(0,300));
    Collider plataformaCollider(&plataforma);

    Clock deltaClock;
*/
    while (g->janelaAberta())
    {
//--------------------------------------------------------------------------------------------------------------------//
//implementação do prototipo//
/*
//PROTOTIPO MARCADO COMO COMENTARIO
    deltaTime = deltaClock.restart().asSeconds();
    if(deltaTime>1.0f / 20.0f){
        deltaTime = 1.0f / 20.0f;
    }
    //movimentação
        velocity.x *= 0.5f;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            velocity.x -= speed ;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            velocity.x += speed ;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canjump){
            canjump= false;
            velocity.y = -sqrtf(2.0f * (981.0f) * 100);
            //sqrt (2.0f *  g * jumpheight)  1 metro equivale a 1000px
            //o sinal de negativo é para que o objeto possa subir

        }
        velocity.y += 981.0f *deltaTime;
        //velocity contara quanto o objeto deverá se mover
        player.move(velocity*deltaTime);
        view.setCenter(player.getPosition());
        g->getWindow()->setView(view);


        sf::Vector2f direction;
        if(plataformaCollider.checkCollision(&playerCollider,direction,0.2f)){
            //minotauro.onCollision(direction);
            if(direction.x<0.0f){//left
                velocity.x=0.0f;
            }else if (direction.x<0.0f){ //right
                velocity.x=0.0f;
            }
            if(direction.y > 0.0f){ //colisão encima
                velocity.y=0.0f;
            }else if (direction.y<0.0f){
                canjump=true;
                velocity.y=0.0f;
            }
        }
*/
//fim do prototipo
//--------------------------------------------------------------------------------------------------------------------//
        //ATUALIZA DELTA TIME
        //METODO EXECUTE DE STATE
            //cria e marca as Entidades necessarias para o state
        g->executar();  //metodo executar do gerenciador grafico
        //METODO DRAW DO STATE
            //todo pode ser alterado para chamar o metodo draw da lista, ja que states nao terao listas proprias
//--------------------------------------------------------------------------------------------------------------------//
//Teste de impressao
        //g->getWindow()->draw(player);
        //g->getWindow()->draw(plataforma);
        //g->getWindow()->draw((shape));
//fim teste
//--------------------------------------------------------------------------------------------------------------------//
        g->exibir();   //Display, exibindo em tela o que ja foi renderizado

    }

}


//--------------------------------------------------------------------------------------------------------------------//
//Nesse momento do desenvolvimento, esses metodos se tornaram obsoletos//
void Jogo::update() {
    //ira atualizar as posições das Entidades dependendo de seu State
}

void Jogo::draw() {
}
//--------------------------------------------------------------------------------------------------------------------//