#include "classes/estadojogo.hpp"
#include "classes/pote.hpp"
#include "classes/mesa.hpp"

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
            
        public:
            Dealer();

            Dealer(EstadoJogo momentoJogo, unsigned int numeroJogadores);
            
            void setEstadoJogo(EstadoJogo momentoJogo);
            void setNumeroJogadores(unsigned int numeroJogadores);
            
            EstadoJogo getMomentoJogo();
            int getNumeroJogadores();

            void inserirJogadores();
            void distribuirFichas(unsigned int numeroFichas);
            void iniciarPartida(unsigned int numeroJogadores);
            void entregarPremio(Jogador* jogadorVencedor);
            void iniciarPreFlop();
    };
}
#endif