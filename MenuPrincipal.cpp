#include "MenuPrincipal.h"
#include <iostream>

MenuPrincipal::MenuPrincipal()
{
    contador = 0;
    keyRepeat = false;
    naoDuplica = 0;
}

MenuPrincipal::~MenuPrincipal()
{
    //dtor
}

int MenuPrincipal::executar()
{
    inicializaTextos();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && contador <2 && naoDuplica > 7)
    {
        contador++;
        naoDuplica = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && contador >0 && naoDuplica > 7)
    {
        contador--;
        naoDuplica = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && naoDuplica > 7)
    {
        naoDuplica = 0;
        return contador;
    }

    switch (contador)
    {
        case 0:
            NovoJogo.setColor(sf::Color::Red);
            Ranking.setColor(sf::Color::White);
            Sair.setColor(sf::Color::White);
            break;

        case 1:
            NovoJogo.setColor(sf::Color::White);
            Ranking.setColor(sf::Color::Red);
            Sair.setColor(sf::Color::White);
            break;

        case 2:
            NovoJogo.setColor(sf::Color::White);
            Ranking.setColor(sf::Color::White);
            Sair.setColor(sf::Color::Red);
            break;
    }

    if(naoDuplica < 100)
    {
        naoDuplica++;
    }

    return -1;
}

void MenuPrincipal::update()
{
    int op = -1;
    op = executar();

    switch (op)
    {
        case 0:
        {
            novoJogo();
        }
            break;

        case 1:
        {
            ranking();
        }

            break;

        case 2:
        {
            sair();
        }
            break;

    }
}

void MenuPrincipal::inicializaTextos()
{
    sf::Font font;
    font.loadFromFile("Textures/arial.ttf");

    NovoJogo.setString("Novo Jogo");
    Ranking.setString("Ranking");
    Sair.setString("Sair");

    NovoJogo.setFont(font);
    Ranking.setFont(font);
    Sair.setFont(font);

    NovoJogo.setPosition(0.0f, 0.0f);
    Ranking.setPosition(0.0f, 30.0f);
    Sair.setPosition(0.0f, 60.0f);

    draw(NovoJogo);
    draw(Ranking);
    draw(Sair);
}

void MenuPrincipal::novoJogo()
{
    std::cout<<"Novo Jogo"<<std::endl;
}

void MenuPrincipal::ranking()
{
    std::cout<<"Ranking"<<std::endl;
}

void MenuPrincipal::sair()
{

}
