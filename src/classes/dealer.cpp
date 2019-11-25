#include "classes/dealer.hpp"
#include "classes/util.hpp"
#include <map>
#include <iterator>
#include <iostream>

using namespace poker;

#define FICHAS_POR_JOGADOR 2000

Dealer::Dealer() {
	this->pote = new Pote();
	this->mesa = new Mesa();
	this->baralho = new Baralho();
	this->momentoJogo = new EstadoJogo();
}

Dealer::Dealer(EstadoJogo* momentoJogo, unsigned int numeroJogadores){
	Dealer();
	this->momentoJogo = momentoJogo;
	this->numeroJogadores = numeroJogadores;
}

void Dealer::setEstadoJogo(EstadoJogo* momentoJogo){
	this->momentoJogo = momentoJogo;
}

void Dealer::setNumeroJogadores(unsigned int numeroJogadores){
	this->numeroJogadores = numeroJogadores;
}

EstadoJogo Dealer::getMomentoJogo(){
	return *this->momentoJogo;
}

int Dealer::getNumeroJogadores(){
	return this->numeroJogadores;
}


void Dealer::inserirJogadores(){
    
    Jogador* bots[7] = {
		new Jogador("Clinky", pote, mesa),
		new Jogador("Adilson", pote, mesa),
		new Jogador("Taylor Swift", pote, mesa),
		new Jogador("Bryan", pote, mesa),
		new Jogador("Julio", pote, mesa),
		new Jogador("Ricky", pote, mesa),
		new Jogador("Morty", pote, mesa),
	}; 

	unsigned int i; 
	for (i = 0; i < numeroJogadores; i++)
    	(this->jogadores).push_back(bots[i]);
	
	this->jogadorHumano = new JogadorHumano("Player", pote, mesa);
	
}

void Dealer::distribuirFichas(unsigned int numeroFichas){
	std::vector<Jogador*>::iterator it;

	for (it = this->jogadores.begin() ; it != this->jogadores.end(); ++it){
		(*it)->setNumeroFichas(numeroFichas);
	}

	this->jogadorHumano->setNumeroFichas(numeroFichas);
}

bool verificarTodosCheck(std::vector<Jogador*> jogadores){
	bool todosCheck = false;

	for (Jogador* jogador : jogadores){
		if (jogador->getUltimaAcao() == "check"){
			todosCheck = true;
		} 
		else {
			todosCheck = false;
			break;
		}
	}

	return todosCheck;
}

bool verificarTodosPagam(std::vector<Jogador*> jogadores){
	bool todosPagam = false;

	for (Jogador* jogador : jogadores){

		if (jogador->getUltimaAcao() == "aumentar" || jogador->getUltimaAcao() == "apostar"){

			for (Jogador* j : jogadores){

				if (jogador->getNome() != j->getNome()){

					if (j->getUltimaAcao() == "pagar"){
						todosPagam = true;
					}
					else {
						todosPagam = false;
						break;								
					}
				
				}
			}
		}
	}

	return todosPagam;

}

void Dealer::iniciarJogadas(){
	std::vector<Jogador*>::iterator it;
	bool podeSeguirProximaJogada = false;

	do {
	
		jogada(this->jogadorHumano);
	
		for (it = this->jogadores.begin(); it != this->jogadores.end(); ++it){
			jogada(*it);

            std::cout << "Jogador " << (*it)->getNome() << " fez: " << (*it)->getUltimaAcao() << std::endl;
			std::cout << std::endl;
		}

		if (verificarTodosCheck(this->jogadores)){
			podeSeguirProximaJogada = true;
		}
		else if (verificarTodosPagam(this->jogadores)) {
			podeSeguirProximaJogada = true;
		}
		else {
			podeSeguirProximaJogada = false;
		}

	} while (!podeSeguirProximaJogada);
}

void Dealer::jogada(Jogador* jogador){
	jogador->jogar(this->getMomentoJogo().verificarOpcoesJogador(jogador, this->pote));
}

void Dealer::jogada(JogadorHumano* jogador){
	mostrarMaoAtualJogador(jogador);
	jogador->jogar(this->getMomentoJogo().verificarOpcoesJogador(jogador, this->pote));
}

void Dealer::mostrarMaoAtualJogador(Jogador* jogador){
	Util util; 
	std::map<std::string, int> mapMao = jogador->analisarMao();
  
	if (mapMao.find("Carta") != mapMao.end()) {

		Simbolo maiorCarta = (Simbolo)(mapMao.find("Carta")->second);
		OrdemSequencia sequencia = (OrdemSequencia)(mapMao.find("Sequencia")->second);

		std::string maiorCartaString = util.ObterStringSimbolo(maiorCarta);
		std::string sequenciaString = util.ObterStringSequencia(sequencia);
    
		std::cout << "Sua mão contém: " << sequenciaString << " com a carta mais alta sendo " << maiorCartaString << std::endl;
	}
}

void Dealer::iniciarEstadoJogo (PreFlop* estadoJogo){
	setEstadoJogo((EstadoJogo*)(estadoJogo));
	estadoJogo->distribuirCartasJogadores(this->jogadores,this->jogadorHumano);

	this->iniciarJogadas();
}

