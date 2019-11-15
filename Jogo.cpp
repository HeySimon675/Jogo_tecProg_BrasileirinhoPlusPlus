
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 27/10/2019//
// Update 04/11 - 11hrs
#include "Jogo.h"

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
    p1.inicializaJogador_1(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(100.0f, 100.0f),true,
            100.0f, 50.0f,sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Up);
    lEntidades.incluir(static_cast<Entidade*>(&p1));
}
//--------------------------------------------------------------------------------------------------------------------//
//metodos principais//
void Jogo::executar() {
//todo Loop Principal
//Função que irá conter o loop principal, chamando os metodos principais das classes agregadas em jogo
//--------------------------------------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------------------------------------//
float deltaTime = 0.0f;
	sf::Clock clock;

//--------------------------------------------------------------------------------------------------------------------//
    while (g->janelaAberta())
    {

        deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 60.0f){
            deltaTime = 1.0f / 60.0f;
		}

//--------------------------------------------------------------------------------------------------------------------//
        //ATUALIZA DELTA TIME
        //METODO EXECUTE DE STATE
            //cria e marca as Entidades necessarias para o state
        g->executar();  //metodo executar do gerenciador grafico
        //METODO DRAW DO STATE
            //todo pode ser alterado para chamar o metodo draw da lista, ja que states nao terao listas proprias
//--------------------------------------------------------------------------------------------------------------------//
        update(deltaTime);
        draw();
        g->exibir();   //Display, exibindo em tela o que ja foi renderizado
    }
}


//--------------------------------------------------------------------------------------------------------------------//
//Nesse momento do desenvolvimento, esses metodos se tornaram obsoletos//
void Jogo::update(float deltaTime) {
    //ira atualizar as posições das Entidades dependendo de seu State
    p1.update(deltaTime);
}

void Jogo::draw() {
    //p1.draw();
    lEntidades.drawEntidades();
}
//--------------------------------------------------------------------------------------------------------------------//
