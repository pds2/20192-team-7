#include <vector>
#include "classes/carta.hpp"

#ifndef POKER_BARALHO
#define POKER_BARALHO

namespace poker {
    
    class Baralho {
    	
        private:
            std::vector<Carta*> cartas;
            
        public:

            void embaralhar();
            std::vector<Carta*> distribuirCartas(unsigned int numeroCartas);
            std::vector<Carta*> getCartas();
    };
}

#endif