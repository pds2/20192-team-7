#include <classes/dealer.hpp>
#include <test/doctest.h>

using namespace poker;

TEST_CASE("Testando o Construtor de Dealer"){
    CHECK_NOTHROW_MESSAGE(new Dealer(), "Construtor nº1 de Dealer OK!");
    CHECK_NOTHROW_MESSAGE(new Dealer(new EstadoJogo(new Baralho), 4), "Construtor nº2 de Dealer OK!");
}

TEST_CASE("Testando setters e getters"){
    Dealer dealer;
    EstadoJogo estadoTeste(new Baralho);
    CHECK_NOTHROW_MESSAGE(dealer.setNumeroJogadores(4), "Set numero de jogadores OK!");
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

TEST_CASE("Testando entregar o prêmio"){
    Dealer dealer;
    CHECK_NOTHROW_MESSAGE(dealer.entregarPremio(new Jogador), "Entregar prêmio OK!");
}

