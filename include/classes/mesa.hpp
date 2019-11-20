#include <vector>
#include <classes/carta.hpp>
#include <classes/pote.hpp>

#ifndef MESA_H
#define MESA_H

namespace poker{

	class Mesa{
		private:
			std::vector<Carta> cartasMesa;
			Pote pote;

		public:
			Mesa();
			Mesa(Pote pote);

			void addCartas(std::vector<Carta> cartasMesa);
			std::vector<Carta> getCartasMesa();

			void setPoteApostaTotal(int valorTotal);
			void setPoteApostaAtual(int valorAtual);
			void setPoteApostaAnterior(int valorAnterior);

			int getPoteTotal();
			int getPoteApostaAtual();
			int getPoteApostaAnterior();

			void poteAlterarApostaTotal(int novoValorTotal);
			void poteAlterarApostaAtual(int novoValorAtual);
			void poteAlterarApostaAnterior(int novoValorAnterior);

	};

}
#endif