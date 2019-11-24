#include "classes/estadojogo.hpp"

#ifndef ESTADO_JOGO_RIVER_H
#define ESTADO_JOGO_RIVER_H

namespace poker {
	
    class River : public EstadoJogo {

        public:
            River();
            River(Baralho* baralho);

            void distribuirCartas(Mesa* mesa) override;
            bool validarApostas(int valorAposta, Jogador* jogador) override;
    };
}

#endif