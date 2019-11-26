#include "classes/preflop.hpp"
#include "classes/carta.hpp"
#include <iostream>
#include <vector>

using namespace poker;

PreFlop::PreFlop(Baralho* baralho) : EstadoJogo(baralho){
}

void PreFlop::distribuirCartas(Mesa* mesa) {
    throw(PokerError("Método não deve ser chamado."));
}

void PreFlop::distribuirCartasJogadores(std::vector<Jogador*> jogadores, JogadorHumano* jogadorHumano) {
    for(Jogador* player : jogadores){
        Mao* mao = new Mao();
        mao->setCartas(this->baralho->distribuirCartas(2));
        player->setMao(mao);
    }
    Mao* mao = new Mao();
    mao->setCartas(this->baralho->distribuirCartas(2));
    jogadorHumano->setMao(mao);
}

bool PreFlop::validarApostas(unsigned int valorAposta, Jogador* jogador) {
    return (jogador->getNumeroFichas() >= valorAposta);
}