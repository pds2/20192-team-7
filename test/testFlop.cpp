#include <test/doctest.h>
#include <classes/flop.hpp>
using namespace poker;

TEST_CASE("Testando o construtor de Flop"){
    Baralho* baralho =  new Baralho();
    CHECK_NOTHROW_MESSAGE(new Flop(baralho), "Construtor de Flop ok!");
}

TEST_CASE("Testando o método distribuirCartas de flop"){
    Flop flopTeste1(new Baralho);
    CHECK_THROWS_MESSAGE(flopTeste1.distribuirCartas(new Mesa), "Distribuição das cartas durante o Erro flop OK!" );
}

TEST_CASE("Testando o método validarApostas de flop"){
    Baralho* baralho = new Baralho();
    Mesa* mesaPointer1 = new Mesa();
    Pote* potePointer1 = new Pote();
    int valorApostaTeste1 = 50, valorApostaTeste2 = 500, valorApostaTeste3 = 2000, valorApostaTeste4 = -50;
    Jogador jogadorPointer( "NOME" , 200, potePointer1 , mesaPointer1);
    Flop flopTeste2(baralho);

    CHECK_EQ(flopTeste2.validarApostas(valorApostaTeste1, &jogadorPointer), 1);
    CHECK_EQ(flopTeste2.validarApostas(valorApostaTeste2, &jogadorPointer), 0);
    CHECK_EQ(flopTeste2.validarApostas(valorApostaTeste3, &jogadorPointer), 0);
    CHECK_THROWS(flopTeste2.validarApostas(valorApostaTeste4, &jogadorPointer));
}