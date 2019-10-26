
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 26/10/19.

#include "GerenciadorGrafico.h"

//--------------------------------------------------------------------------------------------------------------------//
//Variaveis Static//

//altura e largura da Window
const unsigned int larguraJanela = 200;
const unsigned int alturaJanela = 200;
//Tamanho da Window, usado pela View
const Vector2f WindowSize(larguraJanela,alturaJanela);
const Vector2f center(0.0f,0.0f);

//Titulo Da janela e VideoMode da janela
const String titulo("SFML_The_Game");
const VideoMode videoMode(larguraJanela,alturaJanela);
//--------------------------------------------------------------------------------------------------------------------//
//FIM Variaveis Static//

//Construtora Privada
GerenciadorGrafico::GerenciadorGrafico() : RenderWindow(videoMode,titulo){
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
//Loop
void GerenciadorGrafico::executar() {
    while (this->isOpen())
    {
        sf::Event event;
        while (this->pollEvent(event))
        {
            //fecha a janela
            if (event.type == sf::Event::Closed)
                this->close();
        }
    }

}




