#include <classes/mao.hpp>
#include <classes/pote.hpp>
#ifndef JOGADOR_H
#define JOGADOR_H 

namespace poker{

	class Jogador{

		private:
                  Mao* mao;
                  unsigned int numeroFichas;
                  Pote* pote;
			
		public:
                  Jogador(int numeroFichas, Pote pote);
                  void pagarAposta();
                  void aumentarAposta(unsigned int valorAposta);
                  void desistirDaPartida();
                  void passarVez();
                  void analisarMao();
                  void setMao(Mao mao);
                  Mao getMao();                
	};

}
#endif