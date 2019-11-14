#include <classes/carta.hpp>
using namespace poker;

JogadorHumano::JogadorHumano(std::string nome, int numeroFichas, Pote* pote, Mesa* mesa){
    this->mao = nullptr;
    this->pote = pote;
    this->mesa = mesa;
    this->numeroFichas = numeroFichas;
    this->nome = nome;
}

void JogadorHumano::comecarPartida(){

}

void JogadorHumano::finalizarPartida(){
    
}