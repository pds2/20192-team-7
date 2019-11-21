#include <include/classes/Mao.hpp>
#include <include/test/doctest.h>

using namespace poker;

TEST_CASE("Testando o construtor de Mao"){

	Carta cartaTeste1(0, 0);
	Carta cartaTeste2(0, 0);

	Mao maoTeste1(cartaTeste1, cartaTeste2);

	CHECK_THROWS();
}