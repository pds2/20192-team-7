#include "classes/pote.hpp"

using namespace poker;

Pote::Pote() : Pote(0,0,0) {}

Pote::Pote(unsigned int valorTotal,unsigned int valorApostaAtual,unsigned int valorApostaAnterior) : 
	valorTotal(valorTotal),	valorApostaAtual(valorApostaAtual), valorApostaAnterior(valorApostaAnterior) {
}

void Pote::setValorTotal(unsigned int valorTotal){
    this -> valorTotal = valorTotal; 
}

void Pote::setValorApostaAtual(unsigned int valorApostaAtual){
    this -> valorApostaAtual = valorApostaAtual; 
}

void Pote::setValorApostaAnterior(unsigned int valorApostaAnterior){
    this -> valorApostaAnterior = valorApostaAnterior; 
}

unsigned int Pote::getValorTotal(){
    return this -> valorTotal; 
}

unsigned int Pote::getValorApostaAtual(){
    return this -> valorApostaAtual; 
}

unsigned int Pote::getValorApostaAnterior(){
    return this -> valorApostaAnterior; 
}

