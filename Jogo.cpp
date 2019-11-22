
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
Jogo::Jogo() 
{
    //TODO: Analisar a necessidade de lista estar em Jogo, não seria mais conveniente ficar em State, ou Fase
    p1 = new Jogador_1;
    lEntidades = new ListaEntidades;
    lEntidades->incluir(static_cast<Entidade*>(p1));
    faseA = new Fase_A(lEntidades, p1);

    inicializa();
}   //end Construtora

//--------------------------------------------------------------------------------------------------------------------//
//destrutora//

Jogo::~Jogo() {
    //TODO: destrutora 
    //delete lEntidades;
    delete g;
    //delete pstate;


    if(_instance){
        delete _instance;
    }
    _instance = nullptr;
}   //end Destrutora

//--------------------------------------------------------------------------------------------------------------------//
//inicializadores//
void Jogo::inicializa() {
    g = GerenciadorGrafico::getGerGrafico();    //carrega e inicializa o gerenciador grafico
    //pState = GameState::getState();
}

//--------------------------------------------------------------------------------------------------------------------//
//metodos principais//
void Jogo::executar() {
//TODO: Loop Principal
//Função que irá conter o loop principal, chamando os metodos principais das classes agregadas em jogo
//--------------------------------------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------------------------------------//
//State//




//--------------------------------------------------------------------------------------------------------------------//
float deltaTime = 0.0f;
	Clock clock;

//--------------------------------------------------------------------------------------------------------------------//
    while (g->janelaAberta())
    {
        //ATUALIZA DELTA TIME
        deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 60.0f){
            deltaTime = 1.0f / 60.0f;
		}

//--------------------------------------------------------------------------------------------------------------------//
        
        //METODO EXECUTE DE STATE
            //cria e marca as Entidades necessarias para o state
                //se o State alocar a lista, então irá controlar seu percorrimento, chamando somente um metodo

        //TODO: Verificar em qual ordem deve ser feita a chamada de função, se lista->percorrer() vem antes ou depois


        g->executar();  //metodo executar do gerenciador grafico
        lEntidades->percorrer(deltaTime);

//--------------------------------------------------------------------------------------------------------------------//
//Testes//
        //lEntidades->percorrer(deltaTime);
        g->exibir();   //Display, exibindo em tela o que ja foi renderizado

    }
}

void Jogo::inicializarState() {

}

void Jogo::executarState() {

}

void Jogo::pausarState() {

}


//--------------------------------------------------------------------------------------------------------------------//
//Nesse momento do desenvolvimento, esses metodos se tornaram obsoletos//
void Jogo::update(float deltaTime) {}

void Jogo::draw() {}
//--------------------------------------------------------------------------------------------------------------------//
