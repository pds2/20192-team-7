#include <test/doctest.h>
#include <classes/estadojogo.hpp>
using namespace poker;

TEST_CASE("Testando os construtores de EstadoJogo"){
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    CHECK_NOTHROW_MESSAGE(EstadoJogo(), "Construtor nº1 OK!");
    CHECK_NOTHROW_MESSAGE(EstadoJogo(baralhoPointer), "Construtor nº2 OK!");
}

TEST_CASE("Testando verificarOpcoes do jogador"){
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    EstadoJogo estadojogo(baralhoPointer);
    std::map<std::string, bool> mapaOpcoesJogador;
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("check", false));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("apostar", false));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("desistir", false));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("pagar", false));
    mapaOpcoesJogador.insert(std::pair<std::string, bool>("aumentar", false));
    std::map<std::string, bool> mapaOpcoesJogadorHumano;
    mapaOpcoesJogadorHumano.insert(std::pair<std::string, bool>("check", true));
    mapaOpcoesJogadorHumano.insert(std::pair<std::string, bool>("apostar", true));
    mapaOpcoesJogadorHumano.insert(std::pair<std::string, bool>("desistir", true));
    mapaOpcoesJogadorHumano.insert(std::pair<std::string, bool>("pagar", false));
    mapaOpcoesJogadorHumano.insert(std::pair<std::string, bool>("aumentar", false));
    Pote poteTeste1(20, 20, 0);
    Pote poteTeste2(40, 20, 20);
    Pote* pote1 = &poteTeste1;
    Pote* pote2 = &poteTeste2;
    Mesa* mesa;
    Jogador jogadorTeste("NOME", 2, pote1, mesa);
    JogadorHumano jogadorHumanoTeste("HUMANO", 2000, pote2, mesa);
    Jogador* pointer1 = &jogadorTeste;
    Jogador* pointer2 = &jogadorHumanoTeste;
    CHECK_EQ(estadojogo.verificarOpcoesJogador(pointer1, pote1), mapaOpcoesJogador);
    CHECK_EQ(estadojogo.verificarOpcoesJogador(pointer2, pote2), mapaOpcoesJogadorHumano);
}