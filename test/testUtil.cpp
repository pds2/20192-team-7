#include <test/doctest.h>
#include <classes/util.hpp>

using namespace poker;

TEST_CASE("Testando o construtor de Util"){
    CHECK_NOTHROW_MESSAGE(new Util(), "Construtor da classe Util OK!");
}

TEST_CASE("Testando o método obter string símbolo"){
    Util util;
    CHECK_EQ(util.ObterStringSimbolo(DOIS), "Dois");
    CHECK_EQ(util.ObterStringSimbolo(TRES), "Três");
    CHECK_EQ(util.ObterStringSimbolo(QUATRO), "Quatro");
    CHECK_EQ(util.ObterStringSimbolo(CINCO), "Cinco");
    CHECK_EQ(util.ObterStringSimbolo(SEIS), "Seis");
    CHECK_EQ(util.ObterStringSimbolo(SETE), "Sete");
    CHECK_EQ(util.ObterStringSimbolo(OITO), "Oito");
    CHECK_EQ(util.ObterStringSimbolo(NOVE), "Nove");
    CHECK_EQ(util.ObterStringSimbolo(DEZ), "Dez");
    CHECK_EQ(util.ObterStringSimbolo(J), "Valete");
    CHECK_EQ(util.ObterStringSimbolo(Q), "Dama");
    CHECK_EQ(util.ObterStringSimbolo(K), "Rei");
    CHECK_EQ(util.ObterStringSimbolo(A), "Ás");
}

TEST_CASE("Testando o método obter string sequencia"){
    Util util;
    CHECK_EQ(util.ObterStringSequencia(HighCard), "Carta alta");
    CHECK_EQ(util.ObterStringSequencia(Pair), "Par");
    CHECK_EQ(util.ObterStringSequencia(TwoPair), "Duplo par");
    CHECK_EQ(util.ObterStringSequencia(ThreeOfAKind), "Trio");
    CHECK_EQ(util.ObterStringSequencia(Straight), "Straight");
    CHECK_EQ(util.ObterStringSequencia(Flush), "Flush");
    CHECK_EQ(util.ObterStringSequencia(FullHouse), "Full House");
    CHECK_EQ(util.ObterStringSequencia(FourOfAKind), "Quadra");
    CHECK_EQ(util.ObterStringSequencia(StraightFlush), "Straight Flush");
    CHECK_EQ(util.ObterStringSequencia(RoyalFlush), "Royal Flush");
}