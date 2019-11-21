#include "classes/mao.hpp"

using namespace poker;

Mao::Mao(Carta primeira, Carta segunda) {
	this->cartas.push_back(primeira);
	this->cartas.push_back(segunda);
}

std::vector<Carta> Mao::getCartas(){
	return this->cartas;
}