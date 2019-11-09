#include <classes/jogador.hpp>
using namespace poker;

Jogador::Jogador(int numeroFichas, Pote* pote, Mesa* mesa){
    this->mao = nullptr;
    this->pote = pote;
    this->mesa = mesa;
    this->numeroFichas = numeroFichas;
}

void Jogador::setMao(Mao mao){
    this->mao = &mao;
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
        throw(1);
    }
}

void Jogador::aumentarAposta(unsigned int valorNovaAposta){
    int valorTotal = this->pote->getValorTotal();
    int valorApostaAtual = this->pote->getValorApostaAtual();

    if ((numeroFichas - valorNovaAposta >=0) && (valorNovaAposta > this->pote->getValorApostaAnterior())){
        this->pote->setValorTotal(valorNovaAposta + valorTotal);
        this->pote->setValorApostaAnterior(valorApostaAtual);
        this->pote->setValorApostaAtual(valorNovaAposta);
    }

    else{
        throw(1);
    }
}

void Jogador::desistirDaPartida(){
    throw(1);
}

void Jogador::passarVez(){
    int valorApostaAtual = this->pote->getValorApostaAtual();
    int valorApostaAnterior = this->pote->getValorApostaAnterior();

    if (valorApostaAtual == valorApostaAnterior)
        return;
    throw(1);
}

std::string Jogador::analisarMao(){
    bool flushFlag, royalFlushFlag, straightFlag;
    int royalFlushSequence[] = {DEZ, J, Q, K, A};
    Util util;
    std::vector<Carta> cartas = this->mesa->getCartasMesa();
    std::vector<Carta> aux = this->mao->getCartas();
    cartas.insert(std::end(cartas), std::begin(aux), std::end(aux));
    cartas = util.OrdenaCartas(cartas);
    
    flushFlag = true;
    straightFlag = true;
    royalFlushFlag = true;

    for (int i=0; i<cartas.size()-1; i++){
        if(cartas[i].getNaipe != cartas[i+1].getNaipe())
        flushFlag = false;

        if(cartas[i].getSimbolo != (cartas[i+1].getSimbolo()-1))
        straightFlag = false;
    }

    for (int i=0; i < cartas.size(); i++){
        if(cartas[3].getSimbolo()!= royalFlushSequence[i] || !flushFlag)
            royalFlushFlag = false;            
    }

    if(royalFlushFlag)
        return("Royal Flush");

    else if(straightFlag && flushFlag)
        return("Straight Flush");

    else if(flushFlag)
        return("Flush");
    
    else if(straightFlag){
        return("Straight");
    }   


}