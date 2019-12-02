#include <test/doctest.h>
#include <classes/preflop.hpp>
using namespace poker;

TEST_CASE("Testando o construtor de Preflop"){
    Baralho* baralhoPointer = new Baralho();
    CHECK_NOTHROW_MESSAGE(new PreFlop(baralhoPointer), "Construtor de Preflop ok!");
}

TEST_CASE("Testando o método distribuirCartas de Preflop"){
    PreFlop preflopTeste1(new Baralho);
    CHECK_THROWS_MESSAGE(preflopTeste1.distribuirCartas(new Mesa), "Distribuição das cartas durante o Erro preflop OK!" );
}

TEST_CASE("Testando o método validarApostas de PreFlop"){
    Baralho* baralhoPointer = new Baralho();
    Mesa* mesaPointer1 = new Mesa();
    Pote* potePointer1 = new Pote();
    int valorApostaTeste1 = 50, valorApostaTeste2 = 500, valorApostaTeste3 = 2000, valorApostaTeste4 = -50;
    Jogador jogadorPointer( "NOME" , 200, potePointer1 , mesaPointer1);
    PreFlop preflopTeste2(baralhoPointer);

    CHECK_EQ(preflopTeste2.validarApostas(valorApostaTeste1, &jogadorPointer), 1);
    CHECK_EQ(preflopTeste2.validarApostas(valorApostaTeste2, &jogadorPointer), 0);
    CHECK_EQ(preflopTeste2.validarApostas(valorApostaTeste3, &jogadorPointer), 0);
    CHECK_THROWS(preflopTeste2.validarApostas(valorApostaTeste4, &jogadorPointer));
}