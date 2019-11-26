#include <test/doctest.h>
#include <classes/river.hpp>
using namespace poker;

TEST_CASE("Testando o construtor de River"){
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    CHECK_NOTHROW_MESSAGE(new River(baralhoPointer), "Construtor de River ok!");
}

TEST_CASE("Testando o método distribuirCartas de river"){
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    River riverTeste1(baralhoPointer);
    Mesa* mesaPointer;
    CHECK_NOTHROW_MESSAGE( riverTeste1.distribuirCartas(mesaPointer), "Distribuição das cartas durante o River OK!" );
}

TEST_CASE("Testando o método validarApostas de river"){
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    Mesa* mesaPointer1;
    Pote* potePointer1;
    int valorApostaTeste1 = 50, valorApostaTeste2 = 500, valorApostaTeste3 = 2000, valorApostaTeste4 = -50;
    Jogador jogadorPointer( "NOME" , 200, potePointer1 , mesaPointer1);
    River riverTeste2(baralhoPointer);

    CHECK_EQ(riverTeste2.validarApostas(valorApostaTeste1, &jogadorPointer), 1);
    CHECK_EQ(riverTeste2.validarApostas(valorApostaTeste2, &jogadorPointer), 0);
    CHECK_EQ(riverTeste2.validarApostas(valorApostaTeste3, &jogadorPointer), 0);
    CHECK_THROWS(riverTeste2.validarApostas(valorApostaTeste4, &jogadorPointer));
}