#include <test/doctest.h>
#include <classes/jogador.hpp>
using namespace poker;

TEST_CASE("Testando o construtor da classe Jogador"){
    Pote* pote;
    Mesa* mesa;
    CHECK_NOTHROW_MESSAGE(Jogador("NOME", 2000, pote, mesa), "Construtor de Jogador OK!");    
}

TEST_CASE("Testando setMao"){
    Pote* pote;
    Mesa* mesa;
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao mao(Carta(Paus, Q), Carta(Copas, J));
    Mao* pointerMao = &mao;
    CHECK_NOTHROW_MESSAGE(jogadorTeste.setMao(pointerMao), "Mão setada OK!");    
}

TEST_CASE("Testando getMao"){
    Pote* pote;
    Mesa* mesa;
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao mao(Carta(Paus, Q), Carta(Copas, J));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_EQ(jogadorTeste.getMao(), mao);
}

