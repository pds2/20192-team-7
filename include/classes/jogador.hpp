#include <classes/mao.hpp>

#ifndef JOGADOR_H
#define JOGADOR_H 


namespace poker{

	class Jogador{

		private:
            Mao mao;
            unsigned int numeroFichas;
			
		public:
        
            Jogador();
            void PagarAposta();
            void AumentarAposta();
            void DesistirDaPartida();
            void PassarVez();
            void AnalisarMao();
		
	};

}
#endif