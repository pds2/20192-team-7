#include "classes/pokerExceptions.hpp"
#include "classes/mao.hpp"
#include "classes/pote.hpp"
#include "classes/mesa.hpp"
#include "enums/ordemSequencia.hpp"
#include "classes/util.hpp"

#include <map>
#include <vector>
#include <string>

#ifndef JOGADOR_H
#define JOGADOR_H 

namespace poker {

	class Jogador {

      protected:
          Mao* mao;
          Pote* pote;
          Mesa* mesa;
          unsigned int numeroFichas;
          std::string nome;

      public:
          Jogador();
          Jogador(std::string nome, Pote* pote, Mesa* mesa);
          Jogador(std::string nome, int numeroFichas, Pote* pote, Mesa* mesa);

          void setMao(Mao* mao);
          Mao* getMao();
          void setNumeroFichas(int numeroFichas);
          unsigned int getNumeroFichas();
          std::string getNome();

          void passarVez();
          void apostar(int valorAposta);
          void pagarAposta();
          void aumentarAposta(int valorNovaAposta);

          void jogar(std::map<std::string, bool> opcoesJogador, Pote* pote);

          std::map<std::string, int> analisarMao();
	};

}
#endif