#include "naipe.hpp"
#include "simbolo.hpp"

#ifndef CARTA
#define CARTA

namespace poker {
	class Carta {
		private:
			int naipe;
			int simbolo;

		public:
			Carta(Naipe naipe, Simbolo sim);
			int getNaipe();
			int getSimbolo();
	};
}

#endif