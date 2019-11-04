#ifndef CARTA
#define CARTA

#include "enums/naipe.hpp"
#include "enums/simbolo.hpp"

namespace poker {

	class Carta {
		
		private:
			Naipe naipe;
			Simbolo simbolo;

		public:
			Carta();
			Carta(int naipe, int sim);
			Carta(Naipe naipe, Simbolo sim);
			int getNaipe();
			int getSimbolo();
	};
}

#endif