#include "etapajogo.hpp"

#ifndef POKER_BARALHO
#define POKER_BARALHO

namespace poker {
    
    class Dealer {
        private:
            unsigned int numeroJogadores;
            EtapaJogo momentoJogo;
            
        public:
            Dealer();

            Dealer(EtapaJogo momentoJogo, unsigned int numeroJogadores);
            
            void setEtapaJogo();
            void setNumeroJogadores();
            
            EtapaJogo getMomentoJogo();
            int getNumeroJogadores();

    };
}
#endif