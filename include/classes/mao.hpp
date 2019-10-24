#ifndef MAO
#define MAO
#include "carta.cpp"

class Mao{
	private:
		Carta cartas[2];

	public:

		void Mao(Carta primeira, Carta segunda){
			this->cartas[0] = primeira;
			this->cartas[1] = segunda;
		}

		// talvez nao seja a coisa mais pratica do mundo
		// mas eu achei melhor 2 gets diferentes pra cada carta

		Carta* geteCartas();
}

#endif