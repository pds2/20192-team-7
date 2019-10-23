#include <poker/Baralho.hpp>
#include <vector>
using namespace baralho;

Baralho::embaralhar(){
	// para cada naipe, instanciar todas as cartas

	// o vetor Cartas da classe baralho será um vetor com todas as cartas instanciadas
}

Baralho::distribuirCartas(int numeroCartas){
	if (numeroCartas <= cartas.size()){
		for(int i = 0; i < numeroCartas; i++){
			// gerar número aleatório
			cartaRetirada = cartas.at(numeroGerado);
			cartas.resize(cartas.size() - 1);
		}
	} 
	else{
		// throw exception
	}
}