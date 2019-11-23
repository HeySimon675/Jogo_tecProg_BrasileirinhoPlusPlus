
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
    //faseA = new Fase_A(lEntidades, p1);
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


    //TODO TESTE
    podeDarUpdate = false;  //teste
    plataforma = new Obstaculo_Plataforma(Vector2f(0,200));
    espinho = new Obstaculo_Espinho(sf::Vector2f(-300.0f, 150.0f));
    caixa = new Obstaculo_Movel(sf::Vector2f(-150.0f, 150.0f));
    inimigoA = new Inimigo_A(sf::Vector2f(100.0f, 150.0f));
    inimigoB = new Inimigo_B();
    p1->setPosition(-450,0)

    projetil = new Projetil(sf::Vector2f(25.0f, 25.0f));
    projetilBoss = new Projetil(sf::Vector2f(25.0f, 25.0f));
    inimigoB->inicializar(sf::Vector2f(250.0f, 145.0f),projetil)

    collider.incluiInimigoNaLista(inimigoA);
    collider.incluiInimigoNaLista(inimigoB);
    collider.incluiObstaculoNalista(caixa);
    collider.incluiObstaculoNalista(plataforma);
    collider.incluiObstaculoNalista(espinho);
    collider.incluiProjetilNaLista(projetil);
    collider.getPonteiroPlayer(p1);
    lEntidades->incluir(static_cast<Entidade*>(p1));

    pontos = 1000;
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
    //TODO teste
    sf::Clock clock, clockPontos;
    sf::Time elapsed;

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



        elapsed = clockPontos.getElapsedTime();
        if(elapsed.asSeconds() >= 1.0 && pontos> 0 && p1->getAtivo())
        {
            pontos-=5;
            std::cout<<pontos<<std::endl;
            clockPontos.restart();
        }
        update(deltaTime,elapsed.asSeconds());
        draw();
        g->drawPontos(pontos);
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
void Jogo::update(float deltaTime, float elapsed) {
    collider.executar();


    if(p1->getAtivo())
    {
        p1->update(deltaTime);
    }
    if(inimigoA->getAtivo())
    {
        inimigoA->update(deltaTime);
    }
    if(inimigoB->getAtivo())
    {
        inimigoB->update(deltaTime);
    }

    //if(projetil->getAtivo())
    projetil->update(deltaTime);

    projetilBoss->update(deltaTime);
    menuPrincipal.update();


}

void Jogo::draw() {
    plataforma->draw();
    espinho->draw();
    caixa->draw();

    if(p1->getAtivo())
    {
        p1->draw();
    }

    if(inimigoA->getAtivo())
    {
        inimigoA->draw();
    }

    if(inimigoB->getAtivo())
    {
        inimigoB->draw();
    }

    //if(projetil->getAtivo())
    projetil->draw();

}
//--------------------------------------------------------------------------------------------------------------------//
