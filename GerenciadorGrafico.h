
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


typedef class GerenciadorGrafico : public RenderWindow {
private:
    View* pView;
    vector<Texture*> _vTexture;
    static GerenciadorGrafico* _instance;   //Singleton
    GerenciadorGrafico();
public:

    ~GerenciadorGrafico();
    static GerenciadorGrafico* getGerGrafico();     //implementação do Singleton
    void executar();
//--------------------------------------------------------------------------------------------------------------------//
//Inicializadoras//
    void inicializa();
private:
    void inicializaView();
    void carregaTexturas();
    void carregaFontes();
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


