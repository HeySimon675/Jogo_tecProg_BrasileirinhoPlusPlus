#include "MenuPause.h"

MenuPause::MenuPause()
{
    contador = 0;
    naoDuplica = 0;
}

MenuPause::~MenuPause()
{
    //dtor
}

int MenuPause::executar()
{
    inicializaTextos();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && contador <1 && naoDuplica > 7)
    {
        contador++;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && contador > 0 && naoDuplica > 7)
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
            DesPause.setColor(sf::Color::Red);
            Sair.setColor(sf::Color::White);
            break;

        case 1:
            DesPause.setColor(sf::Color::White);
            Sair.setColor(sf::Color::Red);
            break;
    }

    if(naoDuplica < 100)
    {
        naoDuplica++;
    }

    return -1;
}

void MenuPause::update()
{
    int op = -1;
    op = executar();

    switch (op)
    {
        case 0:
            desPause();
            break;

        case 1:
            sair();
            break;
    }
}

void MenuPause::inicializaTextos()
{
    sf::Font font;
    font.loadFromFile(gerenciadorGrafico->getFont());

    DesPause.setString("DesPausar");
    Sair.setString("Sair");

    DesPause.setFont(font);
    Sair.setFont(font);

    DesPause.setPosition(0.0f, 0.0f);
    Sair.setPosition(0.0f, 30.0f);

    draw(DesPause);
    draw(Sair);
}

void MenuPause::desPause()
{

}

void MenuPause::sair()
{

}
