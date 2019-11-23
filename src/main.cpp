#include "classes/dealer.hpp"
#include <iostream>

int main() {
    poker::Dealer* dealer = new poker::Dealer();

    unsigned int numeroJogadores;
    do {
        std::cout << "Insira o número de jogadores rivais (entre 1 e 7):" << std::endl;
        std::cin >> numeroJogadores;
    } while (numeroJogadores > 7 || numeroJogadores < 1);

    dealer->iniciarPartida(numeroJogadores);
}