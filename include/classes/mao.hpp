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
			Mao();
			std::vector<Carta> getCartas();
			void setCartas(std::vector<Carta> cartas);
	};
}

#endif