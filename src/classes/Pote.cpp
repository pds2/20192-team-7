#include 'Pote.h'

using namespace poker;

Pote::Pote() : Pote(0,0,0) {}

Pote::Pote(int valorTotal,int valorApostaAtual, int valorApostaAnterior) : valorTotal(valorTotal),valorApostaAtual(valorApostaAtual),valorApostaAnterior(valorApostaAnterior) {}

void Pote::setValorTotal(int valorAtual){
    this -> valorAtual = valorAtual; 
}

void Pote::setValorApostaAtual(int valorApostaAtual){
    this -> valorApostaAtual = valorApostaAtual; 
}

void Pote::setValorApostaAnterior(int valorApostaAnterior){
    this -> valorApostaAnterior = valorApostaAnterior; 
}

int Pote::getValorTotal(){
    return this -> valorAtual; 
}

int Pote::getValorApostaAtual(){
    return this -> valorApostaAtual; 
}

int Pote::getValorApostaAnterior(){
    return this -> valorApostaAnterior; 
}

void Pote::alterarValorAposta(int novoValorAposta){
    this -> valorAtual = novoValorAposta; 
}

void Pote::substituirApostaAnterior(int novoValorApostaAnterior){
    this -> valorApostaAnterior = novoValorApostaAnterior; 
}

void Pote::alterarValorTotal(int novoValorTotal){
    this -> valorTotal = novoValorTotal; 
}