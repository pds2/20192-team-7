#ifndef CARTA
#define CARTA

namespace poker{


	class Carta{
		private:
			int naipe;
			int simbolo;

		public:

			void Carta(int naip, int sim);

			int getNaipe();

			int getSimbolo();
	}
}

#endif