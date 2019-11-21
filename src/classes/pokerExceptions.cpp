#include <classes/pokerExceptions.hpp>
using namespace poker;

PokerError::PokerError(std::string message){
    this->message = message;
}

std::string PokerError::what(){
    return this->message;
}