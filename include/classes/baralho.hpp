#include "classes/carta.hpp"
#include <vector>

#ifndef POKER_BARALHO
#define POKER_BARALHO

namespace poker {
    
    class Baralho {
    	
        private:
            std::vector<Carta*> cartas;
            
        public:

            std::vector<Carta*> getCartas();

            void embaralhar();
            std::vector<Carta*> distribuirCartas(unsigned int numeroCartas);
    };
}

#endif