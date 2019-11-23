#include "classes/pote.hpp"
#include "classes/pokerExceptions.hpp"

using namespace poker;

Pote::Pote() : Pote(0,0,0) {}

Pote::Pote(int valorTotal, int valorApostaAtual, int valorApostaAnterior) : 
	valorTotal(valorTotal),	valorApostaAtual(valorApostaAtual), valorApostaAnterior(valorApostaAnterior) {
}

void Pote::setValorTotal(int valorTotal){
    if(valorTotal < 2000*4)
        this -> valorTotal = valorTotal;
    else
        throw(PokerError("Total de fichas ultrapassado!"));
     
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

