#include <classes/jogador.hpp>
using namespace poker;

Jogador::Jogador(int numeroFichas, Pote pote){
    this->mao = nullptr;
    this->pote = &pote;
    this->numeroFichas = numeroFichas;
}

void Jogador::setMao(Mao mao){
    this->mao = &mao;
}

Mao Jogador::getMao(){
    return (*this->mao);
}

void Jogador::pagarAposta(){
    int valorApostaAnterior = this->pote->getValorApostaAnterior();
    if ((this->numeroFichas - valorApostaAnterior) >= 0){
        this->numeroFichas -= valorApostaAnterior;
        this->pote->alterarValorTotal(2*valorApostaAnterior);
    }
}

void Jogador::aumentarAposta(unsigned int valorAposta){
    
}

void Jogador::desistirDaPartida(){

}

void Jogador::passarVez(){

}

void Jogador::analisarMao(){

}