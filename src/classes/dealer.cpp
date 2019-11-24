#include "classes/dealer.hpp"
#include "classes/preflop.hpp"
#include <iterator>
#include <iostream>

using namespace poker;

#define FICHAS_POR_JOGADOR 2000

Dealer::Dealer() {
	this->pote = new Pote();
	this->mesa = new Mesa();
	this->baralho = new Baralho();
}

Dealer::Dealer(EstadoJogo momentoJogo, unsigned int numeroJogadores){
	Dealer();
	this->momentoJogo = momentoJogo;
	this->numeroJogadores = numeroJogadores;
}

void Dealer::setEstadoJogo(EstadoJogo momentoJogo){
	this->momentoJogo = momentoJogo;
}

void Dealer::setNumeroJogadores(unsigned int numeroJogadores){
	this->numeroJogadores = numeroJogadores;
}

EstadoJogo Dealer::getMomentoJogo(){
	return this->momentoJogo;
}

int Dealer::getNumeroJogadores(){
	return this->numeroJogadores;
}


void Dealer::inserirJogadores(){
    Jogador bots[7] = {
		Jogador("Clinky", pote, mesa),
		Jogador("Adilson", pote, mesa),
		Jogador("Taylor Swift", pote, mesa),
		Jogador("Bryan", pote, mesa),
		Jogador("Julio", pote, mesa),
		Jogador("Ricky", pote, mesa),
		Jogador("Morty", pote, mesa),
	}; 

	unsigned int i; 
	for (i = 0; i < numeroJogadores; i++)
    	(this->jogadores).push_back(bots[i]);
	
	this->jogadores.push_back(JogadorHumano("Player", pote, mesa));
}

void Dealer::distribuirFichas(unsigned int numeroFichas){
	std::vector<Jogador*>::iterator it;

	for (it = this->jogadores.begin() ; it != this->jogadores.end(); ++it){
		(*it)->setNumeroFichas(numeroFichas);
	}
}

void Dealer::iniciarPartida(unsigned int numeroJogadores){
	setNumeroJogadores(numeroJogadores);
	distribuirFichas(FICHAS_POR_JOGADOR);
	inserirJogadores();
}

void Dealer::entregarPremio(Jogador* jogadorVencedor){
	jogadorVencedor->setNumeroFichas(this->pote->getValorTotal());
	
	this->pote->setValorTotal(0);
	this->pote->setValorApostaAtual(0);
	this->pote->setValorApostaAnterior(0);
}

void Dealer::iniciarPreFlop(){
	PreFlop preFlop = PreFlop(this->baralho);
	preFlop.distribuirCartasJogadores(this->jogadores);
	this->momentoJogo = preFlop;
}

void Dealer::verificarResultadoPartida(){
	std::vector<Jogador> jogadores = this->jogadores;
	std::vector<Jogador> vencedoresPotencias;
	for(Jogador jogador : jogadores){
		if(jogador.getNumeroFichas() > 0 ){
			vencedoresPotencias.push_back(jogador);
		}
	}

	if(vencedoresPotencias.size() == 1 && vencedoresPotencias.at(0).getNumeroFichas() > 0){
		std::cout << "O vencedor foi o jogador : " << vencedoresPotencias.at(0).getNome() << " com " << vencedoresPotencias.at(0).getNumeroFichas() << "fichas";
	}else{
		throw(PokerError("Método chamado no momento errado, mais de um jogador vencedor ou número de fichas do vencedore igual a zero."));
	}
}