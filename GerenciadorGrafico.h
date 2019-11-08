
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 26/10/19.
#pragma once

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
class Entidade;
//--------------------------------------------------------------------------------------------------------------------//
//Namespace's
using namespace sf;
using std::vector;
using std::string;
namespace gerenciadores {
    class GerenciadorGrafico;
}
//--------------------------------------------------------------------------------------------------------------------//
//Gerenciador Grafico


typedef class GerenciadorGrafico {
private:
    RenderWindow* _window;
    View* pView;
    vector<Texture*> _vTexture;
    static GerenciadorGrafico* _instance;   //Singleton
    Event event;
//contrutora privada//
    GerenciadorGrafico();
public:

    ~GerenciadorGrafico();
    static GerenciadorGrafico* getGerGrafico();     //implementação do Singleton
//--------------------------------------------------------------------------------------------------------------------//
//METODOS PARA TESTE//
private:
    RenderWindow* getWindow(){ return _window;}
//--------------------------------------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------------------------------------//
//loop//
public:
    void executar();
    bool janelaAberta();
    void exibir();
    void drawEntidade(Entidade* entidade);
    void draw(Drawable body);
private:
    void updateSFML();


//--------------------------------------------------------------------------------------------------------------------//
//Inicializadoras//
public:
    void inicializa();
private:
    void inicializaView();
    void carregaTexturas();
    void carregaFontes();
    void inicializaWindow();
//end Private

//--------------------------------------------------------------------------------------------------------------------//
//Static Const//
public:
    //Janela e View//
    static const unsigned int larguraJanela;
    static const unsigned int alturaJanela;
    static const Vector2f WindowSize;
    static const String titulo;
    static const Vector2f center;
    //View //



}gGrafico;


