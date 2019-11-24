#include "classes/estadojogo.hpp"

#ifndef ESTADO_JOGO_PRE_FLOP_H
#define ESTADO_JOGO_PRE_FLOP_H

namespace poker {
	
    class PreFlop : public EstadoJogo {

        public:
            PreFlop();
            PreFlop(Baralho* baralho);

            void distribuirCartas(Mesa* mesa) override;
            void distribuirCartasJogadores(std::vector<Jogador> jogadores);
            bool validarApostas(int valorAposta, Jogador* jogador) override;
    };
}

#endif