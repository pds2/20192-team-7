#include <vector>
#include <classes/carta.hpp>
#include <classes/pote.hpp>

#ifndef MESA_H
#define MESA_H

class Mesa{
	private:
		std::vector<Carta> cartasMesa;
		Pote pote;

	public:
		Mesa();
		void addCartas(std::vector<Carta> cartasMesa);
		int getPoteTotal();
		int getPoteAtual();
		int getPoteAnterior();
		int setPoteTotal();
		int setPoteAtual();
		int setPoteAnterior();
};

#endif