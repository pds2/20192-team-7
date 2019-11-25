#include "classes/jogador.hpp"
#include<iostream>
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
                this->numeroFichas -= valorApostaAtual;
                this->pote->setValorTotal(valorTotal + valorApostaAtual);
                this->pote->setValorApostaAnterior(valorApostaAtual);
            } 
            else {
                throw (PokerError("Fichas insuficientes! Valor máximo: " + numeroFichas-valorApostaAtual));
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
        throw (PokerError("Fichas insuficientes! Valor máximo: " + numeroFichas-valorApostaAtual));
    }
}

std::map<std::string, int> Jogador::analisarMao(){
    std::map<std::string, int> resultadoDaAnalise;
    short int counter;
    unsigned short int position = 0;
    bool flushFlag, royalFlushFlag, straightFlag, fourOfAKindFlag, threeOfAKindFlag, pairFlag, secondPairFlag, firsTimeflag;
    int royalFlushSequence[] = {DEZ, J, Q, K, A};
    int maiorCarta;
    Util util;
    std::vector<Carta*> cartas = this->mesa->getCartasMesa();
    std::vector<Carta*> aux = this->mao->getCartas();
    cartas.insert(std::end(cartas), std::begin(aux), std::end(aux));
    cartas = util.OrdenaCartas(cartas);
    
    flushFlag = true;
    straightFlag = true;
    royalFlushFlag = true;
    fourOfAKindFlag = true;
    threeOfAKindFlag = true;
    pairFlag = true;
    secondPairFlag = true;
    firsTimeflag = true;
    counter = 1;

    for (unsigned int i = 0; i < cartas.size()-1; i++){
        if (cartas[i]->getNaipe() != cartas[i+1]->getNaipe())
            flushFlag = false;

        if (cartas[i]->getSimbolo() != (cartas[i+1]->getSimbolo()-1))
            straightFlag = false;
    }

    for (unsigned int i = cartas.size()-5; i < cartas.size(); i++){
        if (cartas[i]->getSimbolo()!= royalFlushSequence[i-3] || !flushFlag)
            royalFlushFlag = false;            
    }

    for (unsigned int i=0; i < cartas.size() - 1; i++){
        if (cartas[i]->getSimbolo() == cartas[i+1]->getSimbolo() && counter!=4)
            counter++;
        else if (counter!=4) counter = 1;
        
        if (counter == 4 && firsTimeflag){
            firsTimeflag = false;
            maiorCarta = cartas[i]->getSimbolo();
        }

    }

    if (counter != 4){
        counter = 1;
        fourOfAKindFlag = false;
    }

    firsTimeflag = true;

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

    if (counter != 3){
        counter = 1;
        threeOfAKindFlag = false;
    }

    firsTimeflag = true;

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

    if (counter != 2) {
        counter = 1;
        pairFlag = false;
    }
    
    counter = 1;
    firsTimeflag = true;
    
    for (unsigned int i = 0; i<cartas.size()-1; i++){
        if (cartas[i]->getSimbolo() == cartas[i+1]->getSimbolo() && !fourOfAKindFlag && counter!=2 && position != i && position != i+1)
            counter++;
        else if ((counter!=2 || i == position) && !threeOfAKindFlag) counter = 1;

        if (counter == 2 && !threeOfAKindFlag && firsTimeflag){
            firsTimeflag = false;
            maiorCarta = (maiorCarta > cartas[i]->getSimbolo()) ? maiorCarta : cartas[i]->getSimbolo();
        }
    }

    if (counter != 2){
        counter = 1;
        secondPairFlag = false;
    }


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


std::string converterOpcaoJogador(int numeroOpcao){

    switch (numeroOpcao){
        case 1:
            return "check";
            break;
        case 2:
            return "apostar";
            break;
        case 3:
            return "desistir";
            break;
        case 4:
            return "pagar";
            break;
        case 5:
            return "aumentar";
            break;
        default: 
            return "check";
            break;
    }
}

int geradorInteiroAleatorio(){
    int numeroOpcoesMaxima = 5;
    int numeroOpcoesMinima = 1;

    return rand() % (numeroOpcoesMaxima-numeroOpcoesMinima) + numeroOpcoesMinima; 
}

int gerarValorChanceAposta(){
    int valorMaximo = 100;
    int valorMinimo = 1;

    return rand() % (valorMaximo-valorMinimo) + valorMinimo;
}

float gerarPorcentagemAumentoAposta(){
    int valorMaximo = 80;
    int valorMinimo = 10;

    return (rand() % (valorMaximo-valorMinimo) + valorMinimo)/10;
}

int gerarValorAposta(Jogador jogador){
    int valorMinimo = 1;
    int valorMaximo = jogador.getNumeroFichas();

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
        this->apostar(gerarValorAposta(*this));

    else if (opcaoSelecionada == "pagar")
        this->pagarAposta();

    else if (opcaoSelecionada == "aumentar")
        this->aumentarAposta(gerarValorAumentarAposta(*this, this->pote));

    setUltimaAcao(opcaoSelecionada);
}

void Jogador::jogar(std::map<std::string, bool> opcoesJogador){
    std::string opcaoSelecionada;

    do {
        opcaoSelecionada = converterOpcaoJogador(geradorInteiroAleatorio());
    } while (opcoesJogador.at(opcaoSelecionada) == true);
    
    realizarJogada(opcaoSelecionada);
}