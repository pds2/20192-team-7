#include "enums/naipe.hpp"
#include "enums/simbolo.hpp"

#ifndef CARTA
#define CARTA

namespace poker {

	class Carta {
		
		private:
			int naipe;
			int simbolo;

		public:
			Carta();
			Carta(Naipe naipe, Simbolo sim);
			int getNaipe();
			int getSimbolo();
	};
}

#endif