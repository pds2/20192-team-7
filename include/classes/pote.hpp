#ifndef POTE_H
#define POTE_H

namespace poker {

    class Pote {
        
    	private:
            unsigned int valorTotal;
            unsigned int valorApostaAtual;
            unsigned int valorApostaAnterior;

        public:
            Pote();
            Pote(unsigned int valorTotal, unsigned int valorApostaAtual, unsigned int valorApostaAnterior);
            
            void setValorTotal(unsigned int valorTotal);
            void setValorApostaAtual(unsigned int valorApostaAtual);
            void setValorApostaAnterior(unsigned int valorApostaAnterior);
            unsigned int getValorTotal();
            unsigned int getValorApostaAtual();
            unsigned int getValorApostaAnterior();
    };
}

#endif