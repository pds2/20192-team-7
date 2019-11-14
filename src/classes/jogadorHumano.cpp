#include <classes/jogadorHumano.hpp>
#include <classes/jogador.hpp>
#include <vector>
using namespace poker;

JogadorHumano::JogadorHumano(std::string nome, int numeroFichas, Pote* pote, Mesa* mesa){
    this->mao = nullptr;
    this->pote = pote;
    this->mesa = mesa;
    this->numeroFichas = numeroFichas;
    this->nome = nome;
}

Pote* JogadorHumano::getPote(){
    return this->pote;
}

Mesa* JogadorHumano::getMesa(){
    return this->mesa;
}

int JogadorHumano::getNumeroFichas(){
    return this->numeroFichas;
}

void JogadorHumano::comecarPartida(){
    Jogador("Clinky", getNumeroFichas(), getPote(), getMesa());
    Jogador("Adilson", getNumeroFichas(), getPote(), getMesa());
    Jogador("Taylor Swift", getNumeroFichas(), getPote(), getMesa());


}

void JogadorHumano::finalizarPartida(){

}