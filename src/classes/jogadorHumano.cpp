#include "classes/jogadorHumano.hpp"
#include "classes/jogador.hpp"
#include "classes/dealer.hpp"
#include "classes/pokerExceptions.hpp"

#include <vector>

using namespace poker;

JogadorHumano::JogadorHumano(std::string nome, int numeroFichas, Pote* pote, Mesa* mesa) : Jogador(nome, numeroFichas, pote, mesa){
}

JogadorHumano::JogadorHumano(std::string nome, Pote* pote, Mesa* mesa) : Jogador(nome, pote, mesa){
}


Pote* JogadorHumano::getPote(){
    return this->pote;
}

Mesa* JogadorHumano::getMesa(){
    return this->mesa;
}

void JogadorHumano::finalizarJogo(){
    throw (FimJogo());
}

void JogadorHumano::desistirDaPartida(){
    throw (FimRodada());
}

void JogadorHumano::jogar(map<std::string, bool> opcoesJogador, Pote* pote){
    // verificar opções de ação
	// exibir na tela as opções de ação pro jogador


	// switch para a opção escolhida, executar e passar pro próximo jogador
		// tratar exceções
}
