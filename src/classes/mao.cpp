#include "classes/mao.hpp"
#include "classes/pokerExceptions.hpp"
#include <iostream>

using namespace poker;

Mao::Mao(Carta* primeira, Carta* segunda) {
	if(this->cartas.empty()){
		this->cartas.push_back(primeira);
		this->cartas.push_back(segunda);
	}
	else{
		throw(PokerError("A mão já possui cartas!"));
	}
}

Mao::Mao(){}

std::vector<Carta*> Mao::getCartas(){
	return this->cartas;
}

void Mao::setCartas(std::vector<Carta*> cartas){
	this->cartas = cartas;
}