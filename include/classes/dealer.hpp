#include "classes/estadojogo.hpp"

#ifndef DEALER_H
#define DEALER_H

namespace poker {
    
    class Dealer {
        private:
            unsigned int numeroJogadores;
            EstadoJogo momentoJogo;
            
        public:
            Dealer();

            Dealer(EstadoJogo momentoJogo, unsigned int numeroJogadores);
            
            void setEstadoJogo();
            void setNumeroJogadores();
            
            EstadoJogo getMomentoJogo();
            int getNumeroJogadores();

    };
}
#endif