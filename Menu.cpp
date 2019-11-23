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
    font.loadFromFile("Textures/arial.ttf");
    return font;
}
