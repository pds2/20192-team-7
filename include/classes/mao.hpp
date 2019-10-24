#ifndef MAO
#define MAO
#include "carta.cpp"

namespace poker{

	class Mao{
		private:
			Carta cartas[2];

		public:

			void Mao(Carta primeira, Carta segunda);
			
			Carta* geteCartas();
	}
}

#endif