
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 26/10/19.


#include "GerenciadorGrafico.h"

#include <bits/stdc++.h>

GerenciadorGrafico* GerenciadorGrafico::_instance = nullptr;
//--------------------------------------------------------------------------------------------------------------------//
/*PREFIXO DO SISTEMA//
    "../"      -> LINUX
    ""         -> WINDOWS
*/
const String GerenciadorGrafico::SYSTEM_PREFIX = "../";


//--------------------------------------------------------------------------------------------------------------------//
//Variaveis Static//


//altura e largura da Window
const unsigned int GerenciadorGrafico::larguraJanela = 800;
const unsigned int GerenciadorGrafico::alturaJanela = 600;
//Tamanho da Window, usado pela View
const Vector2f GerenciadorGrafico::WindowSize(larguraJanela,alturaJanela);
const Vector2f GerenciadorGrafico::center(larguraJanela/2,alturaJanela/2);

//Titulo Da janela e VideoMode da janela
const String GerenciadorGrafico::titulo("SFML_The_Game");

//Chave do Map
int GerenciadorGrafico::key = 0;
//Textures//
const String GerenciadorGrafico::TEXTURE_DIR = SYSTEM_PREFIX + "Textures/";

//players//
const String GerenciadorGrafico::JOGADOR_1_tx = TEXTURE_DIR + "Jogador_1_texture.png";
const String GerenciadorGrafico::JOGADOR_2_tx = TEXTURE_DIR + "Jogador_2_texture.png";

//Inimigos//
const String GerenciadorGrafico::INIMIGO_A_tx = TEXTURE_DIR + "Inimigo_A_texture.png";
const String GerenciadorGrafico::INIMIGO_B_tx = TEXTURE_DIR + "Inimigo_B_texture.png";
const String GerenciadorGrafico::INIMIGO_BOSS_tx = TEXTURE_DIR + "Inimigo_Boss_texture.png";

//Obstaculos//
const String GerenciadorGrafico::OBSTACULO_PLATAFORMA_tx = TEXTURE_DIR + "Obstaculo_Plataforma_texture.png";
const String GerenciadorGrafico::OBSTACULO_CAIXA_tx = TEXTURE_DIR + "Obstaculo_Caixa_texture.png";
const String GerenciadorGrafico::OBSTACULO_SPIKE_tx = TEXTURE_DIR + "Obstaculo_Spike_texture.png";

//Projetil//
const String GerenciadorGrafico::PROJETIL_tx = TEXTURE_DIR + "Projetil_texture.png";
//--------------------------------------------------------------------------------------------------------------------//
//FIM Variaveis Static//

//Construtora Privada
GerenciadorGrafico::GerenciadorGrafico() : _window(VideoMode(larguraJanela,alturaJanela),titulo), pView(center,WindowSize)
{
    inicializa();
}//fim da construtora

//destrutora
GerenciadorGrafico::~GerenciadorGrafico() {
    //todo Desalocar
    // texturas do vector antes de destruir o gerenciador
    //for(int i = 0; i< key ; i++){
    //    delete _mTexture[i];
        //verificar se map possui push back
    //}
    // desalocar objetos dinamicos (_Window, _view)
    //if (_instance){
        //delete pView;
        //delete _window;
        //delete _instance;
    //}
    //_instance = nullptr;
}   // fim da destrutora

//singleton
GerenciadorGrafico *GerenciadorGrafico::getGerGrafico() {
    if(!_instance){
        _instance = new GerenciadorGrafico();
    }
    return _instance;
}

//--------------------------------------------------------------------------------------------------------------------//
//- SOMENTE PARA TESTE
//get Vector    
vector<Texture *> *GerenciadorGrafico::getVector() {
    return &_vTexture;
}

//get map

map<int,Texture*> * GerenciadorGrafico::getMap(){
    return &_mTexture;
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
    //pView = new View(center,WindowSize);
    //_window->setView(*pView);
    _window.setView(pView);
}


//Carrega texturas//

void GerenciadorGrafico::load(const String _caminho) {
    Texture* tx = new Texture;
    tx->loadFromFile(_caminho);
    //this->getVector()->push_back(tx);
    //TODO: TESTE DE INCLUSÃO EM MAP
    this->_mTexture[key] = tx;
    key++;
}

void GerenciadorGrafico::carregaTexturas() {
    //TODO colocar try catch para carregar textura
    load(JOGADOR_1_tx);     //0
    load(JOGADOR_2_tx);     //1
    
    load(INIMIGO_A_tx);     //2

    
    load(OBSTACULO_PLATAFORMA_tx);//3
    load(OBSTACULO_CAIXA_tx);     //4
    load(OBSTACULO_SPIKE_tx);     //5
    
    load(PROJETIL_tx);            //6

    //load(INIMIGO_B_tx);       //7
    //load(INIMIGO_BOSS_tx);    //8
}
//Carrega fontes//
void GerenciadorGrafico::carregaFontes() {

}
//inicializa Window//
void GerenciadorGrafico::inicializaWindow() {
    //_window = new RenderWindow(VideoMode(larguraJanela,alturaJanela),titulo);
    //_window->setFramerateLimit(60);
    _window.setFramerateLimit(60);
}

//--------------------------------------------------------------------------------------------------------------------//
//Loop//

//Verifica se a Janela Esta Aberta//
bool GerenciadorGrafico::janelaAberta() {
    //return (_window->isOpen());
    return (_window.isOpen());
}

//Chama Display, exibindo objetos renderizados//
void GerenciadorGrafico::exibir() {
    //_window->display();
    _window.display();
}

//Update SFML//
void GerenciadorGrafico::updateSFML() {
    while(_window.pollEvent(event)){
        if(event.type == Event::Closed){
            _window.close();
        }
    }
}
//--------------------------------------------------------------------------------------------------------------------//
//Executar//
void GerenciadorGrafico::executar() {
    updateSFML();
    _window.clear();
}
//--------------------------------------------------------------------------------------------------------------------//
//draw//
void GerenciadorGrafico::draw(const RectangleShape body) {
    _window.draw(body);
}

void GerenciadorGrafico::drawPontos(int pontos)
{
    sf::Font font;
    sf::Text text;
    font.loadFromFile("Textures/arial.ttf");
    std::string s = "Pontos: " + std::to_string(pontos);
    text.setString(s);
    text.setFont(font);
    text.setPosition(sf::Vector2f(larguraJanela - 640.0f, -325.0f));
    text.setScale(sf::Vector2f(0.75f, 0.75f));
    _window.draw(text);

}

void GerenciadorGrafico::draw(Text text)
{
    _window.draw(text);
}


//--------------------------------------------------------------------------------------------------------------------//
//Ferramentas

Texture* GerenciadorGrafico::getTexture(int chave){
    if(chave < getLastKey()){
        return this->_mTexture[chave];
    }
}

void GerenciadorGrafico::associaTextura(Entidade* entidade){
    //TODO: para implementar, se necessário   
}

//--------------------------------------------------------------------------------------------------------------------//
//Função obsoleta nesse estagio do desenvolvimento
void GerenciadorGrafico::drawEntidade(Entidade* entidade) {

}

//--------------------------------------------------------------------------------------------------------------------//



