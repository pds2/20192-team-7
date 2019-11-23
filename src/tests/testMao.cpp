#include <classes/mao.hpp>
#include <test/doctest.h>

using namespace poker;

TEST_CASE("Testando o construtor de Mao"){

	Carta cartaTeste1(Paus, Q);
	Carta cartaTeste2(Copas, Q);
	Carta cartaTeste3(Ouros, Q);
	Carta cartaTeste4(Espadas, Q);
	Carta cartaTeste5(Paus, QUATRO);
	Carta cartaTeste6(Copas, SETE);

	CHECK_NOTHROW(Mao(cartaTeste1, cartaTeste2));
	CHECK_NOTHROW(Mao(cartaTeste3, cartaTeste4));
	CHECK_NOTHROW(Mao(cartaTeste5, cartaTeste6));
}

TEST_CASE("Testando getCartas"){

	std::vector<Carta> teste1;
	Carta cartaTeste7(Copas, Q);
	Carta cartaTeste8(Paus, Q);
	teste1.push_back(cartaTeste7);
	teste1.push_back(cartaTeste8);
	Mao maoTeste5(cartaTeste7, cartaTeste8);

	CHECK_EQ(maoTeste5.getCartas(), teste1);
}