#include <classes/dealer.hpp>
#include <test/doctest.h>

using namespace poker;

TEST_CASE("Testando o Construtor de Dealer"){
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    CHECK_NOTHROW_MESSAGE(new Dealer(), "Construtor nº1 de Dealer OK!");
    CHECK_NOTHROW_MESSAGE(new Dealer(EstadoJogo(baralhoPointer), 4), "Construtor nº2 de Dealer OK!");
}

TEST_CASE("Testando setters e getters"){
    Dealer dealer;
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    EstadoJogo estadoTeste(baralhoPointer);
    CHECK_NOTHROW_MESSAGE(dealer.setEstadoJogo(estadoTeste), "Set estado Jogo OK!");
    CHECK_NOTHROW_MESSAGE(dealer.setNumeroJogadores(4), "Set numero de jogadores OK!");
    CHECK_EQ(dealer.getMomentoJogo(), estadoTeste);
    CHECK_EQ(dealer.getNumeroJogadores(), 4);
}

TEST_CASE("Testando a inserção de jogadores"){
    Dealer dealer;
    CHECK_NOTHROW_MESSAGE(dealer.inserirJogadores(), "Inserir jogadores OK!");
}

TEST_CASE("Testando distribuir fichas"){
    Dealer dealer;
    dealer.inserirJogadores();
    CHECK_NOTHROW_MESSAGE(dealer.distribuirFichas(2000), "Inserir fichas OK!");
}

TEST_CASE("Testando iniciar a partida"){
    Dealer dealer;
    CHECK_NOTHROW_MESSAGE(dealer.iniciarPartida(), "Iniciar partida OK!");
}

TEST_CASE("Testando entregar o prêmio"){
    Pote poteTeste(20, 20, 0);
    Pote* pote = &poteTeste;
    Mesa* mesa;
    Dealer dealer;
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Jogador* pointerJogador = &jogadorTeste;
    CHECK_NOTHROW_MESSAGE(dealer.entregarPremio(pointerJogador), "Entregar prêmio OK!");
}

