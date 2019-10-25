#include "baralho.hpp"
#include <vector>
#include <stdlib.h>
#include "naipe.hpp"
#include "naipe.hpp"
#include "simbolo.hpp"

using namespace poker;

Baralho::embaralhar (){
	for(int n = 0; n < 4; n++){
		for(int s = 0; s < 13; s++){
			Carta carta = new Carta((Naipe)n, (Simbolo)s);
			cartas.push_back(carta);
		}
	}
}

Baralho::distribuirCartas (int numeroCartas){
	if (numeroCartas <= cartas.size()){
		for(int i = 0; i < numeroCartas; i++){
			int numeroGerado = rand() % cartas.size();
			cartas.erase(cartas.at(numeroGerado));
			cartas.resize(cartas.size() - 1);
		}
	} 
}