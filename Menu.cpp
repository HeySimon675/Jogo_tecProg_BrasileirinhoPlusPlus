#include "Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::update()
{
}

void Menu::draw(sf::Text text)
{
    gerenciadorGrafico->draw(text);
}


sf::Font Menu::getFont()
{
    font.loadFromFile(gerenciadorGrafico->getFont());
    return font;
}
