#include <test/doctest.h>
#include <classes/Pote.cpp>
using namespace poker;

TEST_CASE("Testando Construtor da classe Pote"){
    CHECK_NOTHROW(Pote());
    CHECK_NOTHROW(Pote(5,5,5));
    CHECK_THROWS(Pote('a',1,2));
    CHECK_THROWS(Pote('@', 2, -999.5));
}

TEST_CASE("Testando Setters"){
    Pote poteTeste;
    CHECK_NOTHROW_MESSAGE(poteTeste.setValorApostaAnterior(1), "setValorApostaAnterior OK!");
    CHECK_NOTHROW_MESSAGE(poteTeste.setValorTotal(1), "setValorApostaTotal OK!");
    CHECK_NOTHROW_MESSAGE(poteTeste.setValorApostaAtual(1), "setValorApostaTotal OK!");
}

TEST_CASE("Testando Getters"){
    Pote poteTeste(5,5,5);
    CHECK_EQ(poteTeste.getValorApostaAnterior(), 5);
    CHECK_EQ(poteTeste.getValorApostaAtual(), 5);
    CHECK_EQ(poteTeste.getValorTotal(), 5);
}

TEST_CASE("Testando Setters e Getters"){
    Pote poteTeste;
    poteTeste.setValorApostaAnterior(2);
    poteTeste.setValorApostaAtual(7);
    poteTeste.setValorTotal(9);  
    CHECK_EQ(poteTeste.getValorApostaAnterior(), 2);
    CHECK_EQ(poteTeste.getValorApostaAtual(), 7);
    CHECK_EQ(poteTeste.getValorTotal(), 9);  
}