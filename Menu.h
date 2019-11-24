
//Implementado por:
    //Coradassi - 90%
    //Simão     - 10%
#pragma once
#include "Entidade.h"

class Menu : public Entidade
{
public:
    Menu();
    virtual ~Menu();
    void update();
    void draw(sf::Text text);
    int executar(int i);
    virtual void inicializaTextos(){};
    sf::Font getFont();
    int funMenuPrincipal();
    int opcaoMenuPrincipal();
    int opcaoMenuNovoJogo();
    int opcaoMenuFase1player();
    int opcaoMenuFase2player();
    int opcaoMenuPause();
    int funMenuPause();
    void setMenuPause(bool mpa) {menuPause = mpa;}
    void setMenuPrincipal(bool mpr) {menuPrincipal = mpr;}
    void setSeguirFaseDois(bool sfd) {seguirFaseDois = sfd;}
    void setSairOuMenu(bool som) {sairOuMenu = som;}
    int funMenuSairOuMenu();
    int opcaoMenuSairOuMenu();
    int funMenuSeguirFase2();
    int opcaoMenuSeguiFase2();
private:
    sf::RectangleShape fundo;
    sf::Text DesPause;
    sf::Text NovoJogo;
    sf::Text Ranking;
    sf::Text Sair;
    sf::Text Player1;
    sf::Text Player2;
    sf::Text Fase1;
    sf::Text Fase2;
    sf::Text MenuPrincipalText;
    sf::Text SeguirFaseDois;
    sf::Font font;
    int contador;
    bool keyRepeat;
    int naoDuplica;
    bool menuPrincipal;
    bool menuPause;
    bool desPause;
    bool ranking;
    bool sair;
    bool fase1player;
    bool fase2player;
    bool novoJogo;
    bool sairOuMenu;
    bool seguirFaseDois;

};

