#include "classes/estadojogo.hpp"
#include "classes/pote.hpp"
#include "classes/mesa.hpp"
#include "classes/preflop.hpp"
#include "classes/flop.hpp"
#include "classes/turn.hpp"
#include "classes/river.hpp"

#ifndef DEALER_H
#define DEALER_H

namespace poker {
    
    class Dealer {
        private:
            unsigned int numeroJogadores;
            EstadoJogo momentoJogo;
            std::vector<Jogador> jogadores;
            Pote* pote;
            Mesa* mesa;
            Baralho* baralho;

            void jogada(Jogador jogador);
            void jogada(JogadorHumano jogador);
            void iniciarJogadas();

            void iniciarEstadoJogo (PreFlop* estadoJogo);
            void iniciarEstadoJogo (Flop* estadoJogo);
            void iniciarEstadoJogo (Turn* estadoJogo);
            void iniciarEstadoJogo (River* estadoJogo);

            void mostrarMaoAtualJogador(Jogador jogador);
            
        public:
            Dealer();

            Dealer(EstadoJogo momentoJogo, unsigned int numeroJogadores);
            
            void setEstadoJogo(EstadoJogo momentoJogo);
            void setNumeroJogadores(unsigned int numeroJogadores);
            
            EstadoJogo getMomentoJogo();
            int getNumeroJogadores();

            void inserirJogadores();
            void distribuirFichas(unsigned int numeroFichas);
            void iniciarJogo(unsigned int numeroJogadores);
            void iniciarPartida();
            void entregarPremio(Jogador* jogadorVencedor);

    };
}
#endif