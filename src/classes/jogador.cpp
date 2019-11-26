#include "classes/jogador.hpp"
#include <iostream>
#include <ctime>
using namespace poker;

#define CHANCE_APOSTA_BOT 95

Jogador::Jogador(){}

Jogador::Jogador(std::string nome, Pote* pote, Mesa* mesa){
    this->mao = nullptr;
    this->pote = pote;
    this->mesa = mesa;
    this->nome = nome;
}


Jogador::Jogador(std::string nome, int numeroFichas, Pote* pote, Mesa* mesa){
    Jogador(nome, pote, mesa);
    this->numeroFichas = numeroFichas;
}

void Jogador::setMao(Mao *mao){
    this->mao = mao;
}

Mao* Jogador::getMao(){
    return this->mao;
}

std::string Jogador::getNome(){
    return this->nome;
}


void Jogador::setNumeroFichas(int numeroFichas){
    this->numeroFichas = numeroFichas;
}

unsigned int Jogador::getNumeroFichas(){
    return this->numeroFichas;
}

void Jogador::setUltimaAcao(std::string ultimaAcao){
    this->ultimaAcao = ultimaAcao;
}

std::string Jogador::getUltimaAcao(){
    return this->ultimaAcao;
}

void Jogador::passarVez(){
    unsigned int valorApostaAtual = this->pote->getValorApostaAtual();
    unsigned int valorApostaAnterior = this->pote->getValorApostaAnterior();

    if (valorApostaAtual == valorApostaAnterior)
        return;

    throw (PokerError("Não é permitido passar a vez se a aposta já foi aumentada!"));
}

void Jogador::apostar(unsigned int valorAposta){
    unsigned int valorApostaAtual = this->pote->getValorApostaAtual();
    unsigned int valorTotal = this->pote->getValorTotal();

    if (this->pote->getValorApostaAnterior() == valorApostaAtual){
        if (valorAposta <= 0 || valorAposta <= valorApostaAtual){
            throw (PokerError("Valor de aposta inválido. Deve ser maior que " + valorApostaAtual));
        } 
        else {
            if (this->getNumeroFichas() >= valorApostaAtual+valorAposta) {
                this->setNumeroFichas(this->getNumeroFichas()-valorAposta);
                this->pote->setValorTotal(valorTotal + valorAposta);
                this->pote->setValorApostaAnterior(valorApostaAtual);
                this->pote->setValorApostaAtual(valorAposta);
            } 
            else {
                throw (PokerError("Fichas insuficientes! Valor máximo: " + this->getNumeroFichas()-valorApostaAtual));
            }
        }
    } 
    else {
        throw (PokerError("Não é possível apostar agora. Apostas já foram feitas na rodada."));
    }
}

void Jogador::pagarAposta(){
    unsigned int valorApostaAtual = this->pote->getValorApostaAtual();
    unsigned int valorTotal = this->pote->getValorTotal();

    if ((this->numeroFichas - valorApostaAtual) >= 0){
        this->numeroFichas -= valorApostaAtual;
        this->pote->setValorTotal(valorTotal + valorApostaAtual);
        this->pote->setValorApostaAnterior(valorApostaAtual);
    }
    else {
        throw (PokerError("Fichas insuficientes"));
    }
}

void Jogador::aumentarAposta(unsigned int valorNovaAposta){
    unsigned int valorTotal = this->pote->getValorTotal();
    unsigned int valorApostaAtual = this->pote->getValorApostaAtual();

    if ((numeroFichas - valorNovaAposta >=0)){
        if (valorNovaAposta > this->pote->getValorApostaAnterior()){
            this->pote->setValorTotal(valorNovaAposta + valorTotal);
            this->pote->setValorApostaAnterior(valorApostaAtual);
            this->pote->setValorApostaAtual(valorNovaAposta);
        }
        else {
            throw (PokerError("É necessário aumentar a aposta!"));
        }
    }
    else {
        throw (PokerError("Fichas insuficientes! Valor máximo: " + this->getNumeroFichas()-valorApostaAtual));
    }
}

bool avaliarRoyalFlushSequence(Carta* carta){
    switch(carta->getSimbolo()){

        case DEZ:
            return true;
            break;
        case J:
            return true;
            break;
        case Q:
            return true;
            break;
        case K:
            return true;
            break;
        case A:
            return true;
            break;
        default:
            return false;
            break;
    }
}

