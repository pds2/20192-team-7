#include <classes/jogador.hpp>
using namespace poker;

Jogador::Jogador(Carta primeira, Carta segunda){
    this->mao = Mao(primeira, segunda);
    this->numeroFichas = 2000;
}

