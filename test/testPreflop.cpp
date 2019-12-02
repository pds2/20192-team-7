#include <test/doctest.h>
#include <classes/preflop.hpp>
using namespace poker;

TEST_CASE("Testando o construtor de Preflop"){
    Baralho* baralhoPointer = new Baralho();
    CHECK_NOTHROW_MESSAGE(new PreFlop(baralhoPointer), "Construtor de Preflop ok!");
}

TEST_CASE("Testando o método distribuirCartas de PreFlop"){
    Baralho* baralhoPointer = new Baralho();
    PreFlop preflopTeste1(baralhoPointer);
    Mesa* mesaPointer = new Mesa();
    CHECK_NOTHROW_MESSAGE( preflopTeste1.distribuirCartas(mesaPointer), "Distribuição das cartas durante o PreFlop OK!" );
}

TEST_CASE("Testando o método de distribuirCartasJogadores de PreFlop"){
    Baralho* baralhoPointer = new Baralho();
    Mesa* mesa = new Mesa();
    Pote* pote = new Pote();
    PreFlop preflopTeste3(baralhoPointer);

    std::vector<Jogador*> jogadorTeste;

    Jogador* jogadores[7] = {
		new Jogador("Clinky", pote, mesa),
		new Jogador("Adilson", pote, mesa),
		new Jogador("Taylor Swift", pote, mesa),
		new Jogador("Bryan", pote, mesa),
		new Jogador("Julio", pote, mesa),
		new Jogador("Ricky", pote, mesa),
		new JogadorHumano("Morty", pote, mesa),
	};

    for(int i = 0; i < 7; i++)
        jogadorTeste.push_back(jogadores[i]);

    JogadorHumano* jogadorHumano = new JogadorHumano("Player", pote, mesa);

    CHECK_NOTHROW_MESSAGE(preflopTeste3.distribuirCartasJogadores(jogadorTeste,jogadorHumano), "Distribuição para os jogadores OK!");
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