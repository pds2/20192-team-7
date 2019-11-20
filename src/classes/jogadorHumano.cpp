#include <classes/jogadorHumano.hpp>
#include <classes/jogador.hpp>
#include <vector>
#include <classes/dealer.hpp>
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

std::vector<Jogador*> JogadorHumano::comecarPartida(){
    std::vector<Jogador*>bots;
    Jogador *Clinky = new Jogador("Clinky", getNumeroFichas(), getPote(), getMesa());
    Jogador *Adilson = new Jogador("Adilson", getNumeroFichas(), getPote(), getMesa());
    Jogador *Taylor = new Jogador("Taylor Swift", getNumeroFichas(), getPote(), getMesa());
    bots.push_back(Clinky);
    bots.push_back(Adilson);
    bots.push_back(Taylor);
    return bots;
}

void JogadorHumano::finalizarPartida(std::vector<Jogador*>bots){
    for(Jogador* valor : bots){
        delete valor;
    }
}