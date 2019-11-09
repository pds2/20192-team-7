#include <vector>
#include <classes/carta.hpp>

#ifndef UTIL_H
#define UTIL_H

namespace poker{
    
class Util{
  
    public:
        std::vector<Carta> OrdenaCartas(std::vector<Carta> cartas);
};

}

#endif