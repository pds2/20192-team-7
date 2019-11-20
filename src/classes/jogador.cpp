#include <classes/jogador.hpp>
using namespace poker;

Jogador::Jogador(std::string nome, int numeroFichas, Pote* pote, Mesa* mesa){
    this->mao = nullptr;
    this->pote = pote;
    this->mesa = mesa;
    this->numeroFichas = numeroFichas;
    this->nome = nome;
}

void Jogador::setMao(Mao *mao){
    this->mao = mao;
}

Mao Jogador::getMao(){
    return (*this->mao);
}

void Jogador::pagarAposta(){
    int valorApostaAtual = this->pote->getValorApostaAtual();
    int valorTotal = this->pote->getValorTotal();

    if ((this->numeroFichas - valorApostaAtual) >= 0){
        this->numeroFichas -= valorApostaAtual;
        this->pote->setValorTotal(valorTotal + valorApostaAtual);
        this->pote->setValorApostaAnterior(valorApostaAtual);
    }

    else{
        throw(PokerError("Fichas insuficientes"));
    }
}

void Jogador::aumentarAposta(unsigned int valorNovaAposta){
    int valorTotal = this->pote->getValorTotal();
    int valorApostaAtual = this->pote->getValorApostaAtual();

    if ((numeroFichas - valorNovaAposta >=0)){
        if (valorNovaAposta > this->pote->getValorApostaAnterior()){
            this->pote->setValorTotal(valorNovaAposta + valorTotal);
            this->pote->setValorApostaAnterior(valorApostaAtual);
            this->pote->setValorApostaAtual(valorNovaAposta);
        }
        else 
            throw(PokerError("É necessário aumentar a aposta!"));
    }

    else{
        throw(PokerError("Fichas insuficientes!"));
    }
}

void Jogador::desistirDaPartida(){
    throw(PokerError("Fim da partida!"));
}

void Jogador::passarVez(){
    int valorApostaAtual = this->pote->getValorApostaAtual();
    int valorApostaAnterior = this->pote->getValorApostaAnterior();

    if (valorApostaAtual == valorApostaAnterior)
        return;
    throw(PokerError("Não é permitido passar a vez se a aposta já foi aumentada!"));
}

std::map<std::string, int> Jogador::analisarMao(){
    std::map<std::string, int> resultadoDaAnalise;
    short int counter, position;
    bool flushFlag, royalFlushFlag, straightFlag, fourOfAKindFlag, threeOfAKindFlag, pairFlag, secondPairFlag, firsTimeflag;
    int royalFlushSequence[] = {DEZ, J, Q, K, A};
    int maiorCarta;
    Util util;
    std::vector<Carta> cartas = this->mesa->getCartasMesa();
    std::vector<Carta> aux = this->mao->getCartas();
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

    for (int i=0; i<cartas.size()-1; i++){
        if(cartas[i].getNaipe != cartas[i+1].getNaipe())
        flushFlag = false;

        if(cartas[i].getSimbolo != (cartas[i+1].getSimbolo()-1))
        straightFlag = false;
    }

    for (int i = cartas.size()-5; i < cartas.size(); i++){
        if(cartas[i].getSimbolo()!= royalFlushSequence[i-3] || !flushFlag)
            royalFlushFlag = false;            
    }

    for (int i=0; i < cartas.size() - 1; i++){
        if(cartas[i].getSimbolo() == cartas[i+1].getSimbolo() && counter!=4)
            counter++;
        else if (counter!=4) counter = 1;
        
        if(counter == 4 && firsTimeflag){
            firsTimeflag = false;
            maiorCarta = cartas[i].getSimbolo();
        }

    }
        if(counter != 4){
            counter = 1;
            fourOfAKindFlag = false;
        }

    firsTimeflag = true;

    for (int i=0; i < cartas.size() - 1; i++){
        if(cartas[i].getSimbolo() == cartas[i+1].getSimbolo() && !fourOfAKindFlag && counter!=3)
            counter++;
        else if (counter!=3) counter = 1;

        if (counter == 2)
            position = i;

        if(counter == 3 && firsTimeflag && !fourOfAKindFlag){
            firsTimeflag = false;
            maiorCarta = cartas[i].getSimbolo();
        }
    }
        if(counter != 3){
            counter = 1;
            threeOfAKindFlag = false;
        }

    firsTimeflag = true;

    for (int i=0; i < cartas.size() - 1; i++){
        if(cartas[i].getSimbolo() == cartas[i+1].getSimbolo() && !fourOfAKindFlag && !threeOfAKindFlag && counter!=2)
            counter++;
        else if (counter!=2) counter = 1;

        if (counter == 2 && !threeOfAKindFlag && firsTimeflag){
            position = i;
            firsTimeflag = false;
            maiorCarta = cartas[i].getSimbolo();
        }
    }
        if(counter != 2){
            counter = 1;
            pairFlag = false;
        }
    
    counter = 1;
    firsTimeflag = true;
    
    for (int i = 0; i<cartas.size()-1; i++){
        if(cartas[i].getSimbolo() == cartas[i+1].getSimbolo() && !fourOfAKindFlag && counter!=2 && position != i && position != i+1)
            counter++;
        else if ((counter!=2 || i == position) && !threeOfAKindFlag) counter = 1;

        if (counter == 2 && !threeOfAKindFlag && firsTimeflag){
            firsTimeflag = false;
            maiorCarta = (maiorCarta > cartas[i].getSimbolo()) ? maiorCarta : cartas[i].getSimbolo();
        }
    }
        if(counter != 2){
            counter = 1;
            secondPairFlag = false;
        }


    if(royalFlushFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", cartas.back().getSimbolo()));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", RoyalFlush));
    }

    else if(straightFlag && flushFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", cartas.back().getSimbolo()));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", StraigthFlush));
    }

    else if(fourOfAKindFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", maiorCarta));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", FourOfAKind));
    }
    
    else if(threeOfAKindFlag && secondPairFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", maiorCarta));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", FullHouse));
    }

    else if(flushFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", cartas.back().getSimbolo()));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", Flush));
    }
    
    else if(straightFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", cartas.back().getSimbolo()));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", Straight));
    }
    
    else if(threeOfAKindFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", maiorCarta));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", ThreeOfAKind));
    }
    
    else if(pairFlag && secondPairFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", maiorCarta));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", TwoPair));
    }
    
    else if(pairFlag){
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", maiorCarta));        
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", Pair));
    }

    else{
        resultadoDaAnalise.insert(std::pair<std::string, int>("Carta", cartas.back().getSimbolo()));
        resultadoDaAnalise.insert(std::pair<std::string, int>("Sequencia", HighCard));
    }    
    
    return(resultadoDaAnalise); 
}