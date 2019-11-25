#include <test/doctest.h>
#include <classes/preflop.hpp>
using namespace poker;


TEST_CASE("Testando o método distribuirCartas de PreFlop"){
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    PreFlop preflopTeste1(baralhoPointer);
    Mesa* mesaPointer;
    CHECK_NOTHROW_MESSAGE( preflopTeste1.distribuirCartas(mesaPointer), "Distribuição das cartas durante o PreFlop OK!" );
}

TEST_CASE("Testando o método de distribuirCartasJogadores de PreFlop"){
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    Mesa* mesa;
    Pote* pote;
    PreFlop preflopTeste3(baralhoPointer);

    std::vector<Jogador> jogadorTeste;

    Jogador jogadores[7] = {
		Jogador("Clinky", pote, mesa),
		Jogador("Adilson", pote, mesa),
		Jogador("Taylor Swift", pote, mesa),
		Jogador("Bryan", pote, mesa),
		Jogador("Julio", pote, mesa),
		Jogador("Ricky", pote, mesa),
		JogadorHumano("Morty", pote, mesa),
	};

    for(int i = 0; i < 7; i++)
        jogadorTeste.push_back(jogadores[i]);

    CHECK_NOTHROW_MESSAGE(preflopTeste3.distribuirCartasJogadores(jogadorTeste), "Distribuição para os jogadores OK!");
}

TEST_CASE("Testando o método validarApostas de PreFlop"){
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    Mesa* mesaPointer1;
    Pote* potePointer1;
    int valorApostaTeste1 = 50, valorApostaTeste2 = 500, valorApostaTeste3 = 2000, valorApostaTeste4 = -50;
    Jogador jogadorPointer( "NOME" , 200, potePointer1 , mesaPointer1);
    PreFlop preflopTeste2(baralhoPointer);

    CHECK_EQ(preflopTeste2.validarApostas(valorApostaTeste1, &jogadorPointer), 1);
    CHECK_EQ(preflopTeste2.validarApostas(valorApostaTeste2, &jogadorPointer), 0);
    CHECK_EQ(preflopTeste2.validarApostas(valorApostaTeste3, &jogadorPointer), 0);
    CHECK_THROWS(preflopTeste2.validarApostas(valorApostaTeste4, &jogadorPointer));
}