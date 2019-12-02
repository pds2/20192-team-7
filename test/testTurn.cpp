#include <test/doctest.h>
#include <classes/turn.hpp>
using namespace poker;

TEST_CASE("Testando o construtor de Turn"){
    Baralho* baralhoPointer = new Baralho();
    CHECK_NOTHROW_MESSAGE(new Turn(baralhoPointer), "Construtor de Turn ok!");
}

TEST_CASE("Testando o método distribuirCartas de turn"){
    Turn turnTeste1(new Baralho);
    CHECK_THROWS_MESSAGE(turnTeste1.distribuirCartas(new Mesa), "Distribuição das cartas durante o Erro flop OK!" );
}

TEST_CASE("Testando o método validarApostas de turn"){
    Baralho* baralhoPointer = new Baralho();
    Mesa* mesaPointer1 = new Mesa();
    Pote* potePointer1 =  new Pote();
    int valorApostaTeste1 = 50, valorApostaTeste2 = 500, valorApostaTeste3 = 2000;
    Jogador jogadorPointer( "NOME" , 200, potePointer1 , mesaPointer1);
    Turn turnTeste2(baralhoPointer);

    CHECK_EQ(turnTeste2.validarApostas(valorApostaTeste1, &jogadorPointer), 1);
    CHECK_EQ(turnTeste2.validarApostas(valorApostaTeste2, &jogadorPointer), 0);
    CHECK_EQ(turnTeste2.validarApostas(valorApostaTeste3, &jogadorPointer), 0);
}