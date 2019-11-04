#include <vector>

#ifndef POKER_BARALHO
#define POKER_BARALHO

namespace poker {
    
    class Baralho {
    	
        private:
            std::vector<Carta> cartas;
            
        public:

            void embaralhar();
            std::vector<Carta> distribuirCartas(int numeroCartas);
    };
}

#endif