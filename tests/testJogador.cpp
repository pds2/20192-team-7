#include <test/doctest.h>
#include <classes/jogador.hpp>
using namespace poker;

TEST_CASE("Testando o construtor da classe Jogador"){
    Pote* pote;
    Mesa* mesa;
    CHECK_NOTHROW_MESSAGE(new Jogador("NOME", 2000, pote, mesa), "Construtor nº1 de Jogador OK!"); 
    CHECK_NOTHROW_MESSAGE(new Jogador("NOME", pote, mesa), "Construtor nº2 de Jogador OK!");
    CHECK_NOTHROW_MESSAGE(new Jogador(), "Construtor nº3 de Jogador OK!"); 
}

TEST_CASE("Testando setMao"){
    Pote* pote;
    Mesa* mesa;
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao* mao =  new Mao(new Carta(Paus, Q), new Carta(Copas, J));
    CHECK_NOTHROW_MESSAGE(jogadorTeste.setMao(mao), "Mão setada OK!");    
}

TEST_CASE("Testando getMao"){
    Pote* pote;
    Mesa* mesa;
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao* mao = new Mao(new Carta(Paus, Q),new  Carta(Copas, J));
    jogadorTeste.setMao(mao);
    CHECK_EQ(jogadorTeste.getMao(), mao);
}

TEST_CASE("Testando setUltimaAcao"){
    Pote* pote;
    Mesa* mesa;
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    CHECK_NOTHROW_MESSAGE(jogadorTeste.setUltimaAcao("TESTE"), "Mão setada OK!");    
}

