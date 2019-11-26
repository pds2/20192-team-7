#include "classes/dealer.hpp"
#include <iostream>
#include <cstdlib>

int main() {
    std::system("clear");

    poker::Dealer* dealer = new poker::Dealer();

    unsigned int numeroJogadores;
    
    do {
       
        std::cout << "Insira o número de jogadores rivais (entre 1 e 7):" << std::endl;

        if(!(std::cin >> numeroJogadores)){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout<< "Digite um valor válido!" <<std::endl;
        }

    } while (numeroJogadores > 7 || numeroJogadores < 1);
    
    try {
        dealer->iniciarJogo(numeroJogadores);
    }
    catch (std::exception& e){
        return 0;
    }
    return 0;
}