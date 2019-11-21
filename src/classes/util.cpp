#include <classes/util.hpp>
using namespace poker;

std::vector<Carta> Util::OrdenaCartas(std::vector<Carta> cartas){
    Carta aux(Ouros, DOIS);
    int min;

    unsigned int i;

    for (i = 0; i < cartas.size() - 1; i++){
        min = i;

        for (unsigned int j = i+1; j<cartas.size(); j++){
            if (cartas[j].getSimbolo() < cartas[min].getSimbolo())
                min = j;

            if (cartas[i].getSimbolo()!= cartas[min].getSimbolo()){
                aux = cartas[i];
                cartas[i] = cartas[min];
                cartas[min] = aux;
            }
        }
    }

    return(cartas);
}
