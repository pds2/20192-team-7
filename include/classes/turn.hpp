#include "classes/estadojogo.hpp"

#ifndef ESTADO_JOGO_TURN_H
#define ESTADO_JOGO_TURN_H

namespace poker {
	
    class Turn : public EstadoJogo {

        public:
            Turn(Baralho* baralho);

            void distribuirCartas(Mesa* mesa) override;
            bool validarApostas(unsigned int valorAposta, Jogador* jogador) override;
    };
}

#endif