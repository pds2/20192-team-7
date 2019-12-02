#include <test/doctest.h>
#include <classes/jogador.hpp>
using namespace poker;

TEST_CASE("Testando o construtor da classe Jogador"){
    Pote* pote = new Pote();
    Mesa* mesa = new Mesa();
    CHECK_NOTHROW_MESSAGE(new Jogador("NOME", 2000, pote, mesa), "Construtor nº1 de Jogador OK!"); 
    CHECK_NOTHROW_MESSAGE(new Jogador("NOME", pote, mesa), "Construtor nº2 de Jogador OK!");
    CHECK_NOTHROW_MESSAGE(new Jogador(), "Construtor nº3 de Jogador OK!"); 
}

TEST_CASE("Testando setMao"){
    Pote* pote = new Pote();
    Mesa* mesa = new Mesa();
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao* mao =  new Mao(new Carta(Paus, Q), new Carta(Copas, J));
    CHECK_NOTHROW_MESSAGE(jogadorTeste.setMao(mao), "Mão setada OK!");    
}

TEST_CASE("Testando getMao"){
    Pote* pote = new Pote();
    Mesa* mesa = new Mesa();
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao* mao = new Mao(new Carta(Paus, Q),new  Carta(Copas, J));
    jogadorTeste.setMao(mao);
    CHECK_EQ(jogadorTeste.getMao(), mao);
}

TEST_CASE("Testando setUltimaAcao"){
    Pote* pote = new Pote();
    Mesa* mesa = new Mesa();
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    CHECK_NOTHROW_MESSAGE(jogadorTeste.setUltimaAcao("TESTE"), "Mão setada OK!");    
}

TEST_CASE("Testando getUltimaAcao"){
    Pote* pote = new Pote();
    Mesa* mesa = new Mesa();
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    jogadorTeste.setUltimaAcao("TESTE");
    CHECK_EQ(jogadorTeste.getUltimaAcao(), "TESTE");   
}

