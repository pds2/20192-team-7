#include <classes/util.hpp>
using namespace poker;

std::vector<Carta*> Util::OrdenaCartas(std::vector<Carta*> cartas){
    Carta* aux = new Carta(Ouros, DOIS);
    int min;

    unsigned int i;

    for (i = 0; i < cartas.size() - 1; i++){
        min = i;

        unsigned int j;
        for (j = i+1; j<cartas.size(); j++){
            if (cartas[j]->getSimbolo() < cartas[min]->getSimbolo())
                min = j;

            if (cartas[i]->getSimbolo()!= cartas[min]->getSimbolo()){
                aux = cartas[i];
                cartas[i] = cartas[min];
                cartas[min] = aux;
            }
        }
    }

    return(cartas);
}

std::string Util::ObterStringSimbolo(Simbolo simbolo){
	std::string simboloString = "";
	switch (simbolo)
	{
		case DOIS :
			simboloString = "Dois";
			break;
		case TRES :
			simboloString = "Três";
			break;
		case QUATRO :
			simboloString = "Quatro";
			break;
		case CINCO :
			simboloString = "Cinco";
			break;
		case SEIS :
			simboloString = "Seis";
			break;
		case SETE :
			simboloString = "Sete";
			break;
		case OITO :
			simboloString = "Oito";
			break;
		case NOVE :
			simboloString = "Nove";
			break;
		case DEZ :
			simboloString = "Dez";
			break;
		case J :
			simboloString = "Valete";
			break;
		case Q :
			simboloString = "Dama";
			break;
		case K :
			simboloString = "Rei";
			break;
		case A :
			simboloString = "Ás";
			break;
		
		default:
			break;
		
	}

	return simboloString;
}

std::string Util::ObterStringNaipe(Naipe naipe){
	std::string naipeString = "";
	switch (naipe)
	{
		case Ouros :
			naipeString = "Ouros";
			break;
		case Paus :
			naipeString = "Paus";
			break;
		case Copas :
			naipeString = "Copas";
			break;
		case Espadas :
			naipeString = "Espadas";
			break;
		
		default:
			break;
		
	}

	return naipeString;
}


std::string Util::ObterStringSequencia(OrdemSequencia sequencia){
	std::string sequenciaString = "";

	switch (sequencia)
	{
		case HighCard:
			sequenciaString = "Carta alta";
			break;
		case Pair:
			sequenciaString = "Par";
			break;
		case TwoPair:
			sequenciaString = "Duplo par";
			break;
		case ThreeOfAKind:
			sequenciaString = "Trio";
			break;
		case Straight:
			sequenciaString = "Straight";
			break;
		case Flush:
			sequenciaString = "Flush";
			break;
		case FullHouse:
			sequenciaString = "Full House";
			break;
		case FourOfAKind:
			sequenciaString = "Quadra";
			break;
		case StraightFlush:
			sequenciaString = "Straight Flush";
			break;
		case RoyalFlush:
			sequenciaString = "Royal Flush";
			break;
		
		default:
			break;

	}
		return sequenciaString;
}


