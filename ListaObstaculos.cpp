
//--------------------------------------------------------------------------------------------------------------------//

#include "ListaObstaculos.h"

ListaObstaculos::ListaObstaculos() {
    contador = 0;
}

ListaObstaculos::~ListaObstaculos() {

}

void ListaObstaculos::incluir(Obstaculo *Obstaculo) {
    vetorObstaculo.push_back(Obstaculo);
    contador++;
}

void ListaObstaculos::desativar() {
    vector<Obstaculo*>::iterator iterator = vetorObstaculo.begin();
    while(iterator != vetorObstaculo.end()){
        (*iterator)->desativar();
    }
}
