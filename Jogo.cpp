
//--------------------------------------------------------------------------------------------------------------------//
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
    faseA = new Fase_A();
    faseA->setJogadores(p1);
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
    pontos = 1000;
    menuOp = 0;
    pause = false;
    faseA->desativar();
}

//--------------------------------------------------------------------------------------------------------------------//
//metodos principais//
void Jogo::executar() {
//Função que irá conter o loop principal, chamando os metodos principais das classes agregadas em jogo
//--------------------------------------------------------------------------------------------------------------------//
float deltaTime = 0.0f;
    Clock clock, clockPontos;
    sf::Time elapsed;

//--------------------------------------------------------------------------------------------------------------------//
    while (g->janelaAberta())
    {
        deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 60.0f){
            deltaTime = 1.0f / 60.0f;
		}

        g->executar();  //metodo executar do gerenciador grafico
//--------------------------------------------------------------------------------------------------------------------//
//menu//
        int op = -1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P) && !pause)
        {
            pause = true;
            menu.setMenuPause(true);
            menuOp = 1;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            menuOp = 2;
            menu.setSairOuMenu(true);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            menuOp = 3;
            menu.setSeguirFaseDois(true);
        }


        op = menu.executar(menuOp);


        switch (op)
        {
            case 5:
            {
                std::cout<< "Fechar"<< std::endl;
                g->fechar();
                op = -1;
            }
                break;

            case 1:
            {
                criaFase1player1();
                op = -1;
            }
                break;

            case 2:
            {
                criaFase2player1();
                op = -1;
            }
                break;

            case 3:
            {
                criaFase1player2();
                op = -1;
            }
                break;

            case 4:
            {
                criaFase2player2();
                op = -1;
            }
                break;

            case 6:
            {
                pause = false;
                op = -1;
            }
                break;
            case 7:
            {

            }
                break;
        }

//--------------------------------------------------------------------------------------------------------------------//
        elapsed = clockPontos.getElapsedTime();
        if(elapsed.asSeconds() >= 1.0 && pontos> 0 && p1->isActive())
        {
            pontos-=5;
            std::cout<<pontos<<std::endl;
            clockPontos.restart();
        }
        g->drawPontos(pontos);
//--------------------------------------------------------------------------------------------------------------------//
        if(faseA && faseA->isActive()){
            faseA->draw();
            faseA->update(deltaTime);
        }else{
            //delete faseA;
        }
        if(!pause)
        {
            //TODO trocar pelo update da fase
            //lEntidades->percorrer(deltaTime);
        }

//--------------------------------------------------------------------------------------------------------------------//
        g->exibir();   //Display, exibindo em tela o que ja foi renderizado

    }
}
//--------------------------------------------------------------------------------------------------------------------//
//funções inuteis
void Jogo::inicializarState() {}

void Jogo::executarState() {}

void Jogo::pausarState() {}


//--------------------------------------------------------------------------------------------------------------------//
//Nesse momento do desenvolvimento, esses metodos se tornaram obsoletos//
void Jogo::update(float deltaTime, float elapsed) {}

void Jogo::draw() {}
//--------------------------------------------------------------------------------------------------------------------//
void Jogo::criaFase1player1()
{
    player2 = false;
}

void Jogo::criaFase2player1()
{
    player2 = false;
}

void Jogo::criaFase2player2()
{
    player2 = true;
}

void Jogo::criaFase1player2()
{
    player2 = true;
}

