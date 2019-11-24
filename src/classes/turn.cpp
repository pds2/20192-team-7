#include "classes/turn.hpp"
#include "classes/carta.hpp"

#include <vector>

using namespace poker;

Turn::Turn() : EstadoJogo(){
}

Turn::Turn(Baralho* baralho) : EstadoJogo(baralho){
}

void Turn::distribuirCartas(Mesa* mesa) {
    std::vector<Carta> cartasMesa = this->baralho->distribuirCartas(1);
    mesa->addCartas(cartasMesa);
}

bool Turn::validarApostas(int valorAposta, Jogador* jogador) {
    return (jogador->getNumeroFichas() >= valorAposta);
}