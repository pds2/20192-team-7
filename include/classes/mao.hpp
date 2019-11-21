#ifndef MAO
#define MAO

#include "classes/carta.hpp"
#include <vector>

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