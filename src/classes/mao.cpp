#include "classes/mao.hpp"

using namespace poker;

Mao::Mao(Carta primeira, Carta segunda) {
	this->cartas.push_back(primeira);
	this->cartas.push_back(segunda);
}

Mao::Mao(){}

std::vector<Carta> Mao::getCartas(){
	return this->cartas;
}

void Mao::setCartas(std::vector<Carta> cartas){
	this->cartas = cartas;
}