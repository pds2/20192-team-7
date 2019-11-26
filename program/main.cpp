#include "classes/dealer.hpp"
#include <iostream>

int main() {
    poker::Dealer* dealer = new poker::Dealer();

    unsigned int numeroJogadores;
    
    do {
       
        std::cout << "Insira o número de jogadores rivais (entre 1 e 7):" << std::endl;
        std::cout<< numeroJogadores<<std::endl;

        if(!(std::cin >> numeroJogadores)){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout<<"Digite um valor válido!"<<std::endl;
        }

    } while (numeroJogadores > 7 || numeroJogadores < 1);
    
    dealer->iniciarJogo(numeroJogadores);
    return 0;
}