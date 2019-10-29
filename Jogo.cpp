
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 27/10/2019//
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
    while (g->janelaAberta()) //todo criar um metodo em GerenciadorGrafico para verificar se esta aberta a janela
    {
        //ATUALIZA DELTA TIME
        //METODO EXECUTE DE STATE
            //cria e marca as Entidades necessarias para o state
        g->executar();  //metodo executar do gerenciador grafico
        //METODO DRAW DO STATE
            //todo pode ser alterado para chamar o metodo draw da lista, ja que states nao terao listas proprias
//--------------------------------------------------------------------------------------------------------------------//
//Teste de impressao
        g->getWindow()->draw(shape);
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