TEST_CASE("Testando getUltimaAcao"){
    Pote* pote;
    Mesa* mesa;
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    jogadorTeste.setUltimaAcao("TESTE");
    CHECK_EQ(jogadorTeste.getMao(), "TESTE");   
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
    royalFlushVector = {new Carta(Copas, Q), new Carta(Copas, K),new  Carta(Copas, A)};
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
    FlushVector = {new Carta(Copas, TRES),new Carta(Copas, NOVE),new Carta(Copas, DEZ)};
    Pote* pote;
    Mesa* mesa = new Mesa();
    mesa->addCartas(FlushVector);
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
    straightVector = {new Carta(Copas, TRES),new Carta(Paus, QUATRO),new Carta(Ouros, CINCO)};
    Mesa mesaTeste;
    Pote* pote;
    Mesa* mesa = new Mesa();
    mesa->addCartas(straightVector);
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
    straightFlushVector = {new Carta(Copas, TRES),new Carta(Copas, QUATRO),new Carta(Copas, CINCO)};
    Pote* pote;
    Mesa* mesa = new Mesa();
    mesa->addCartas(straightFlushVector);
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
    fourOfAKindVector = {new Carta(Copas, CINCO),new Carta(Ouros, CINCO),new Carta(Paus, CINCO)};
    Pote* pote;
    Mesa* mesa = new Mesa();
    mesa->addCartas(fourOfAKindVector);
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
    fullHouseVector = {new Carta(Copas, CINCO),new  Carta(Ouros, CINCO),new Carta(Paus, CINCO)};
    Pote* pote;
    Mesa* mesa = new Mesa();
    mesa->addCartas(fullHouseVector);
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
    threeOfAKindVector = {new Carta(Copas, CINCO),new  Carta(Ouros, CINCO),new  Carta(Paus, CINCO)};
    Pote* pote;
    Mesa* mesa = new Mesa();
    mesa->addCartas(threeOfAKindVector);
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao* mao = new Mao(new Carta(Copas, NOVE),new Carta(Espadas, TRES));
    jogadorTeste.setMao(mao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "Three of a Kind Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, threeOfAKindMap);
}

TEST_CASE("Testando analisar mão: Two Pairs"){
    std::vector<Carta*> twoPairsVector;
    std::map<std::string, int> mapTeste;
    std::map<std::string, int> twoPairsMap;
    twoPairsMap.insert(std::pair<std::string, int>("Carta", SETE));
    twoPairsMap.insert(std::pair<std::string, int>("Sequencia", TwoPair));
    twoPairsVector = {new Carta(Copas, CINCO),new Carta(Ouros, CINCO),new Carta(Paus, SETE)};
    Pote* pote;
    Mesa* mesa = new Mesa();
    mesa->addCartas(twoPairsVector);
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
    pairVector = {new Carta(Copas, CINCO),new Carta(Ouros, CINCO),new Carta(Paus, SETE)};
    Pote* pote;
    Mesa* mesa = new Mesa();
    mesa->addCartas(pairVector);
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
    highCardVector = {new Carta(Copas, CINCO),new Carta(Ouros, OITO),new Carta(Paus, DOIS)};
    Pote* pote;
    Mesa* mesa = new Mesa();
    mesa->addCartas(highCardVector);
    Jogador jogadorTeste("NOME", 2000, pote, mesa);
    Mao mao(new Carta(Copas, NOVE),new Carta(Espadas, Q));
    Mao* pointerMao = &mao;
    jogadorTeste.setMao(pointerMao);
    CHECK_NOTHROW_MESSAGE(mapTeste = jogadorTeste.analisarMao(), "High Card Analisar mão sem exceções OK!");
    CHECK_EQ(mapTeste, highCardMap);
}

TEST_CASE("Testando realizarJogada: Apostar"){
    Pote poteTeste1(20, 20, 0);
    Pote poteTeste2(40, 20, 20);
    Pote* pote1 = &poteTeste1;
    Pote* pote2 = &poteTeste2;
    Mesa* mesa;
    Jogador jogadorTeste1("NOME", 2000, pote1, mesa);
    Jogador jogadorTeste2("NOME", 2000, pote2, mesa);
    CHECK_NOTHROW_MESSAGE(jogadorTeste2.realizarJogada("apostar"), "Apostar OK!");
    CHECK_THROWS_MESSAGE(jogadorTeste1.realizarJogada("apostar"), "Impossível apostar nessa etapa OK!");
}

TEST_CASE("Testando realizarJogada: check"){
    Pote poteTeste1(20, 20, 0);
    Pote poteTeste2(40, 20, 20);
    Pote* pote1 = &poteTeste1;
    Pote* pote2 = &poteTeste2;
    Mesa* mesa;
    Jogador jogadorTeste1("NOME", 2000, pote1, mesa);
    Jogador jogadorTeste2("NOME", 2000, pote2, mesa);
    CHECK_NOTHROW_MESSAGE(jogadorTeste2.realizarJogada("check"), "Desistir OK!");
    CHECK_THROWS_MESSAGE(jogadorTeste1.realizarJogada("check"), "Impossível desistir nessa etapa OK!");
}

TEST_CASE("Testando realizarJogada: pagar"){
    Pote poteTeste1(20, 20, 0);
    Pote poteTeste2(40, 20, 20);
    Pote* pote1 = &poteTeste1;
    Pote* pote2 = &poteTeste2;
    Mesa* mesa;
    Jogador jogadorTeste1("NOME", 2000, pote1, mesa);
    Jogador jogadorTeste2("NOME", 2000, pote2, mesa);
    CHECK_THROWS_MESSAGE(jogadorTeste2.realizarJogada("pagar"), "Impossível pagar nessa etapa OK!");
    CHECK_NOTHROW_MESSAGE(jogadorTeste1.realizarJogada("pagar"), "Pagar OK!");
}

TEST_CASE("Testando realizarJogada: aumentar"){
    Pote poteTeste1(20, 20, 0);
    Pote poteTeste2(40, 20, 20);
    Pote* pote1 = &poteTeste1;
    Pote* pote2 = &poteTeste2;
    Mesa* mesa;
    Jogador jogadorTeste1("NOME", 2000, pote1, mesa);
    Jogador jogadorTeste2("NOME", 2000, pote2, mesa);
    CHECK_THROWS_MESSAGE(jogadorTeste2.realizarJogada("aumentar"), "Impossível aumentar nessa etapa OK!");
    CHECK_NOTHROW_MESSAGE(jogadorTeste1.realizarJogada("aumentar"), "Aumentar OK!");
}

TEST_CASE("Testando jogar"){
    std::map<std::string, bool> opcoesJogador;
    opcoesJogador.insert(std::pair<std::string, int>("aumentar", true));
    opcoesJogador.insert(std::pair<std::string, int>("pagar", true));
    opcoesJogador.insert(std::pair<std::string, int>("check", false));
    opcoesJogador.insert(std::pair<std::string, int>("apostar", false));
    std::map<std::string, bool> opcoesJogador2;
    opcoesJogador2.insert(std::pair<std::string, int>("aumentar", false));
    opcoesJogador2.insert(std::pair<std::string, int>("pagar", false));
    opcoesJogador2.insert(std::pair<std::string, int>("check", true));
    opcoesJogador2.insert(std::pair<std::string, int>("apostar", true));
    Pote poteTeste2(20, 20, 0);
    Pote poteTeste1(40, 20, 20);
    Pote* pote1 = &poteTeste1;
    Pote* pote2 = &poteTeste2;
    Mesa* mesa;
    Jogador jogadorTeste1("NOME", 2000, pote1, mesa);
    Jogador jogadorTeste2("NOME", 2000, pote2, mesa);
    CHECK_NOTHROW_MESSAGE(jogadorTeste2.jogar(opcoesJogador2), "Jogar 1 OK!");
    CHECK_NOTHROW_MESSAGE(jogadorTeste1.jogar(opcoesJogador), "Jogar 2 OK!");
}