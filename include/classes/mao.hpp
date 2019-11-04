#ifndef MAO
#define MAO
#include "classes/carta.hpp"

namespace poker {
	
	class Mao {
		
		private:
			Carta cartas[2];

		public:
			Mao(Carta &primeira, Carta &segunda);
			Carta* getCartas();
	};
}

#endif