#include "classes/mao.hpp"

using namespace poker;

Mao::Mao(Carta &primeira, Carta &segunda) {
	cartas[0] = primeira;
	cartas[1] = segunda;
}

Carta* Mao::getCartas(){
	return this->cartas;
}