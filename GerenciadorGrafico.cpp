
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 26/10/19.
//Update: 11hrs 29/10

#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::_instance = nullptr;
//--------------------------------------------------------------------------------------------------------------------//
//Variaveis Static//

//teste
//altura e largura da Window
const unsigned int GerenciadorGrafico::larguraJanela = 1000;
const unsigned int GerenciadorGrafico::alturaJanela = 650;
//Tamanho da Window, usado pela View
const Vector2f GerenciadorGrafico::WindowSize(larguraJanela,alturaJanela);
const Vector2f GerenciadorGrafico::center(0.0f,0.0f);

//Titulo Da janela e VideoMode da janela
const String GerenciadorGrafico::titulo("SFML_The_Game");

//Textures//
const String GerenciadorGrafico::TEXTURE_DIR("Textures/");

//player
const String GerenciadorGrafico::JOGADOR_1_tx = TEXTURE_DIR + "Jogador_1_texture.png";

//--------------------------------------------------------------------------------------------------------------------//
//FIM Variaveis Static//

//Construtora Privada
GerenciadorGrafico::GerenciadorGrafico(){
    inicializa();
}//fim da construtora

//destrutora
GerenciadorGrafico::~GerenciadorGrafico() {
    if (_instance){
        delete _instance;
    }
    //todo Desalocar
    // texturas do vector antes de destruir o gerenciador
    // desalocar objetos dinamicos (_Window, _view)
    _instance = nullptr;
}   // fim da destrutora

//singleton
GerenciadorGrafico *GerenciadorGrafico::getGerGrafico() {
    if(!_instance){
        _instance = new GerenciadorGrafico();
    }
    return _instance;
}

//get Vector

vector<Texture *> *GerenciadorGrafico::getVector() {
    return &_vTexture;
}


//--------------------------------------------------------------------------------------------------------------------//
//Inicializadoras//

//inicializadora principal//
void GerenciadorGrafico::inicializa() {
    inicializaWindow(); //metodo que iŕá substituir a generalização de RenderWindow
    inicializaView();
    carregaTexturas();
    carregaFontes();
}
//inicializa view
void GerenciadorGrafico::inicializaView() {
    pView = new View(center,WindowSize);
    _window->setView(*pView);
}


//Carrega texturas//

void GerenciadorGrafico::load(const String _caminho) {
    Texture* tx = new Texture;
    tx->loadFromFile(_caminho);
    //tx->loadFromFile(_caminho);
    this->getVector()->push_back(tx);
}

void GerenciadorGrafico::carregaTexturas() {
    //TODO colocar try catch para carregar textura
    load(JOGADOR_1_tx);
}
//Carrega fontes//
void GerenciadorGrafico::carregaFontes() {

}
//inicializa Window//
void GerenciadorGrafico::inicializaWindow() {
    _window = new RenderWindow(VideoMode(larguraJanela,alturaJanela),titulo);
    _window->setFramerateLimit(60);
}

//--------------------------------------------------------------------------------------------------------------------//
//Loop//

//Verifica se a Janela Esta Aberta//
bool GerenciadorGrafico::janelaAberta() {
    return (_window->isOpen());
}

//Chama Display, exibindo objetos renderizados//
void GerenciadorGrafico::exibir() {
    _window->display();
}

//Update SFML//
void GerenciadorGrafico::updateSFML() {
    while(_window->pollEvent(event)){
        if(event.type == Event::Closed){
            _window->close();
        }
    }
}
//--------------------------------------------------------------------------------------------------------------------//
//Executar//
void GerenciadorGrafico::executar() {
    updateSFML();
    _window->clear();
}
//--------------------------------------------------------------------------------------------------------------------//
//draw//
void GerenciadorGrafico::draw(const RectangleShape body) {
    getWindow()->draw(body);
}

//--------------------------------------------------------------------------------------------------------------------//
//Função obsoleta nesse estagio do desenvolvimento
void GerenciadorGrafico::drawEntidade(Entidade* entidade) {

}
//--------------------------------------------------------------------------------------------------------------------//


//--------------------------------------------------------------------------------------------------------------------//



