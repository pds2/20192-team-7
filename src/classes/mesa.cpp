#include "classes/mesa.hpp"

using namespace poker;

Mesa::Mesa(){
    this->pote = Pote();
}

Mesa::Mesa(Pote pote){
    this->pote = pote;
}

void Mesa::addCartas(std::vector<Carta> cartasMesa){
    if (cartasMesa.size() <= 5)
        this->cartasMesa = cartasMesa;
}

std::vector<Carta> Mesa::getCartasMesa(){
    return (this->cartasMesa);
}

void Mesa::setPoteApostaTotal(int valorTotal){
    this->pote.setValorTotal(valorTotal);
}

void Mesa::setPoteApostaAtual(int valorAtual){
    this->pote.setValorApostaAtual(valorAtual);
}

void Mesa::setPoteApostaAnterior(int valorAnterior){
    this->pote.setValorApostaAnterior(valorAnterior);
}

int Mesa::getPoteTotal(){
    return(this->pote.getValorTotal());
}

int Mesa::getPoteApostaAtual(){
    return(this->pote.getValorApostaAtual());
}

int Mesa::getPoteApostaAnterior(){
    return(this->pote.getValorApostaAnterior());
}
