#include "carta.hpp"

using namespace poker;

void Carta::Carta(int naip, int sim){
	this->naipe = naipe;
	this->simbolo = sim;
}

int Carta::getNaipe(){
	return this->naipe;
}

int Carta::getSimbolo(){
	return this->simbolo;
}
