#ifndef MESA
#define MESA

class Mesa{
	private:
		Carta* cartasMesa = new Carta[5];
		Pote* pote = new Pote;
	public:
		addCartas(Carta);
};

#endif