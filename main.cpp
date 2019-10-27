#include <iostream>
#include "GerenciadorGrafico.h"


int main()
{

    GerenciadorGrafico* g = GerenciadorGrafico::getGerGrafico();
    g->executar();
    return 0;
}