std::map<std::string, int> Jogador::analisarMao(){

    std::cout << std::endl << "7.1.3" << std::endl << std::endl;

    std::map<std::string, int> resultadoDaAnalise;
    short int counter;
    unsigned int position = 0;
    bool flushFlag, royalFlushFlag, straightFlag, fourOfAKindFlag, threeOfAKindFlag, pairFlag, secondPairFlag, firsTimeflag;
    int maiorCarta;
    Util util;
    std::vector<Carta*> cartas = this->mesa->getCartasMesa();
    std::vector<Carta*> aux = this->mao->getCartas();
    cartas.insert(std::end(cartas), std::begin(aux), std::end(aux));
    cartas = util.OrdenaCartas(cartas);

    std::cout << std::endl << "7.1.4" << std::endl << std::endl;
    
    flushFlag = true;
    straightFlag = true;
    royalFlushFlag = true;
    fourOfAKindFlag = true;
    threeOfAKindFlag = true;
    pairFlag = true;
    secondPairFlag = true;
    firsTimeflag = true;
    counter = 1;

    std::cout << std::endl << "7.1.5" << std::endl << std::endl;

    for (unsigned int i = 0; i < cartas.size()-1; i++){
        if (cartas[i]->getNaipe() != cartas[i+1]->getNaipe())
            flushFlag = false;

        if (cartas[i]->getSimbolo() != (cartas[i+1]->getSimbolo()-1))
            straightFlag = false;
    }
    if (cartas.size()<4){
        straightFlag = false;
        flushFlag = false;
    }

    std::cout << std::endl << "7.1.6" << std::endl << std::endl;
    
    if (cartas.size()>5){
        for (unsigned int i = cartas.size()-5; i < cartas.size(); i++){
            if (!(avaliarRoyalFlushSequence(cartas[i])) || !flushFlag)
                royalFlushFlag = false;            
        }
    }
    else royalFlushFlag = false;

    for (unsigned int i=0; i < cartas.size() - 1; i++){
        if (cartas[i]->getSimbolo() == cartas[i+1]->getSimbolo() && counter!=4)
            counter++;
        else if (counter!=4) counter = 1;
        
        if (counter == 4 && firsTimeflag){
            firsTimeflag = false;
            maiorCarta = cartas[i]->getSimbolo();
        }

    }

    std::cout << std::endl << "7.1.7" << std::endl << std::endl;

    if (counter != 4){
        counter = 1;
        fourOfAKindFlag = false;
    }

    firsTimeflag = true;

    std::cout << std::endl << "7.1.8" << std::endl << std::endl;

    for (unsigned int i=0; i < cartas.size() - 1; i++){
        if (cartas[i]->getSimbolo() == cartas[i+1]->getSimbolo() && !fourOfAKindFlag && counter!=3)
            counter++;
        else if (counter!=3) counter = 1;

        if (counter == 2)
            position = i;

        if (counter == 3 && firsTimeflag && !fourOfAKindFlag){
            firsTimeflag = false;
            maiorCarta = cartas[i]->getSimbolo();
        }
    }

    std::cout << std::endl << "7.1.9" << std::endl << std::endl;

    if (counter != 3){
        counter = 1;
        threeOfAKindFlag = false;
    }

    firsTimeflag = true;

    std::cout << std::endl << "7.1.10" << std::endl << std::endl;

    for (unsigned int i=0; i < cartas.size() - 1; i++){
        if (cartas[i]->getSimbolo() == cartas[i+1]->getSimbolo() && !fourOfAKindFlag && !threeOfAKindFlag && counter!=2)
            counter++;
        else if (counter!=2) counter = 1;

        if (counter == 2 && !threeOfAKindFlag && firsTimeflag){
            position = i;
            firsTimeflag = false;
            maiorCarta = cartas[i]->getSimbolo();
        }
    }

    std::cout << std::endl << "7.1.11" << std::endl << std::endl;

    if (counter != 2) {
        counter = 1;
        pairFlag = false;
    }
    
    counter = 1;
    firsTimeflag = true;
    
    for (unsigned int i = 0; i<cartas.size()-1; i++){
        if (cartas[i]->getSimbolo() == cartas[i+1]->getSimbolo() && !fourOfAKindFlag && counter!=2 && position != i && position != i+1)
            counter++;
        else if ((counter!=2 || i == position || i == position+1 || i == position -1) && !threeOfAKindFlag) counter = 1;

        if (counter == 2 && !threeOfAKindFlag && firsTimeflag){
            firsTimeflag = false;
            maiorCarta = (maiorCarta > cartas[i]->getSimbolo()) ? maiorCarta : cartas[i]->getSimbolo();
        }
    }

    std::cout << std::endl << "7.1.12" << std::endl << std::endl;

    if (counter != 2){
        counter = 1;
        secondPairFlag = false;
    }

    std::cout << std::endl << "7.1.13" << std::endl << std::endl;

    if (royalFlushFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", cartas.back()->getSimbolo()));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", RoyalFlush));
    }

    else if (straightFlag && flushFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", cartas.back()->getSimbolo()));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", StraightFlush));
    }

    else if (fourOfAKindFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", maiorCarta));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", FourOfAKind));
    }
    
    else if (threeOfAKindFlag && secondPairFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", maiorCarta));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", FullHouse));
    }

    else if (flushFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", cartas.back()->getSimbolo()));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", Flush));
    }
    
    else if (straightFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", cartas.back()->getSimbolo()));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", Straight));
    }
    
    else if (threeOfAKindFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", maiorCarta));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", ThreeOfAKind));
    }
    
    else if (pairFlag && secondPairFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", maiorCarta));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", TwoPair));
    }
    
    else if (pairFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", maiorCarta));        
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", Pair));
    }

    else {
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", cartas.back()->getSimbolo()));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", HighCard));
    }    
    
    
    return(resultadoDaAnalise); 
}

