#include <test/doctest.h>
#include <classes/jogadorHumano.hpp>

using namespace poker;

TEST_CASE("Testando o construtor de Jogador Humano"){
    Pote* pote;
    Mesa* mesa;
    CHECK_NOTHROW_MESSAGE(JogadorHumano("NOME", 2000, pote, mesa), "Construtor de Jogador Humano OK!");    
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
    CHECK_NOTHROW(jogadorTest.setMao(Mao(Carta(Copas, DOIS), Carta(Paus, TRES))));
    CHECK_EQ(jogadorTest.getMao(), Mao(Carta(Copas, DOIS), Carta(Paus, TRES))));
}

TEST_CASE("Testando o método Começar partida"){
    Pote poteTest(40, 20, 20);
    Mesa mesaTest(poteTest);
    Pote* pote = &poteTest;
    Mesa* mesa = &mesaTest;
    std::vector<Jogador*>bots;
    Jogador *Clinky = new Jogador("Clinky", 2000, poteTest, mesaTest);
    Jogador *Adilson = new Jogador("Adilson", 2000, poteTest, mesaTest);
    Jogador *Taylor = new Jogador("Taylor Swift", 2000, poteTest, mesaTest);
    bots.push_back(Clinky);
    bots.push_back(Adilson);
    bots.push_back(Taylor);
    JogadorHumano jogadorTest("NOME", 2000, pote, mesa);
    CHECK_EQ(jogadorTest.comecarPartida(), bots);
}

TEST_CASE("Testando o método Finalizar partida"){
    Pote poteTest(40, 20, 20);
    Mesa mesaTest(poteTest);
    Pote* pote = &poteTest;
    Mesa* mesa = &mesaTest;
    JogadorHumano jogadorTest("NOME", 2000, pote, mesa);   
    CHECK_NOTHROW_MESSAGE(jogadorTest.finalizarPartida(), "Finalizar partida OK!");
}