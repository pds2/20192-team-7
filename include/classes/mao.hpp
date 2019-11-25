#include "classes/carta.hpp"
#include <vector>

#ifndef MAO
#define MAO

namespace poker {
	
	class Mao {
		
		private:
			std::vector<Carta*> cartas;
			
		public:
			Mao();
			Mao(Carta* primeira, Carta* segunda);

			void setCartas(std::vector<Carta*> cartas);
			std::vector<Carta*> getCartas();
	};
}

#endif