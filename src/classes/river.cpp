#include "classes/river.hpp"
#include "classes/carta.hpp"

#include <vector>

using namespace poker;

River::River(Baralho* baralho) : EstadoJogo(baralho){
}

void River::distribuirCartas(Mesa* mesa) {
    std::vector<Carta> cartasMesa = this->baralho->distribuirCartas(1);
    mesa->addCartas(cartasMesa);
}

bool River::validarApostas(unsigned int valorAposta, Jogador* jogador) {
    return (jogador->getNumeroFichas() >= valorAposta);
}