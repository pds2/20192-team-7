#include <classes/mesa.hpp>
#include <vector>

//TODO: Definir corretamente os parâmetros do construtor do Pote
Mesa::Mesa(){
    this->pote = Pote();
}

void Mesa::addCartas(std::vector<Carta> cartasMesa){
    if (cartasMesa.size() <= 5)
        this->cartasMesa = cartasMesa;
    else
        //Exceção de excesso de cartas
}

//TODO: Setters e Getters de Pote

int Mesa::getPoteAnterior(){
    return(0);
}

int Mesa::getPoteAtual(){
    return(0);
}

int Mesa::getPoteTotal(){
    return(0);
}

int Mesa::setPoteAnterior(){
    return;
}

int Mesa::setPoteAtual(){
    return;
}

int Mesa::setPoteTotal(){
    return;
}