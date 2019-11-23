#include "classes/baralho.hpp"
#include <vector>
#include <stdlib.h>
#include "enums/naipe.hpp"
#include "enums/simbolo.hpp"

using namespace poker;

void Baralho::embaralhar (){
	for (int n = 0; n < 4; n++){

		for (int s = 0; s < 13; s++){
			Carta carta = Carta(n, s);
			cartas.push_back(carta);
		}
	}
}

std::vector<Carta> Baralho::distribuirCartas (unsigned int numeroCartas){
	std::vector<Carta> cartasDistribuidas;
	
	if (numeroCartas <= cartas.size()){
		
		for (unsigned int i = 0; i < numeroCartas; i++){
			int numeroGerado = rand() % cartas.size();
			cartasDistribuidas.push_back(cartas.at(numeroGerado));
			cartas.erase(cartas.begin() + numeroGerado);
			cartas.resize(cartas.size() - 1);
		}
	}

	return cartasDistribuidas;
}