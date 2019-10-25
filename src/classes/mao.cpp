#include "mao.hpp"

using namespace poker;

Mao::Mao(Carta primeira, Carta segunda) {
	this->cartas[0] = primeira;
	this->cartas[1] = segunda;
}

Carta* Mao::getCartas(){
	return this->cartas;
}