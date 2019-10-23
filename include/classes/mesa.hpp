#ifndef MESA
#define MESA

class Mesa{
	private:
		Carta* cartasMesa = new Carta[5];
		Pote* pote = new Pote;
	public:
		Mesa();
		void addCartas(Carta);
};

#endif