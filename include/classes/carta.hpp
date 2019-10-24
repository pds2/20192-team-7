#ifndef CARTA
#define CARTA

class Carta{
	private:
		int naipe;
		int simbolo;

	public:

		void Carta(int naip, int sim){
			this->naipe = naipe;
			this->simbolo = simbolo;
		}

		int getNaipe();
		int getSimbolo();
}

#endif