#include <test/doctest.h>
#include <classes/mesa.hpp>
using namespace poker;

TEST_CASE("Testando o construtor vazio da classe Mesa"){
    CHECK_NOTHROW(Mesa());
}

TEST_CASE("Testando o construtor parametrizado da classe Mesa"){
    Pote poteTest;
    CHECK_NOTHROW(Mesa(poteTest));
}

TEST_CASE("Testando Adição de Cartas"){
    Mesa mesaTeste;
    std::vector<Carta*> vectorTeste;
    for (int i=0; i<5; i++){
        vectorTeste.push_back(new Carta(Copas, Q));
    }
    CHECK_NOTHROW_MESSAGE(mesaTeste.addCartas(vectorTeste), "Cartas adicionadas a mesa!");
}

TEST_CASE("Testando Retorno de Cartas"){
    Mesa mesaTeste;
    std::vector<Carta*> vectorTeste;
    for (int i=0; i<5; i++){
        vectorTeste.push_back(new Carta(Copas, Q));
    }
    mesaTeste.addCartas(vectorTeste);
    CHECK_EQ(mesaTeste.getCartasMesa(), vectorTeste);
}

TEST_CASE("Testando Setters"){
    Mesa mesaTeste;
    CHECK_NOTHROW_MESSAGE(mesaTeste.setPoteApostaTotal(1), "setPoteApostaTotal OK!");
    CHECK_NOTHROW_MESSAGE(mesaTeste.setPoteApostaAtual(1), "setPoteAposstaAtual OK!");
    CHECK_NOTHROW_MESSAGE(mesaTeste.setPoteApostaAnterior(1), "setPoteApostaAnterior OK!");
}

TEST_CASE("Testando Getters"){
    Mesa mesaTeste;
    mesaTeste.setPoteApostaTotal(1);
    mesaTeste.setPoteApostaAtual(1);
    mesaTeste.setPoteApostaAnterior(1);
    CHECK_EQ(mesaTeste.getPoteTotal(), 1);
    CHECK_EQ(mesaTeste.getPoteApostaAtual(), 1);
    CHECK_EQ(mesaTeste.getPoteApostaAnterior(), 1);
}
