#include "classes/pote.hpp"

using namespace poker;

Pote::Pote() : Pote(0,0,0) {}

Pote::Pote(int valorTotal, int valorApostaAtual, int valorApostaAnterior) : 
	valorTotal(valorTotal),	valorApostaAtual(valorApostaAtual), valorApostaAnterior(valorApostaAnterior) {
}

void Pote::setValorTotal(int valorTotal){
    this -> valorTotal = valorTotal; 
}

void Pote::setValorApostaAtual(int valorApostaAtual){
    this -> valorApostaAtual = valorApostaAtual; 
}

void Pote::setValorApostaAnterior(int valorApostaAnterior){
    this -> valorApostaAnterior = valorApostaAnterior; 
}

int Pote::getValorTotal(){
    return this -> valorTotal; 
}

int Pote::getValorApostaAtual(){
    return this -> valorApostaAtual; 
}

int Pote::getValorApostaAnterior(){
    return this -> valorApostaAnterior; 
}

