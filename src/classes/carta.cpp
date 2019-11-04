#include "classes/carta.hpp"

using namespace poker;

Carta::Carta() : Carta((Naipe)0, (Simbolo)0) {}

Carta::Carta(int naipe, int sim) : Carta((Naipe)naipe, (Simbolo)sim) {}

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
