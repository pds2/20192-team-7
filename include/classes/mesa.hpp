#include <vector>
#ifndef MESA
#define MESA

class Mesa{
	private:
		std::vector<Carta> cartasMesa;
		Pote* pote = new Pote;
	public:
		Mesa();
		void addCartas(std::vector<Carta> cartasMesa);
};

#endif