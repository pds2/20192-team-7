# 20192-team-7

Projeto da disciplina deProgramação e Desenvolvimento de Software 2 do curso de Sistemas de Informação da UFMG.

## Descrição

Jogo de Poker Texas Hold'em desenvolvido em C++

## User stories

* Como jogador eu quero aumentar a aposta para aumentar o valor do pote e ganhar mais (raise)
* Critérios de aceitação:
  * O jogador deve estar participando da jogada
  * O valor do pote deve ser acrescido
  * O jogador deve ter o valor para aumentar a aposta
  * O valor deve ser descontado do valor das fichas do jogador


* Como jogador eu quero seguir o jogo para continuar na rodada e manter o valor do pote (check)
* Critérios de aceitação:
  * O jogador deve estar participando da jogada
  * O valor da aposta não deve ter sido alterado na rodada
  * O jogador deve se manter no jogo
  * As fichas do jogador devem ser mantidas


* Como jogador eu quero aceitar a aposta para continuar na rodada e aumentar o valor do pote (call)
* Critérios de aceitação:
  * O jogador deve estar participando da jogada
  * O valor da aposta deve ter sido alterado na rodada
  * O jogador deve se manter no jogo
  * O valor deve ser descontado do valor das fichas do jogador


* Como jogador eu quero desistir da jogada para sair da mesa (fold)
* Critérios de aceitação:
  * O jogador deve estar participando da jogada
  * O jogador deve ser retirado da mesa
  * Se for o pré-flop, as fichas não são descontadas
  * O valor deve ser descontado do valor das fichas do jogador se tiver passado do flop


* Como jogador eu quero iniciar o jogo para poder jogar
* Critérios de aceitação:
  * O jogador deve informar o número de bots a jogar contra
  * O jogador deve ser inserido no jogo
  * Os bots devem ser inseridos no jogo
  * O jogador deve receber 2 cartas
  * Os bots devem receber 2 cartas
  * O jogador deve receber um valor inicial em fichas
  * Os bots devem receber um valor inicial em fichas


* Como jogador eu quero finalizar o jogo para poder sair do jogo
* Critérios de aceitação:
  * O jogador deve estar jogando anteriormente
  * O jogador deve confirmar que deseja sair
  * O jogo deve ser encerrado


* Como jogador eu quero saber o que tenho na mão para poder tomar decisões na jogada
* Critérios de aceitação:
  * O jogador deve estar participando da jogada
  * O sistema deve informar a sequência que o jogador tem na mão
  * O sistema deve informar a hierarquia das sequências e onde a mão do jogador se encontra nessa hierarquia




## CRCs


Classe | Dealer
-------|--------
Responsabilidades | Colaborações
Atributos: | Baralho
Momento do jogo | Mesa
Número de jogadores | Pote
""| EtapaJogo
Métodos:
Iniciar partida
Distribuir fichas
Incluir jogadores
Iniciar pré-flop
Iniciar flop
Iniciar turn
Iniciar river
Mostrar mão atual do jogador
Verificar resultado da partida
Entregar prêmio

Classe | EtapaJogo
-------|--------
Responsabilidades | Colaborações
Atributos:| Baralho
Momento do jogo | Jogador
Número de jogadores | Mão
 | Mesa
Métodos: | Pote
Validar Apostas
Distribuir Cartas
Verificar Opções de Ação Do Jogador

Classe | PreFlop
-------|--------
Responsabilidades | Colaborações
Atributos:| Baralho
Momento do jogo | Jogador
Número de jogadores | Mão
 | Mesa
Métodos: | Pote
Validar Apostas | Bot
Distribuir Cartas | EtapaJogo (Herança por polimorfismo)
Verificar Opções de Ação Do Jogador

Classe | Flop
-------|--------
Responsabilidades | Colaborações
Atributos:| Baralho
Momento do jogo | Jogador
Número de jogadores | Mão
 | Mesa
Métodos: | Pote
Validar Apostas | Bot
Distribuir Cartas | EtapaJogo (Herança por polimorfismo)
Verificar Opções de Ação Do Jogador

Classe | Turn
-------|--------
Responsabilidades | Colaborações
Atributos:| Baralho
Momento do jogo | Jogador
Número de jogadores | Mão
 | Mesa
Métodos: | Pote
Validar Apostas | Bot
Distribuir Cartas | EtapaJogo (Herança por polimorfismo)
Verificar Opções de Ação Do Jogador

Classe | River
-------|--------
Responsabilidades | Colaborações
Atributos:| Baralho
Momento do jogo | Jogador
Número de jogadores | Mão
 | Mesa
Métodos: | Pote
Validar Apostas | Bot
Distribuir Cartas | EtapaJogo (Herança por polimorfismo)
Verificar Opções de Ação Do Jogador

Classe | Carta
-------|--------
Responsabilidades | Colaborações
Atributos: | Naipe
Naipe | Símbolo
Símbolo


Classe | Baralho
-------|--------
Responsabilidades | Colaborações
Atributos: | Cartas
Cartas 
Métodos: 
Embaralhar
Distribuir cartas


Classe | Mesa
-------|--------
Responsabilidades | Colaborações
Atributos: | Pote
Cartas | Carta
Pote | Baralho
Métodos: 
Adicionar cartas à mesa

Classe | Pote
-------|--------
Responsabilidades | Colaborações
Atributos: | Jogador
Valor total | Mesa
Valor aposta atual
Valor aposta anterior
Métodos:
Alterar valor aposta atual
Substituir aposta anterior
Alterar valor total


Classe | Jogador
-------|--------
Responsabilidades | Colaborações
Atributos: | Mão
Mão | Pote
Fichas | Baralho
Métodos: | OrdemSequencia
Pagar a aposta | EstadoJogo
Aumentar a aposta
Desistir da partida
Passar a vez
Analisar mão

Classe | Jogador
-------|--------
Responsabilidades | Colaborações
Atributos: | Mão
Mão | Pote
Fichas | Baralho
Métodos: | OrdemSequencia
Pagar a aposta | EtapaJogo
Aumentar a aposta | Jogador (Herança)
Desistir da partida
Passar a vez
Analisar mão

Classe | JogadorHumano
-------|--------
Responsabilidades | Colaborações
Atributos: | Jogador(Herança)
Mão | Mão
Fichas | Pote
 |Baralho
Métodos: | OrdemSequencia
Pagar a aposta | EtapaJogo
Começar Partida
Finalizar Jogo
Pagar a aposta
Aumentar a aposta

Classe | Mão
-------|--------
Responsabilidades | Colaborações
Atributos: | Cartas
Cartas (Coleção de cartas) | Jogador
"" | Naipe
"" | Símbolo


Enum: Naipe
-------
Ouros = 1;
Paus = 2;
Copas = 3;
Espadas = 4;


Enum: Símbolo
-------
A;
2;
3;
4;
5;
6;
7;
8;
9;
10;
J;
Q;
K;


Enum: OrdemSequencia
---------------
HighCard = 1;
Pair = 2;
TwoPair = 3;
ThreeOfAKind = 4;
Straight = 5;
Flush = 6;
FullHouse = 7;
FourOfAKind = 8;
StraightFlush = 9;
RoyalFlush = 10;

