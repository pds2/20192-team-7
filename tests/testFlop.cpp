#include <test/doctest.h>
#include <classes/flop.hpp>
using namespace poker;

TEST_CASE("Testando o construtor de Flop"){
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    CHECK_NOTHROW_MESSAGE(new Flop(baralhoPointer), "Construtor de Flop ok!");
}

TEST_CASE("Testando o método distribuirCartas de flop"){
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    Flop flopTeste1(baralhoPointer);
    Mesa* mesaPointer;
    CHECK_NOTHROW_MESSAGE( flopTeste1.distribuirCartas(mesaPointer), "Distribuição das cartas durante o Flop OK!" );
}

TEST_CASE("Testando o método validarApostas de flop"){
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    Mesa* mesaPointer1;
    Pote* potePointer1;
    int valorApostaTeste1 = 50, valorApostaTeste2 = 500, valorApostaTeste3 = 2000, valorApostaTeste4 = -50;
    Jogador jogadorPointer( "NOME" , 200, potePointer1 , mesaPointer1);
    Flop flopTeste2(baralhoPointer);

    CHECK_EQ(flopTeste2.validarApostas(valorApostaTeste1, &jogadorPointer), 1);
    CHECK_EQ(flopTeste2.validarApostas(valorApostaTeste2, &jogadorPointer), 0);
    CHECK_EQ(flopTeste2.validarApostas(valorApostaTeste3, &jogadorPointer), 0);
    CHECK_THROWS(flopTeste2.validarApostas(valorApostaTeste4, &jogadorPointer));
}