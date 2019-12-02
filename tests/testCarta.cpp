#include <classes/carta.hpp>
#include <test/doctest.h>

using namespace poker;

TEST_CASE("Testando o Construtor de Carta"){
	CHECK_NOTHROW_MESSAGE(new Carta(Copas, Q), "Construtor nº1 de Carta OK!");
	CHECK_NOTHROW_MESSAGE(new Carta(2, 5), "Construtor nº2 de Carta OK!");
}

TEST_CASE("Testando getNaipe"){
	Carta cartaTeste(Paus, K);
	CHECK_FALSE((cartaTeste.getNaipe() == 0));
	CHECK_EQ(cartaTeste.getNaipe(), Paus);
}

TEST_CASE("Testando getSimbolo"){
	Carta cartaTeste(Espadas, A);
	CHECK_FALSE((cartaTeste.getSimbolo()==0));
	CHECK_EQ(cartaTeste.getSimbolo(), A);	
}