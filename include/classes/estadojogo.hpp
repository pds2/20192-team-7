#include "classes/mesa.hpp"
#include "classes/jogadorHumano.hpp"

#ifndef ESTADO_JOGO_H
#define ESTADO_JOGO_H

namespace poker {
	
    class EstadoJogo {

        public:
            EstadoJogo();

            virtual void distribuirCartas(Mesa mesa) = 0;
            virtual bool validarApostas(int valorAposta, JogadorHumano jogadorHumano) = 0;
            virtual void verificarOpcoesJogador() = 0;
    };
}

#endif