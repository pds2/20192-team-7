#include "classes/carta.hpp"
#include "enums/ordemSequencia.hpp"
#include "enums/simbolo.hpp"
#include "enums/naipe.hpp"
#include <vector>
#include <string>

#ifndef UTIL_H
#define UTIL_H

namespace poker {

    class Util {
    
        public:
            std::vector<Carta*> OrdenaCartas(std::vector<Carta*> cartas);
            std::string ObterStringSimbolo(Simbolo simbolo);
            std::string ObterStringSequencia(OrdemSequencia sequencia);
            std::string ObterStringNaipe(Naipe naipe);
    };

}

#endif