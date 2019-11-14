#include <classes/jogador.hpp>
#include <string>

#ifndef JOGADOR_HUMANO
#define JOGADOR_HUMANO

namespace poker{

    class JogadorHumano : public Jogador{

        public:

            JogadorHumano(std::string nome, int numeroFichas, Pote* pote, Mesa* mesa);
            void comecarPartida();
            void finalizarPartida();
            Pote* getPote();
            Mesa* getMesa();
            int getNumeroFichas();

    };

}

#endif
