#include <mesa.hpp>
#ifndef ESTADO_JOGO_H
#define ESTADO_JOGO_H

namespace poker {
    class EstadoJogo {
        public:
            EstadoJogo();
            virtual bool validarApostas(int valorAposta, *JogadorHumano jogadorHumano);
            virtual void distribuirCartas(*Mesa mesa);
            virtual void verificarOpcoesJogador();
    };
}

#endif