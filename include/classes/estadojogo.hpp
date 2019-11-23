#include "classes/mesa.hpp"
#include "classes/jogadorHumano.hpp"
#include "classes/baralho.hpp"

#ifndef ESTADO_JOGO_H
#define ESTADO_JOGO_H

namespace poker {
	
    class EstadoJogo {
        protected:
            Baralho* baralho;

        public:
            EstadoJogo(Baralho* baralho) {
                this->baralho = baralho;
            }

            virtual void distribuirCartas(Mesa* mesa);
            virtual bool validarApostas(int valorAposta, Jogador* jogador);
            virtual void verificarOpcoesJogador();
    };
}

#endif