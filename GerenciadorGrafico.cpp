
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 26/10/19.

#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::_instance = nullptr;
//--------------------------------------------------------------------------------------------------------------------//
//Variaveis Static//

//altura e largura da Window
const unsigned int GerenciadorGrafico::larguraJanela = 800;
const unsigned int GerenciadorGrafico::alturaJanela = 600;
//Tamanho da Window, usado pela View
const Vector2f GerenciadorGrafico::WindowSize(larguraJanela,alturaJanela);
const Vector2f GerenciadorGrafico::center(0.0f,0.0f);

//Titulo Da janela e VideoMode da janela
const String GerenciadorGrafico::titulo("SFML_The_Game");

//--------------------------------------------------------------------------------------------------------------------//
//FIM Variaveis Static//

//Construtora Privada
GerenciadorGrafico::GerenciadorGrafico() : RenderWindow(VideoMode(larguraJanela,alturaJanela),titulo){
    inicializa();
    this->setFramerateLimit(60);
}//fim da construtora

//destrutora
GerenciadorGrafico::~GerenciadorGrafico() {
    if (_instance){
        delete _instance;
    }
    //todo Desalocar texturas do vector antes de destruir o gerenciador
    _instance = nullptr;
}   // fim da destrutora

//singleton
GerenciadorGrafico *GerenciadorGrafico::getGerGrafico() {
    if(!_instance){
        _instance = new GerenciadorGrafico();
    }
    return _instance;
}

//--------------------------------------------------------------------------------------------------------------------//
//Inicializadoras//

//inicializadora principal//
void GerenciadorGrafico::inicializa() {
    inicializaView();
    carregaTexturas();
    carregaFontes();
}
//inicializa view
void GerenciadorGrafico::inicializaView() {
    pView = new View(center,WindowSize);
    this->setView(*pView);
}

//todo para Implementar urgente
//Carrega texturas//
void GerenciadorGrafico::carregaTexturas() {

}
//Carrega fontes//
void GerenciadorGrafico::carregaFontes() {

}

//--------------------------------------------------------------------------------------------------------------------//
//Loop//

//Update SFML//
void GerenciadorGrafico::updateSFML() {
    while(this->pollEvent(event)){
        if(event.type == Event::Closed){
            this->close();
        }
    }
}
//loop draw
void GerenciadorGrafico::drawEntidades() {
    this->clear();
    //todo
    // a função ficará encarregada de percorrer a lista verificando quais entidades estão marcadas com ative, assim
    // podendo manter somente uma lista de entidades, então as fases quando chamadas pelo state, iram percorrer a lista
    // alterando bool active de todas as entidades pertinentes, para que o gerenciador grafico saiba o que desenhar
}

//Executar//
void GerenciadorGrafico::executar() {
    //TESTE//
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    //FIM TESTE//
    while (this->isOpen())
    {
        updateSFML();
        drawEntidades();
        // teste//

        this->draw(shape);
        this->display();

    }

}