int gerarValorChanceAposta(){
    int valorMaximo = 100;
    int valorMinimo = 1;
    srand((unsigned)time(0));
    return rand() % (valorMaximo-valorMinimo) + valorMinimo;
}

float gerarPorcentagemAumentoAposta(){
    int valorMaximo = 20;
    int valorMinimo = 5;
    srand((unsigned)time(0));
    return (rand() % (valorMaximo-valorMinimo) + valorMinimo)/100;
}

float gerarPorcentagemAposta(){
    int valorMaximo = 10;
    int valorMinimo = 5;
    srand((unsigned)time(0));
    return (rand() % (valorMaximo-valorMinimo) + valorMinimo)/100;
}

int gerarValorAposta(Jogador jogador){
    int valorMinimo = 1;
    int valorMaximo = jogador.getNumeroFichas();
    srand((unsigned)time(0));
    return rand() % (valorMaximo-valorMinimo) + valorMinimo; 
}

int gerarValorAumentarAposta(Jogador jogador, Pote* pote){
    if (gerarValorChanceAposta() <= CHANCE_APOSTA_BOT){
        return (float)pote->getValorApostaAnterior() * gerarPorcentagemAumentoAposta();
    }
    else {
        return jogador.getNumeroFichas();
    }
}

void Jogador::realizarJogada(std::string opcaoSelecionada){
    if (opcaoSelecionada == "check")
        this->passarVez();

    else if (opcaoSelecionada == "apostar")
        this->apostar(gerarValorAposta(*this)*gerarPorcentagemAposta());

    else if (opcaoSelecionada == "pagar")
        this->pagarAposta();

    else if (opcaoSelecionada == "aumentar")
        this->aumentarAposta(gerarValorAumentarAposta(*this, this->pote));

    setUltimaAcao(opcaoSelecionada);
}

void Jogador::jogar(std::map<std::string, bool> opcoesJogador){
    int contadorOpcoes = 0;

    std::map<int, std::string> menu;

    for (std::map<std::string, bool>::iterator it = opcoesJogador.begin(); it != opcoesJogador.end(); ++it){
        if (it->second){
            menu.insert(std::make_pair(contadorOpcoes, it->first));
            contadorOpcoes++;
        }
    }

    bool botJogou = false;
    do {
        try {
            int opcaoEscolhidaAleatoriamente = rand() % contadorOpcoes;
            realizarJogada(menu.find(opcaoEscolhidaAleatoriamente)->second);

            botJogou = true;
        }

        catch (PokerError& e) {
            botJogou = false;
        }

    } while (!botJogou);
}