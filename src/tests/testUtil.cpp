#include <test/doctest.h>
#include <classes/util.hpp>

using namespace poker;

TEST_CASE("Testando o construtor de Util"){
    CHECK_NOTHROW_MESSAGE(Util(), "Construtor da classe Util OK!");
}

TEST_CASE("Testando o método OrdenaCartas"){
    std::vector<Carta> ordened = {Carta(Paus,DOIS), Carta(Copas, TRES), Carta(Ouros, SEIS), Carta(Copas, Q)};
    std::vector<Carta> cartas = {Carta(Copas, Q), Carta(Paus,DOIS), Carta(Ouros, SEIS), Carta(Copas, TRES)};
    Util util;
    CHECK_NOTHROW_MESSAGE(cartas = util.OrdenaCartas(cartas), "Método de ordenação chamado OK!");
    CHECK_EQ(cartas, ordened);
}