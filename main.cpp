#include "Jogo.h"
//---------------------------UML-THE-GAME-----------------------------------------------------------------------------//

/**COMO EXECUTAR:   **/
//Va em GerenciadorGrafico.cpp e Fase.cpp e altere o valor da String SYSTEM_PREFIX
    //Windows
        /**deixe vazio o valor da string     **/
    //Linux
        /**altere o valor para ../  **/
//NÃO APAGUE A STRING, SOMENTE ALTERE O VALOR

int main()
{

    Jogo* SFML_The_Game = Jogo::getJogo();
    SFML_The_Game->executar();
    return 0;
}