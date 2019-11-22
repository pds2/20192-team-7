#include "classes/jogador.hpp"
#include <string>

#ifndef JOGADOR_HUMANO
#define JOGADOR_HUMANO

namespace poker {

    class JogadorHumano : public Jogador {

        public:
            JogadorHumano(std::string nome, int numeroFichas, Pote* pote, Mesa* mesa);
            JogadorHumano(std::string nome, Pote* pote, Mesa* mesa);
            
            Pote* getPote();
            Mesa* getMesa();

            void finalizarPartida(std::vector<Jogador*>bots);
    };

}

#endif
