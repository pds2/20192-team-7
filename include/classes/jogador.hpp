#include <classes/mao.hpp>
#include <classes/pote.hpp>
#include <classes/mesa.hpp>
#include <enums/ordemSequencia.hpp>
#ifndef JOGADOR_H
#define JOGADOR_H 

namespace poker{

	class Jogador{

		private:
                  Mao* mao;
                  Pote* pote;
                  Mesa* mesa;
                  unsigned int numeroFichas;
			
		public:
                  Jogador(int numeroFichas, Pote* pote, Mesa* mesa);
                  void pagarAposta();
                  void aumentarAposta(unsigned int valorNovaAposta);
                  void desistirDaPartida();
                  void passarVez();
                  void analisarMao();
                  void setMao(Mao mao);
                  Mao getMao();                
	};

}
#endif