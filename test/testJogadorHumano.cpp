#include <test/doctest.h>
#include <classes/jogadorHumano.hpp>

using namespace poker;

TEST_CASE("Testando o construtor de Jogador Humano"){
    Pote* pote = new Pote();
    Mesa* mesa = new Mesa();
    CHECK_NOTHROW_MESSAGE(new JogadorHumano("NOME", 2000, pote, mesa), "1º Construtor de Jogador Humano OK!"); 
    CHECK_NOTHROW_MESSAGE(new JogadorHumano("NOME", pote, mesa), "2º Construtor de Jogador Humano OK!"); 
}


TEST_CASE("Testando os getters de Jogador Humano"){
    Pote poteTest(40, 20, 20);
    Mesa* mesaTest = new Mesa(poteTest);
    Pote* pote = &poteTest;
    JogadorHumano jogadorTest("NOME", 2000, pote, mesaTest);   
    CHECK_EQ(jogadorTest.getMesa(), mesaTest);
    CHECK_EQ(jogadorTest.getPote(), pote);
    CHECK_EQ(jogadorTest.getNumeroFichas(), 2000);
    Mao* maoPointer= new Mao(new Carta(Copas, DOIS),new  Carta(Paus, TRES));
    CHECK_NOTHROW(jogadorTest.setMao(maoPointer));
    CHECK_EQ(jogadorTest.getMao(), new Mao(new Carta(Copas, DOIS), new Carta(Paus, TRES)));
}

TEST_CASE("Testando o método desistir partida"){
    Pote poteTest(40, 20, 20);
    Mesa* mesaTest = new Mesa(poteTest);
    Pote* pote = &poteTest;
    JogadorHumano jogadorTest("NOME", 2000, pote, mesaTest);  
    CHECK_THROWS_MESSAGE(jogadorTest.desistirDaPartida(), "Desistir da partida OK!");
}

TEST_CASE("Testando o método Finalizar Jogo"){
    Pote poteTest(40, 20, 20);
    Mesa* mesaTest = new Mesa(poteTest);
    Pote* pote = &poteTest;
    JogadorHumano jogadorTest("NOME", 2000, pote, mesaTest);   
    CHECK_THROWS_MESSAGE(jogadorTest.finalizarJogo(), "Finalizar jogo OK!");
}