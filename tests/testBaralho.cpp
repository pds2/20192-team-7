#include <test/doctest.h>
#include <classes/baralho.hpp>

using namespace poker;

TEST_CASE("Testando a construção do Baralho"){
    CHECK_NOTHROW_MESSAGE(new Baralho(),"Construção de Baralho OK!");
}

TEST_CASE("Testando o método Embaralhar"){
    Baralho baralho;
    CHECK_NOTHROW_MESSAGE(baralho.embaralhar(),"Embaralhar OK!");
}

TEST_CASE("Testando o método distribuir cartas"){
    std::vector<Carta> cartas;
    Baralho baralho;
    baralho.embaralhar();
    CHECK_NOTHROW_MESSAGE((cartas = baralho.distribuirCartas(5)), "Distribuição de cartas OK!");
    CHECK_THROWS_MESSAGE((cartas = baralho.distribuirCartas(70)), "Impossível retirar mais cartas existem no baralho OK!");
}