void Dealer::iniciarEstadoJogo (EstadoJogo* estadoJogo){
	setEstadoJogo((EstadoJogo*)(estadoJogo));
	estadoJogo->distribuirCartas(this->mesa);

	this->iniciarJogadas();
}

bool verificarMaiorMao(Jogador* primeiroJogador, Jogador* segundoJogador){
	return primeiroJogador->analisarMao().at("Sequencia") > segundoJogador->analisarMao().at("Sequencia");
}

bool verificarMaoIgual(Jogador* primeiroJogador, Jogador* segundoJogador){
	return primeiroJogador->analisarMao().at("Sequencia") == segundoJogador->analisarMao().at("Sequencia");
}


bool compararCartas(Carta primeiraCarta, Carta segundaCarta){
	return (primeiraCarta.getSimbolo() > segundaCarta.getSimbolo());
}

bool verificarCartasIguais(Carta cartaUm, Carta cartaDois){
	return cartaUm.getSimbolo() == cartaDois.getSimbolo();
}

Carta* recuperarCarta(Jogador jogador, int posicao){
	return jogador.getMao()->getCartas().at(posicao);
}

Carta converterCarta(int simbolo){
	return Carta(static_cast<Simbolo>(simbolo),static_cast<Naipe>(simbolo));
}

Jogador* verificarJogadorMaiorCarta(Jogador* primeiroJogador, Jogador* segundoJogador){
	if (verificarCartasIguais(converterCarta(primeiroJogador->analisarMao().at("Carta")), converterCarta(segundoJogador->analisarMao().at("Carta")))){
		return primeiroJogador;
	}
	
	if (compararCartas(converterCarta(primeiroJogador->analisarMao().at("Carta")), converterCarta(segundoJogador->analisarMao().at("Carta")))){
		return primeiroJogador;
	}
	else {
		return segundoJogador;
	}

}

void Dealer::iniciarJogo(unsigned int numeroJogadores){
	setNumeroJogadores(numeroJogadores);
	
	inserirJogadores();
		
	distribuirFichas(FICHAS_POR_JOGADOR);

	bool podeContinuarJogo = true;

	while (podeContinuarJogo){
		try {

			iniciarRodada();

		} catch (FimJogo e){
			std::cout << e.what() << std::endl;
			podeContinuarJogo = false;
		}
	}

	verificarResultadoJogo();
}

void Dealer::iniciarRodada(){
	try { 

		this->baralho->embaralhar();

		PreFlop* preFlop = new PreFlop(this->baralho);
		Flop* flop = new Flop(this->baralho);
		Turn* turn = new Turn(this->baralho);
		River* river = new River(this->baralho);

		iniciarEstadoJogo(preFlop);
		iniciarEstadoJogo(flop);
		iniciarEstadoJogo(turn);
		iniciarEstadoJogo(river);

		Jogador* jogadorVencedor = verificarResultadoRodada();
		entregarPremio(jogadorVencedor);

		for (Jogador* jogador : this->jogadores){

			if (jogador->getNumeroFichas() == 0)
				throw FimJogo();
		}

	} catch (FimRodada e){
		std::cout << e.what() << std::endl;
	}
}

void Dealer::entregarPremio(Jogador* jogadorVencedor){
	jogadorVencedor->setNumeroFichas(this->pote->getValorTotal());
	
	this->pote->setValorTotal(0);
	this->pote->setValorApostaAtual(0);
	this->pote->setValorApostaAnterior(0);
}

void Dealer::verificarResultadoJogo(){
	std::vector<Jogador*> jogadores = this->jogadores;
	std::vector<Jogador*> vencedoresPotencias;
	
	for (Jogador* jogador : this->jogadores){
		
		if (jogador->getNumeroFichas() > 0 ){
			vencedoresPotencias.push_back(jogador);
		}
	}

	if (vencedoresPotencias.size() == 1 && vencedoresPotencias.at(0)->getNumeroFichas() > 0){
		std::cout << "O vencedor foi o jogador : " << vencedoresPotencias.at(0)->getNome() << " com " << vencedoresPotencias.at(0)->getNumeroFichas() << "fichas";
	} 
	else {
		throw (PokerError("Método chamado no momento errado, mais de um jogador vencedor ou número de fichas do vencedore igual a zero."));
	}
}

Jogador* Dealer::verificarResultadoRodada(){
	Jogador* vencedor = nullptr;
	for (Jogador* primeiroCandidatoVencer : this->jogadores){
	
		for (Jogador* comparacaoVencedor : this->jogadores){
			
			if (verificarMaiorMao(primeiroCandidatoVencer,comparacaoVencedor)){
				vencedor = primeiroCandidatoVencer;
			}
			else if (verificarMaoIgual(primeiroCandidatoVencer,comparacaoVencedor)){
				vencedor = verificarJogadorMaiorCarta(primeiroCandidatoVencer, comparacaoVencedor);
			}
		}
	}

	return vencedor;
}