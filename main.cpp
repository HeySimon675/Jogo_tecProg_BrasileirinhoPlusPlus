#include <iostream>
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"


int main()
{

    GerenciadorGrafico* g = GerenciadorGrafico::getGerGrafico();
    g->executar();
    //GerenciadorGrafico::getGerGrafico()->draw(shape);
    //GerenciadorGrafico::getGerGrafico()->executar();


    return 0;
}