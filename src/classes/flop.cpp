#include "classes/flop.hpp"
#include "classes/carta.hpp"

#include <vector>

using namespace poker;

Flop::Flop() : EstadoJogo(){
}

Flop::Flop(Baralho* baralho) : EstadoJogo(baralho){
}

void Flop::distribuirCartas(Mesa* mesa) {
    std::vector<Carta> cartasMesa = this->baralho->distribuirCartas(3);
    mesa->addCartas(cartasMesa);
}

bool Flop::validarApostas(int valorAposta, Jogador* jogador) {
    return (jogador->getNumeroFichas() >= valorAposta);
}

bool verificarCheck(Jogador* jogador, Pote* pote){
    return (pote->getValorApostaAnterior() == pote->getValorApostaAtual() && jogador->getNumeroFichas() >= pote->getValorApostaAtual());
}

bool verificarBet(Jogador* jogador, Pote* pote){
    return (pote->getValorApostaAnterior() == pote->getValorApostaAtual() && jogador->getNumeroFichas() > pote->getValorApostaAtual());
}

bool verificarFold(Jogador* jogador, Pote* pote){
    return true;
}

bool verificarCall(Jogador* jogador, Pote* pote){
    return (pote->getValorApostaAtual() > pote->getValorApostaAnterior() && jogador->getNumeroFichas() >= pote->getValorApostaAtual());
}

bool verificarRaise(Jogador* jogador, Pote* pote){
    return (pote->getValorApostaAtual() > pote->getValorApostaAnterior() && jogador->getNumeroFichas() > pote->getValorApostaAtual());
}

std::map<std::string, bool> Flop::verificarOpcoesJogador(Jogador* jogador, Pote* pote) {
    std::map<std::string, bool> mapaOpcoesJogador;

    mapaOpcoesJogador.insert(std::pair<std::string, bool>("check", verificarCheck(jogador, pote)));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("apostar", verificarBet(jogador, pote)));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("desistir", verificarFold(jogador, pote)));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("pagar", verificarCall(jogador, pote)));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("aumentar", verificarRaise(jogador, pote)));

    return mapaOpcoesJogador;
}
