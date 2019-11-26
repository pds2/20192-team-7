#include <test/doctest.h>
#include <classes/jogadorHumano.hpp>

using namespace poker;

TEST_CASE("Testando o construtor de Jogador Humano"){
    Pote* pote;
    Mesa* mesa;
    CHECK_NOTHROW_MESSAGE(new JogadorHumano("NOME", 2000, pote, mesa), "1º Construtor de Jogador Humano OK!"); 
    CHECK_NOTHROW_MESSAGE(new JogadorHumano("NOME", pote, mesa), "2º Construtor de Jogador Humano OK!"); 
}


TEST_CASE("Testando os getters de Jogador Humano"){
    Pote poteTest(40, 20, 20);
    Mesa mesaTest(poteTest);
    Pote* pote = &poteTest;
    Mesa* mesa = &mesaTest;
    JogadorHumano jogadorTest("NOME", 2000, pote, mesa);   
    CHECK_EQ(jogadorTest.getMesa(), mesaTest);
    CHECK_EQ(jogadorTest.getPote(), poteTest);
    CHECK_EQ(jogadorTest.getNumeroFichas, 2000);
    Mao maoTest(Carta(Copas, DOIS), Carta(Paus, TRES));
    Mao* maoPointer = &maoTest;
    CHECK_NOTHROW(jogadorTest.setMao(maoPointer));
    CHECK_EQ(jogadorTest.getMao(), Mao(Carta(Copas, DOIS), Carta(Paus, TRES)));
}

TEST_CASE("Testando o método desistir partida"){
    Pote poteTest(40, 20, 20);
    Mesa mesaTest(poteTest);
    Pote* pote = &poteTest;
    Mesa* mesa = &mesaTest;
    JogadorHumano jogadorTest("NOME", 2000, pote, mesa);   
    CHECK_THROWS_MESSAGE(jogadorTest.desistirDaPartida(), "Desistir da partida OK!");
}

TEST_CASE("Testando o método Finalizar Jogo"){
    Pote poteTest(40, 20, 20);
    Mesa mesaTest(poteTest);
    Pote* pote = &poteTest;
    Mesa* mesa = &mesaTest;
    JogadorHumano jogadorTest("NOME", 2000, pote, mesa);   
    CHECK_THROWS_MESSAGE(jogadorTest.finalizarJogo(), "Finalizar jogo OK!");
}