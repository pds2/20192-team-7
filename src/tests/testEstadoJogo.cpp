#include <test/doctest.h>
#include <classes/estadojogo.hpp>
using namespace poker;

TEST_CASE("Testando os construtores de EstadoJogo"){
    Baralho baralho;
    Baralho* baralhoPointer = &baralho;
    CHECK_NOTHROW_MESSAGE(EstadoJogo(), "Construtor nº1 OK!");
    CHECK_NOTHROW_MESSAGE(EstadoJogo(baralhoPointer), "Construtor nº1 OK!");
}