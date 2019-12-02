#include <test/doctest.h>
#include <classes/estadojogo.hpp>
using namespace poker;

TEST_CASE("Testando os construtores de EstadoJogo"){
    CHECK_NOTHROW_MESSAGE(new EstadoJogo(), "Construtor nº1 OK!");
    CHECK_NOTHROW_MESSAGE(new EstadoJogo(new Baralho), "Construtor nº2 OK!");
}

TEST_CASE("Testando verificar Opcoes do jogador"){
    EstadoJogo estadojogo(new Baralho);
    std::map<std::string, bool> mapaOpcoesJogador;
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("check", false));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("apostar", false));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("desistir", false));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("pagar", false));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("aumentar", false));
    Pote poteTeste1(20, 20, 0);
    Pote poteTeste2(40, 20, 20);
    Pote* pote1 = &poteTeste1;
    Mesa* mesa = new Mesa();
    Jogador jogadorTeste("NOME", 2, pote1, mesa);
    Jogador* pointer1 = &jogadorTeste;
    CHECK_EQ(estadojogo.verificarOpcoesJogador(pointer1, pote1), mapaOpcoesJogador);
}