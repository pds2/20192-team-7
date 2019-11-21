#include "dealer.hpp"

using namespace poker;

Dealer:Dealer(){
}

Dealer::Dealer(EtapaJogo momentoJogo, unsigned int numeroJogadores){
	this->momentoJogo = momentoJogo;
	this->numeroJogadores = numeroJogadores;
}

void Dealer::setEtapaJogo(EpataJogo momentoJogo){
	this->momentoJogo=momentoJogo;
}

void Dealer::setNumeroJogadores(unsigned int numeroJogadores){
	this->numeroJogadores=numeroJogadores;
}

EtapaJogo Dealer::getMomentoJogo(){
	return this->momentoJogo;
}

int Dealer::getNumeroJogadores(){
	return this->numeroJogadores;
}