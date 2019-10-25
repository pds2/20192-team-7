#include "carta.hpp"

using namespace poker;

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
