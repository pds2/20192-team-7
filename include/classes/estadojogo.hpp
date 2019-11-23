#include "classes/mesa.hpp"
#include "classes/jogadorHumano.hpp"

#ifndef ESTADO_JOGO_H
#define ESTADO_JOGO_H

namespace poker {
	
    class EstadoJogo {

        public:
            EstadoJogo();

            virtual void distribuirCartas(Mesa* mesa);
            virtual bool validarApostas(int valorAposta, Jogador* jogador);
            virtual void verificarOpcoesJogador();
    };
}

#endif