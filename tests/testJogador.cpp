#include <test/doctest.h>
#include <classes/jogador.hpp>
using namespace poker;

TEST_CASE("Testando o construtor da classe Jogador"){
    Pote* pote;
    Mesa* mesa;
    CHECK_NOTHROW_MESSAGE(Jogador("NOME", 2000, pote, mesa), "Construtor nº1 de Jogador OK!"); 
    CHECK_NOTHROW_MESSAGE(Jogador("NOME", pote, mesa), "Construtor nº2 de Jogador OK!");    
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

TEST_CASE("Testando apostar"){
    Pote poteTeste1(20,20,0);
    Pote poteTeste2(40, 20, 20);
    Pote* pote1 = &poteTeste1;
    Pote* pote2 = &poteTeste2;
    Mesa* mesa;
    Jogador jogadorTeste1("NOME", 2000, pote1, mesa);
    Jogador jogadorTeste2("NOME", 2000, pote2, mesa);
    CHECK_THROWS_MESSAGE(jogadorTeste1.apostar(200), "Impossível apostar com apostas já feitas na rodada OK!");
    CHECK_THROWS_MESSAGE(jogadorTeste2.apostar(0), "Impossível apostar valores <= 0 OK!");
    CHECK_THROWS_MESSAGE(jogadorTeste2.apostar(19), "Impossível apostar menos que o valor atual OK!");
    CHECK_THROWS_MESSAGE(jogadorTeste2.apostar(5000), "Impossível apostar mais que o valor de fichas disponíveis OK!");
    CHECK_NOTHROW_MESSAGE(jogadorTeste2.apostar(50), "Aposta válida OK!");
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
    std::vector<Carta*> royalFlushVector;
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
    Mao mao(new Carta(Copas, DEZ), new Carta(Copas, J));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "Royal Flush Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, royalFlushMap);
}

TEST_CASE("Testando analisar mão: Flush"){
    std::vector<Carta*> FlushVector;
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
    Mao mao(new Carta(Copas, SEIS),new Carta(Copas, SETE));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "Flush Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, FlushMap);
}

TEST_CASE("Testando analisar mão: Straight"){
    std::vector<Carta*> straightVector;
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
    Mao mao(new Carta(Espadas, SEIS), new Carta(Copas, SETE));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "Straight Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, straightMap);
}

TEST_CASE("Testando analisar mão: Straight Flush"){
    std::vector<Carta*> straightFlushVector;
    std::map<std::string, int> mapTeste;
    std::map<std::string, int> straightFlushMap;
    straightFlushMap.insert(std::pair<std::string, int>("Carta", SETE));
    straightFlushMap.insert(std::pair<std::string, int>("Sequencia", StraightFlush));
    straightFlushVector = {Carta(Copas, TRES), Carta(Copas, QUATRO), Carta(Copas, CINCO)};
    Mesa mesaTeste;
    Pote* pote;
    Mesa* mesa = &mesaTeste;
    mesaTeste.addCartas(straightFlushVector);
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao mao(new Carta(Copas, SEIS),new  Carta(Copas, SETE));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "Flush Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, straightFlushMap);
}

TEST_CASE("Testando analisar mão: Four of a Kind"){
    std::vector<Carta*> fourOfAKindVector;
    std::map<std::string, int> mapTeste;
    std::map<std::string, int> fourOfAKindMap;
    fourOfAKindMap.insert(std::pair<std::string, int>("Carta", CINCO));
    fourOfAKindMap.insert(std::pair<std::string, int>("Sequencia", FourOfAKind));
    fourOfAKindVector = {Carta(Copas, CINCO), Carta(Ouros, CINCO), Carta(Paus, CINCO)};
    Mesa mesaTeste;
    Pote* pote;
    Mesa* mesa = &mesaTeste;
    mesaTeste.addCartas(fourOfAKindVector);
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao mao(new Carta(Copas, SEIS),new  Carta(Espadas, CINCO));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "Four of a Kind Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, fourOfAKindMap);
}

TEST_CASE("Testando analisar mão: FullHouse"){
    std::vector<Carta*> fullHouseVector;
    std::map<std::string, int> mapTeste;
    std::map<std::string, int> fullHouseMap;
    fullHouseMap.insert(std::pair<std::string, int>("Carta", CINCO));
    fullHouseMap.insert(std::pair<std::string, int>("Sequencia", FullHouse));
    fullHouseVector = {Carta(Copas, CINCO), Carta(Ouros, CINCO), Carta(Paus, CINCO)};
    Mesa mesaTeste;
    Pote* pote;
    Mesa* mesa = &mesaTeste;
    mesaTeste.addCartas(fullHouseVector);
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao mao(new Carta(Copas, TRES),new Carta(Espadas, TRES));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "FullHouse Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, fullHouseMap);
}

TEST_CASE("Testando analisar mão: Three of a Kind"){
    std::vector<Carta*> threeOfAKindVector;
    std::map<std::string, int> mapTeste;
    std::map<std::string, int> threeOfAKindMap;
    threeOfAKindMap.insert(std::pair<std::string, int>("Carta", CINCO));
    threeOfAKindMap.insert(std::pair<std::string, int>("Sequencia", ThreeOfAKind));
    threeOfAKindVector = {Carta(Copas, CINCO), Carta(Ouros, CINCO), Carta(Paus, CINCO)};
    Mesa mesaTeste;
    Pote* pote;
    Mesa* mesa = &mesaTeste;
    mesaTeste.addCartas(threeOfAKindVector);
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao mao(new Carta(Copas, NOVE),new Carta(Espadas, TRES));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "Three of a Kind Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, threeOfAKindMap);
}

TEST_CASE("Testando analisar mão: Two Pairs"){
    std::vector<Carta*> twoPairsVector;
    std::map<std::string, int> mapTeste;
    std::map<std::string, int> twoPairsMap;
    twoPairsMap.insert(std::pair<std::string, int>("Carta", SETE));
    twoPairsMap.insert(std::pair<std::string, int>("Sequencia", TwoPair));
    twoPairsVector = {Carta(Copas, CINCO), Carta(Ouros, CINCO), Carta(Paus, SETE)};
    Mesa mesaTeste;
    Pote* pote;
    Mesa* mesa = &mesaTeste;
    mesaTeste.addCartas(twoPairsVector);
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao mao(new Carta(Copas, SETE),new Carta(Espadas, TRES));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "Two Pairs Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, twoPairsMap);
}

TEST_CASE("Testando analisar mão: Pair"){
    std::vector<Carta*> pairVector;
    std::map<std::string, int> mapTeste;
    std::map<std::string, int> pairMap;
    pairMap.insert(std::pair<std::string, int>("Carta", CINCO));
    pairMap.insert(std::pair<std::string, int>("Sequencia", Pair));
    pairVector = {Carta(Copas, CINCO), Carta(Ouros, CINCO), Carta(Paus, SETE)};
    Mesa mesaTeste;
    Pote* pote;
    Mesa* mesa = &mesaTeste;
    mesaTeste.addCartas(pairVector);
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao mao(new Carta(Copas, NOVE),new Carta(Espadas, TRES));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "Pair Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, pairMap);
}

TEST_CASE("Testando analisar mão: High Card"){
    std::vector<Carta*> highCardVector;
    std::map<std::string, int> mapTeste;
    std::map<std::string, int>highCardMap;
    highCardMap.insert(std::pair<std::string, int>("Carta", Q));
    highCardMap.insert(std::pair<std::string, int>("Sequencia", HighCard));
    highCardVector = {Carta(Copas, CINCO), Carta(Ouros, OITO), Carta(Paus, DOIS)};
    Mesa mesaTeste;
    Pote* pote;
    Mesa* mesa = &mesaTeste;
    mesaTeste.addCartas(highCardVector);
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao mao(new Carta(Copas, NOVE),new Carta(Espadas, Q));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "High Card Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, highCardMap);
}