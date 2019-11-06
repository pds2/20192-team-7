#include <classes/mao.hpp>
#ifndef JOGADOR_H
#define JOGADOR_H 

namespace poker{

	class Jogador{

		private:
                  Mao* mao;
                  unsigned int numeroFichas;
			
		public:
                  Jogador();
                  void pagarAposta(unsigned int valorAposta);
                  void aumentarAposta();
                  void desistirDaPartida();
                  void passarVez();
                  void analisarMao();
                  void setMao(Mao mao);
                  Mao getMao();                
	};

}
#endif