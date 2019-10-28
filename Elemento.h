//
// Created by simao on 16/04/19.
//
#pragma once

//adicionar uma função de adicionar primeiro elemento à lista, para fins de coesão
    //e então tirar essa parte da Lista::includeElemento

template<class TIPO> class Elemento{
private:
    Elemento<TIPO>* prox;
    Elemento<TIPO>* ante;
    TIPO* pInfo;
public:
    Elemento() {prox= nullptr; ante= nullptr; pInfo= nullptr;}
    Elemento(TIPO* el);
    ~Elemento() {prox= nullptr; ante= nullptr; pInfo= nullptr;}
    Elemento<TIPO> *getProx() const;
    Elemento<TIPO> *getAnte() const;
    void setProx(Elemento<TIPO>* px);
    void setAnte(Elemento<TIPO>* at);
    void setInfo(const TIPO& info);
    TIPO* getInfo();
    TIPO* operator*(Elemento<TIPO>* aux);
};

template<class TIPO>
Elemento<TIPO>::Elemento(TIPO *el) {
    prox= nullptr;
    ante= nullptr;
    setInfo(el);
}

template<class TIPO>
Elemento<TIPO> *Elemento<TIPO>::getProx() const {
    return prox;
}

template<class TIPO>
Elemento<TIPO> *Elemento<TIPO>::getAnte() const {
    return ante;
}

template<class TIPO>
void Elemento<TIPO>::setProx(Elemento<TIPO> *px) {
    prox=px;
}

template<class TIPO>
void Elemento<TIPO>::setAnte(Elemento<TIPO> *at) {
    ante=at;
}

template<class TIPO>
void Elemento<TIPO>::setInfo(const TIPO& info) {
    pInfo=info;
}

template<class TIPO>
TIPO* Elemento<TIPO>::getInfo() {
    return pInfo;
}

template<class TIPO>
TIPO *Elemento<TIPO>::operator*(Elemento<TIPO> *aux) {
    return getInfo();
}
