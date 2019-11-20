#include <classes/jogador.hpp>
#include <string>
#include <classes/dealer.hpp>

#ifndef JOGADOR_HUMANO
#define JOGADOR_HUMANO

namespace poker{

    class JogadorHumano : public Jogador{

        public:

            JogadorHumano(std::string nome, int numeroFichas, Pote* pote, Mesa* mesa);
            std::vector<Jogador*> comecarPartida();
            void finalizarPartida();
            Pote* getPote();
            Mesa* getMesa();
            int getNumeroFichas();

    };

}

#endif
