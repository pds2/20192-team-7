#include <include/classes/Mao.hpp>
#include <include/test/doctest.h>

using namespace poker;

TEST_CASE("Testando o construtor de Mao"){

	Carta cartaTeste1(0, 0);
	Carta cartaTeste2(0, 0);
	Carta cartaTeste3(3, 6);
	Carta cartaTeste4(2, 8);
	Carta cartaTeste5(1, 3);
	Carta cartaTeste6(4, 4);

	CHECK_THROWS(maoTeste1(cartaTeste1, cartaTeste2));
	CHECK_THROWS(maoTeste2(12, 3));

	CHECK_NOTHROWS(maoTeste3(cartaTeste3, cartaTeste4));
	CHECK_NOTHROWS(maoTeste4(cartaTeste5, cartaTeste6));
}

TEST_CASE("Testando getCartas"){

	std::vector<Carta>teste1;

	Carta cartaTeste7(1, 3);
	Carta cartaTeste8(4, 4);

	teste1.pushback(cartaTeste7);
	teste1.pushback(cartaTeste8);

	Mao maoTeste5(cartaTeste7, cartaTeste8);

	CHECK_EQ(maoTeste5.getCartas(), teste1);
}