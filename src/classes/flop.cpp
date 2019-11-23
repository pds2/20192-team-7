#include "classes/flop.hpp"
#include "classes/baralho.hpp"
#include "classes/carta.hpp"
#include <vector>

using namespace poker;

Flop::Flop(Baralho* baralho) : EstadoJogo(baralho){

}

void Flop::distribuirCartas(Mesa* mesa) {
    std::vector<Carta> cartasMesa = this->baralho->distribuirCartas(3);
    mesa->addCartas(cartasMesa);
}

bool Flop::validarApostas(int valorAposta, Jogador* jogador) {
    return false;
}

void Flop::verificarOpcoesJogador() {}
