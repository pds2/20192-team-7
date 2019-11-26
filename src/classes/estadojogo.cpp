#include "classes/estadojogo.hpp"
#include "classes/pote.hpp"
#include "classes/jogador.hpp"

#include <iostream>
#include <typeinfo>

using namespace poker;

EstadoJogo::EstadoJogo(){}

EstadoJogo::EstadoJogo(Baralho* baralho){
    this->baralho = baralho;
}

void EstadoJogo::distribuirCartas(Mesa* mesa){}

bool EstadoJogo::validarApostas(unsigned int valorAposta, Jogador* jogador){
    bool valido = (jogador->getNumeroFichas() >= valorAposta);
    return valido;
}

bool verificarCheck(Jogador* jogador, Pote* pote){
    bool valido = (pote->getValorApostaAnterior() == pote->getValorApostaAtual() && jogador->getNumeroFichas() >= pote->getValorApostaAtual());
    return valido;
}

bool verificarBet(Jogador* jogador, Pote* pote){
    bool valido = (jogador->getNumeroFichas() > pote->getValorApostaAtual());
    return valido;
}

bool verificarFold(Jogador* jogador, Pote* pote){
    bool valido = false;
    return valido;
}

bool verificarFold(JogadorHumano* jogador, Pote* pote){
    bool valido = true;
    return valido;
}

bool verificarCall(Jogador* jogador, Pote* pote){
    bool valido =  (pote->getValorApostaAtual() > pote->getValorApostaAnterior() && jogador->getNumeroFichas() >= pote->getValorApostaAtual());
    return valido;
}

bool verificarRaise(Jogador* jogador, Pote* pote){
    bool valido = (pote->getValorApostaAtual() > pote->getValorApostaAnterior() && jogador->getNumeroFichas() > pote->getValorApostaAtual());

    return valido;
}

std::map<std::string, bool> EstadoJogo::verificarOpcoesJogador(Jogador* jogador, Pote* pote) {
    std::map<std::string, bool> mapaOpcoesJogador;

    mapaOpcoesJogador.insert(std::pair<std::string, bool>("check", verificarCheck(jogador, pote)));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("apostar", verificarBet(jogador, pote)));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("desistir", verificarFold(jogador, pote)));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("pagar", verificarCall(jogador, pote)));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("aumentar", verificarRaise(jogador, pote)));

    return mapaOpcoesJogador;
}

std::map<std::string, bool> EstadoJogo::verificarOpcoesJogador(JogadorHumano* jogador, Pote* pote) {
    std::map<std::string, bool> mapaOpcoesJogador;

    mapaOpcoesJogador.insert(std::pair<std::string, bool>("check", verificarCheck(jogador, pote)));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("apostar", verificarBet(jogador, pote)));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("desistir", verificarFold(jogador, pote)));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("pagar", verificarCall(jogador, pote)));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("aumentar", verificarRaise(jogador, pote)));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("sair do jogo", true));

    return mapaOpcoesJogador;
}