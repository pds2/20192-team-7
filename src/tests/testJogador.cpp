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

TEST_CASE("Testando pagar aposta"){
    Pote poteTeste(20, 20, 0);
    Pote* pote = &poteTeste;
    Mesa* mesa;
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Jogador jogadorTeste2("NOME", 19, pote, mesa);
    CHECK_NOTHROW(jogadorTeste.pagarAposta());
    CHECK_EQ(poteTeste.getValorApostaAtual(), 20);
    CHECK_EQ(poteTeste.getValorTotal(), 40);
    CHECK_EQ(poteTeste.getValorApostaAnterior(), 20);
    CHECK_THROWS_MESSAGE(jogadorTeste2.pagarAposta(), "Impossível pagar mais fichas que o total OK!");
}

TEST_CASE("Testando aumentar aposta"){
    Pote poteTeste(20, 20, 0);
    Pote* pote = &poteTeste;
    Mesa* mesa;
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Jogador jogadorTeste2("NOME", 19, pote, mesa);
    CHECK_NOTHROW(jogadorTeste.aumentarAposta(21));
    CHECK_EQ(poteTeste.getValorApostaAtual(), 21);
    CHECK_EQ(poteTeste.getValorTotal(), 41);
    CHECK_EQ(poteTeste.getValorApostaAnterior(), 20);
    CHECK_THROWS_MESSAGE(jogadorTeste2.aumentarAposta(21), "Impossível pagar mais fichas que o total OK!");
    CHECK_THROWS_MESSAGE(jogadorTeste.aumentarAposta(15), "Impossível aumentar a aposta com um valor inferior que o antigo OK!");
}

TEST_CASE("Testando desistir da partida"){
    Pote poteTeste(20, 20, 0);
    Pote* pote = &poteTeste;
    Mesa* mesa;
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    CHECK_THROWS_MESSAGE(jogadorTeste.desistirDaPartida(), "Desistir da partida OK!");
}

TEST_CASE("Testando passar vez"){
    Pote poteTeste(40, 20, 20);
    Pote* pote = &poteTeste;
    Mesa* mesa;
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Jogador jogadorTeste2("NOME", 19, pote, mesa);
    CHECK_NOTHROW_MESSAGE(jogadorTeste.passarVez(), "Passar a vez OK!");
    jogadorTeste2.pagarAposta();
    CHECK_THROWS_MESSAGE(jogadorTeste.passarVez(), "Impossível passar vez quando o jogador anterior modificou as apostas OK!");
}

TEST_CASE("Testando analisar mão: Royal Flush"){
    std::vector<Carta> royalFlushVector;
    std::map<std::string, int> mapTeste;
    std::map<std::string, int> royalFlushMap;
    royalFlushMap.insert(std::pair<std::string, int>("Carta", A));
    royalFlushMap.insert(std::pair<std::string, int>("Sequencia", RoyalFlush));
    royalFlushVector = {Carta(Copas, Q), Carta(Copas, K), Carta(Copas, A)};
    Mesa mesaTeste;
    Pote* pote;
    Mesa* mesa = &mesaTeste;
    mesaTeste.addCartas(royalFlushVector);
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao mao(Carta(Copas, DEZ), Carta(Copas, J));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, royalFlushMap);
}

TEST_CASE("Testando analisar mão: Flush"){
    std::vector<Carta> FlushVector;
    std::map<std::string, int> mapTeste;
    std::map<std::string, int> FlushMap;
    FlushMap.insert(std::pair<std::string, int>("Carta", DEZ));
    FlushMap.insert(std::pair<std::string, int>("Sequencia", Flush));
    FlushVector = {Carta(Copas, TRES), Carta(Copas, NOVE), Carta(Copas, DEZ)};
    Mesa mesaTeste;
    Pote* pote;
    Mesa* mesa = &mesaTeste;
    mesaTeste.addCartas(FlushVector);
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao mao(Carta(Copas, SEIS), Carta(Copas, SETE));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, FlushMap);
}

TEST_CASE("Testando analisar mão: Straight"){
    std::vector<Carta> straightVector;
    std::map<std::string, int> mapTeste;
    std::map<std::string, int> straightMap;
    straightMap.insert(std::pair<std::string, int>("Carta", SETE));
    straightMap.insert(std::pair<std::string, int>("Sequencia", Straight));
    straightVector = {Carta(Copas, TRES), Carta(Paus, QUATRO), Carta(Ouros, CINCO)};
    Mesa mesaTeste;
    Pote* pote;
    Mesa* mesa = &mesaTeste;
    mesaTeste.addCartas(straightVector);
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao mao(Carta(Espadas, SEIS), Carta(Copas, SETE));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, straightMap);
}