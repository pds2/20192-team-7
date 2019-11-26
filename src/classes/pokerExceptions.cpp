#include <classes/pokerExceptions.hpp>
using namespace poker;

PokerError::PokerError(std::string message){
    this->message = message;
}

std::string PokerError::what(){
    return this->message;
}

FimRodada::FimRodada() : std::exception() {
}


std::string FimRodada::what(){
    return "Fim da rodada";
}


FimJogo::FimJogo() : std::exception() {
}


std::string FimJogo::what(){
    return "Fim do jogo";
}

