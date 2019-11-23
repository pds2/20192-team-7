#include "classes/estadojogo.hpp"

#ifndef ESTADO_JOGO_FLOP_H
#define ESTADO_JOGO_FLOP_H

namespace poker {
	
    class Flop : public EstadoJogo {

        public:
            Flop();
            Flop(Baralho* baralho);

            void distribuirCartas(Mesa* mesa) override;
            bool validarApostas(int valorAposta, Jogador* jogador) override;
    };
}

#endif