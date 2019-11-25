#include "classes/jogadorHumano.hpp"
#include "classes/jogador.hpp"
#include "classes/dealer.hpp"
#include "classes/pokerExceptions.hpp"
#include "classes/util.hpp"
#include "enums/simbolo.hpp"
#include "enums/naipe.hpp"

#include <vector>
#include <iostream>

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

void imprimirCarta(Carta* carta){
    Util util;
    std::cout << '\t' << util.ObterStringSimbolo((Simbolo)carta->getSimbolo()) << " de " << util.ObterStringNaipe((Naipe)carta->getNaipe()) << std::endl;
}

void imprimirCartasMesa(Mesa* mesa){
    std::cout << "Cartas na mesa: " << std::endl;
    for (Carta* carta : mesa->getCartasMesa()){
        imprimirCarta(carta);
    }
}

void imprimirCartasJogador(Jogador* jogador){
    std::cout << "Cartas na sua mão: " << std::endl;
    for (Carta* carta : jogador->getMao()->getCartas()){
        imprimirCarta(carta);
    }
}

void imprimirDadosPote(Pote* pote){
    std::cout << "Valor aposta atual: " << pote->getValorApostaAtual() << std::endl;
    std::cout << "Pote: " << pote->getValorTotal() << std::endl;
}


void imprimirSituacaoAtualJogo(Pote* pote, Jogador* jogador, Mesa* mesa){
    imprimirCartasMesa(mesa);
    std::cout << std::endl;
    imprimirCartasJogador(jogador);
    std::cout << std::endl;
    imprimirDadosPote(pote);
    std::cout << std::endl;
    std::cout << std::endl;
}

void JogadorHumano::jogar(std::map<std::string, bool> opcoesJogador){
    std::string opcoes = "";

    int contadorOpcoes = 0;
    int opcaoEscolhida = 0;

    std::map<int, std::string> menu;

    for (std::map<std::string, bool>::iterator it = opcoesJogador.begin(); it != opcoesJogador.end(); ++it){
        if (it->second){
            contadorOpcoes++;
            opcoes += ('\t' + std::to_string(contadorOpcoes) + " - " + it->first + '\n');
            
            menu.insert(std::make_pair(contadorOpcoes, it->first));
        }
    }

    imprimirSituacaoAtualJogo(this->pote, this, this->mesa);


    do {
        std::cout << "Escolha sua jogada:" << std::endl << opcoes;

        std::cin >> opcaoEscolhida;

    } while (opcaoEscolhida < 1 || opcaoEscolhida > (contadorOpcoes+1) );
    
    realizarJogada(menu.find(opcaoEscolhida)->second);

}

void JogadorHumano::realizarJogada(std::string opcaoSelecionada){
    unsigned int valorAposta;
    bool apostou = false;
    if (opcaoSelecionada == "check"){
        this->passarVez();

    }else if (opcaoSelecionada == "apostar"){
        do {
            try {
                std::cout << "Valor da aposta: " ;
                std::cin >> valorAposta;
                
                this->apostar(valorAposta);

                apostou = true;
            } catch (PokerError pokerErrorException){
                std::cout << pokerErrorException.what() << std::endl;
                apostou = false;
            }
        } while (!apostou);
    }
    else if (opcaoSelecionada == "pagar")
        this->pagarAposta();

    else if (opcaoSelecionada == "aumentar"){
        do {
            try {
                std::cout << "Valor da nova aposta: " ;
                std::cin >> valorAposta;
                
                this->aumentarAposta(valorAposta);

                apostou = true;
            } catch (PokerError pokerErrorException){
                std::cout << pokerErrorException.what() << std::endl;
                apostou = false;
            }
        } while (!apostou);
    }

    else if (opcaoSelecionada == "desistir")
        this->desistirDaPartida();

    setUltimaAcao(opcaoSelecionada);
}

