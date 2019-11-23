#include "classes/estadojogo.hpp"

#ifndef ESTADO_JOGO_FLOP_H
#define ESTADO_JOGO_FLOP_H

namespace poker {
	
    class Flop : public EstadoJogo {

        public:
            Flop();

            void distribuirCartas(Mesa mesa) override;
            bool validarApostas(int valorAposta, JogadorHumano jogadorHumano) override;
            void verificarOpcoesJogador() override;
    };
}

#endif