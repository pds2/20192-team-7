#include "classes/mesa.hpp"
#include <vector>

Mesa::Mesa(){ //TODO: Construtor do objeto Mesa

}

void Mesa::addCartas(std::vector<Carta> cartasMesa){
    if (cartasMesa.size() <= 5)
        this->cartasMesa = cartasMesa;
    else
        //Exceção de excesso de cartas
}


