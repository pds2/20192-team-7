#ifndef POTE_H
#define POTE_H

namespace poker{
    
    class Pote{
    	private:
            int valorTotal;
            int valorApostaAtual;
            int valorApostaAnterior;

        public:

            Pote();

            Pote(int valorTotal,int valorApostaAtual, int valorApostaAnterior);

            void setValorTotal(int valorTotal);

            void setValorApostaAtual(int valorApostaAtual);
    
            void setValorApostaAnterior(int valorApostaAnterior);

            int getValorTotal();

            int getValorApostaAtual();

            int getValorApostaAnterior();

            void alterarValorAposta(int novoValorAposta);

            void substituirApostaAnterior(int novoValorApostaAnterior);

            void alterarValorTotal(int novoValorTotal);
        }
}

#endif