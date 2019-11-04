#include "classes/carta.hpp"

using namespace poker;

Carta::Carta() : Carta(0, 0) {}

Carta::Carta(Naipe naipe, Simbolo sim){
	this->naipe = naipe;
	this->simbolo = sim;
}

int Carta::getNaipe(){
	return this->naipe;
}

int Carta::getSimbolo(){
	return this->simbolo;
}
