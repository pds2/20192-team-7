#include "classes/preflop.hpp"
#include "classes/carta.hpp"

#include <vector>

using namespace poker;

PreFlop::PreFlop() : EstadoJogo(){
}

PreFlop::PreFlop(Baralho* baralho) : EstadoJogo(baralho){
}

void PreFlop::distribuirCartas(Mesa* mesa) {
    throw(PokerError("Método não deve ser chamado."));
}

void PreFlop::distribuirCartasJogadores(std::vector<Jogador> jogadores) {
    for(Jogador player : jogadores){
        Mao mao = Mao();
        mao.setCartas(this->baralho->distribuirCartas(2));
        player.setMao(&mao);
    }
}

bool PreFlop::validarApostas(int valorAposta, Jogador* jogador) {
    return (jogador->getNumeroFichas() >= valorAposta);
}