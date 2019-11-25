#include "classes/baralho.hpp"
#include "enums/naipe.hpp"
#include "enums/simbolo.hpp"
#include "classes/pokerExceptions.hpp"
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <chrono>

using namespace poker;

std::vector<Carta*> embaralharCartas(std::vector<Carta*> baralho)
{
	unsigned seed = std::chrono::system_clock::now()
						   .time_since_epoch()
						   .count();

	shuffle (baralho.begin(), baralho.end(), std::default_random_engine(seed));
	return baralho;

}

void Baralho::embaralhar (){
	for (int n = 0; n < 4; n++){

		for (int s = 0; s < 13; s++){
			Carta* carta = new Carta(n, s);
			cartas.push_back(carta);
		}
	}

	cartas = embaralharCartas(cartas);
}

std::vector<Carta*> Baralho::distribuirCartas (unsigned int numeroCartas){

	std::vector<Carta*> cartasDistribuidas;
	
	if (numeroCartas <= cartas.size()){
		
		for (unsigned int i = 0; i < numeroCartas; i++){
			int numeroGerado = rand() % cartas.size();
			cartasDistribuidas.push_back(cartas.at(numeroGerado));

			cartas.erase(cartas.begin() + numeroGerado);
			cartas.resize(cartas.size() - 1);
		}
	}
	else {
		throw (PokerError("Cartas insuficientes no baralho!"));
	}
	

	return cartasDistribuidas;
}

std::vector<Carta*> Baralho::getCartas(){
	return this->cartas;
}