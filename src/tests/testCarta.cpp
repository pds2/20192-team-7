#include <include/classes/carta.hpp>
#include <include/test/doctest.h>

using namespace poker;

TEST_CASE("Testando o Construtor de Carta"){
	CHECK_NOTHROWS(Carta());

	CHECK_NOTHROWS(Carta(2, 6));
	CHECK_NOTHROWS(Carta(3, 9));

	CHECK_THROWS(Carta(5, 10));
	CHECK_THROWS(Carta(3, 17));
	CHECK_THROWS(Carta(-1,-6));
	CHECK_THROWS(Carta("_","@"));
}

TEST_CASE("Testando getNaipe"){
	
	Carta cartaTeste1(0, 0);

	CHECK_EQ(cartaTeste1.getNaipe(), 0);
}

TEST_CASE("Testando getSimbolo"){

	Carta cartaTeste1(0, 0);

	CHECK_EQ(cartaTeste1.getSimbolo(), 0);	
}