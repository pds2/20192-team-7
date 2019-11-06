#include <classes/jogador.hpp>
using namespace poker;

Jogador::Jogador(){
    this->mao = nullptr;
    this->numeroFichas = 2000;
}

void Jogador::setMao(Mao mao){
    this->mao = &mao;
}

Mao Jogador::getMao(){
    return (*this->mao);
}

void Jogador::pagarAposta(unsigned int valorAposta){
    if ((this->numeroFichas - valorAposta) >= 0)
        this->numeroFichas -= valorAposta;
}

void Jogador::aumentarAposta(){

}

void Jogador::desistirDaPartida(){

}

void Jogador::passarVez(){

}

void Jogador::analisarMao(){

}