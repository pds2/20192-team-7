#include <classes/pokerExceptions.hpp>
using namespace poker;

PokerError::PokerError(std::string message){
    this->message = message;
}

std::string PokerError::what(){
    return this->message;
}

FimPartida::FimPartida() : std::exception() {
}


std::string FimPartida::what(){
    return "Fim da partida";
}

