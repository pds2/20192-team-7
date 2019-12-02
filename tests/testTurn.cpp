#include <test/doctest.h>
#include <classes/turn.hpp>
using namespace poker;

TEST_CASE("Testando o construtor de Turn"){
    Baralho* baralhoPointer = new Baralho();
    CHECK_NOTHROW_MESSAGE(new Turn(baralhoPointer), "Construtor de Turn ok!");
}

TEST_CASE("Testando o método distribuirCartas de turn"){
    Baralho* baralhoPointer = new Baralho();
    Turn turnTeste1(baralhoPointer);
    Mesa* mesaPointer;
    CHECK_NOTHROW_MESSAGE( turnTeste1.distribuirCartas(mesaPointer), "Distribuição das cartas durante o Turn OK!" );
}

TEST_CASE("Testando o método validarApostas de turn"){
    Baralho* baralhoPointer = new Baralho();
    Mesa* mesaPointer1;
    Pote* potePointer1;
    int valorApostaTeste1 = 50, valorApostaTeste2 = 500, valorApostaTeste3 = 2000, valorApostaTeste4 = -50;
    Jogador jogadorPointer( "NOME" , 200, potePointer1 , mesaPointer1);
    Turn turnTeste2(baralhoPointer);

    CHECK_EQ(turnTeste2.validarApostas(valorApostaTeste1, &jogadorPointer), 1);
    CHECK_EQ(turnTeste2.validarApostas(valorApostaTeste2, &jogadorPointer), 0);
    CHECK_EQ(turnTeste2.validarApostas(valorApostaTeste3, &jogadorPointer), 0);
    CHECK_THROWS(turnTeste2.validarApostas(valorApostaTeste4, &jogadorPointer));
}