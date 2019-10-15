/*
-------------- Created by simao on 16/04/19. --------------------------
---------------Lista Template Duplamente Encadeada---------------------
*/
#pragma once
#include "Elemento.h"

template<class TIPO> class Lista {
private:
    Elemento<TIPO>* primeiro;
    Elemento<TIPO>* atual;
    Elemento<TIPO>* aux;
    unsigned int tamanho;
public:
    //Classe Iterator
    //A classe Iterator foi construida com a ajuda do Ex aluno Adriano Paulik
    class Iterator{
    public:
        friend class Lista<TIPO>;   //TODO pesquisar sobre o que é friend class
        typedef TIPO& referencia;
        typedef Elemento<TIPO>* ponteiro;
    private:
        ponteiro _elemento;
    public:
        Iterator(){_elemento= nullptr;}
        Iterator(ponteiro p){_elemento= p;}

        referencia operator*(){
            return  _elemento->getInfo();
        }

        referencia operator->(){
            return (*(*this));
        }

        referencia& operator++(){
            if(_elemento){
                _elemento = _elemento->getProx();
            }
            return *this;
        }
        referencia& operator--(){
            if(_elemento){
                _elemento = _elemento->getAnte();
            }
            return *this;
        }
        bool operator!=(const Iterator& iterator)const {
            return (_elemento != iterator._elemento);
        }

        bool operator==(const Iterator iterator) const{
            return (_elemento == iterator._elemento);
        }
    };

    //CONSTRUTORAS
    Lista() {primeiro= nullptr; atual= nullptr;aux= nullptr; tamanho=0;}
    ~Lista() {
        limpaLista();
        primeiro= nullptr;
        atual= nullptr;
        aux= nullptr;
    }

    //INCLUIR NA LISTA
    bool includeElemento(TIPO* el);
    void operator=(TIPO* el);

    //GET PRIMEIRO E ATUAL ELEMENTO
    Elemento<TIPO>* getPrim();
    Elemento<TIPO>* getAt();

    //REMOVE/RETORNA/LIMPA LISTA
    void popFront();
    void popBack();
    void operator--();
    void limpaLista();

    //FUNÇÕES NAO IMPLEMENTADAS
    void inicializaLista();
    void gravaLista();
    void returnLista();

private:
    bool vazia();
    bool adicionaPrimeiro(TIPO *el);
};

template<class TIPO>
bool Lista<TIPO>::vazia() {
    return primeiro != nullptr;
}

template<class TIPO>
bool Lista<TIPO>::adicionaPrimeiro(TIPO *el) {
    primeiro=aux;
    atual=aux;
    aux->setProx(nullptr);
    aux->setAnte(nullptr);   //Como é o primeiro elemento ele não possui proximo nem anterior
    aux= nullptr;
    return true;
}

//INCLUIR
template<class TIPO>
bool Lista<TIPO>::includeElemento(TIPO *el){
    aux = new Elemento<TIPO>(el); //criando um Elemento com o TIPO especificado, para por na lista
    if (vazia()){
        return adicionaPrimeiro(el);
    }else{// a lista possuí 1+ elementos
        aux= new Elemento<TIPO>(el);
        aux->setAnte(atual);
        atual->setProx(aux);
        aux->setProx(nullptr);
        atual=aux;
        aux=nullptr;
        return true;
    }
}

template<class TIPO>
void Lista<TIPO>::operator=(TIPO *el) {
    if(!includeElemento(el)){
        //TODO
        // Criar aviso para elemento não incluido na lista

    }
}


//GETS
template<class TIPO>
Elemento<TIPO> *Lista<TIPO>::getPrim() {
    return primeiro;
}

template<class TIPO>
Elemento<TIPO> *Lista<TIPO>::getAt() {
    return atual;
}

//RETURN/REMOVE/ LIMPA LISTA

//Remove um elemento do começo da lista
template<class TIPO>
void Lista<TIPO>::popFront() {
    if(!vazia()){
        aux = primeiro;
        primeiro = primeiro->getProx();
        delete aux;
        aux= nullptr;
        if(tamanho==1){
            tamanho--;
            atual = nullptr;
        }
    }
}

//remove uma elemento do começo da lista
template<class TIPO>
void Lista<TIPO>::popBack() {
    if(!vazia()){
        aux = atual;
        atual = atual->getAnte();
        delete aux;
        aux = nullptr;
        if(tamanho==1){
            tamanho--;
            primeiro = nullptr;
        }
    }
}


template<class TIPO>
void Lista<TIPO>::operator--() {
    limpaLista();
}

template<class TIPO>
void Lista<TIPO>::limpaLista() {
    while (!vazia()){
        popFront();
    }
    primeiro = nullptr;
}

//NÃO IMPLEMENTADAS
//todo O objetivo dessas funções é gravar os Elementos da lista em arquivos .txt, tornando assim o savegame possivel
template<class TIPO>
void Lista<TIPO>::inicializaLista() {
    //A função inicializa a lista deve buscar elementos ja criados da lista em questão nos arquivos .txt
}

template<class TIPO>
void Lista<TIPO>::gravaLista() {
    //reescreve o arquivo .txt que contem objetos ja criados da lista
}

template<class TIPO>
void Lista<TIPO>::returnLista() {
    //recupera uma lista de elementos<TIPO> de um arquivo .txt essa função sobrepoe os objetos criados em tempo de execução
    //util para terminar a execução sem alterar a base de dados
}

