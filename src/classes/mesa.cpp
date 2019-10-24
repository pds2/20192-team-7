#include <classes/mesa.hpp>

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
    else
        //Exceção de excesso de cartas
}


//TODO: Setters e Getters de Pote

int Mesa::getPoteApostaAnterior(){
    return(0);
}

int Mesa::getPoteApostaAtual(){
    return(0);
}

int Mesa::getPoteApostaTotal(){
    return(0);
}

int Mesa::setPoteApostaAnterior(){
    return;
}

int Mesa::setPoteApostaAtual(){
    return;
}

int Mesa::setPoteApostaTotal(){
    return;
}