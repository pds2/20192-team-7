#include "classes/carta.hpp"
#include <vector>

#ifndef MAO
#define MAO

namespace poker {
	
	class Mao {
		
		private:
			std::vector<Carta> cartas;
			
		public:
			Mao(Carta primeira, Carta segunda);
			std::vector<Carta> getCartas();
	};
}

#endif