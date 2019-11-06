#include <classes/jogador.hpp>
using namespace poker;

Jogador::Jogador(){
    this->numeroFichas = 2000;
}

void Jogador::PagarAposta(unsigned int valorAposta){
    if ((this->numeroFichas - valorAposta) >= 0)
        this->numeroFichas -= valorAposta;
    }

