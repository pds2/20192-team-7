#include "classes/mesa.hpp"
#include "classes/jogadorHumano.hpp"
#include "classes/baralho.hpp"
#include "classes/pote.hpp"

#include <map>
#include <string>

#ifndef ESTADO_JOGO_H
#define ESTADO_JOGO_H

namespace poker {
	
    class EstadoJogo {
        protected:
            Baralho* baralho;

        public:
            EstadoJogo();
            EstadoJogo(Baralho* baralho);
            
            virtual void distribuirCartas(Mesa* mesa);
            virtual bool validarApostas(unsigned int valorAposta, Jogador* jogador);
            std::map<std::string, bool> verificarOpcoesJogador(Jogador* jogador, Pote* pote);
            std::map<std::string, bool> verificarOpcoesJogador(JogadorHumano* jogador, Pote* pote);
    };
}

#endif