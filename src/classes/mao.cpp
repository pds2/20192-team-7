#include "classes/mao.hpp"
#include "classes/pokerExceptions.hpp"

using namespace poker;

Mao::Mao(Carta primeira, Carta segunda) {
	if(this->cartas.empty){
		this->cartas.push_back(primeira);
		this->cartas.push_back(segunda);
	}
	else{
		throw(PokerError("A mçao já possui cartas!"));
	}
}

std::vector<Carta> Mao::getCartas(){
	return this->cartas;
}