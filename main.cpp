#include <iostream>
#include "Jogo.h"


int main()
{

    Jogo* SFML_The_Game = Jogo::getJogo();
    SFML_The_Game->executar();
    return 0;
}