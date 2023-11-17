#ifndef FUNCOES_H
#define FUNCOES_H


//Variavel string100//
typedef char string100[100];

//Struct Hardware//
typedef enum computador{
    Desktop, Notebook
}COMPUTADOR;


typedef struct hardware{
    COMPUTADOR computer;
    string100 cpu;
    string100 gpu;
    int ram;
}HARDWARE;

//Struct Dados do Campeonato//
typedef struct campeonato{
    int victories;
    int draws;
    int losses;
    int points;
}CAMPEONATO;

//Struct Títulos Campeonato//
typedef struct titulos{
    int titles;
}TITULOS;

//Struct Posicao Ranking Mundial//
typedef struct ranking{
    int rank;
}RANKING;

void EscreverJogadoresVetor(JOGADOR *jogadores, int n);
void EscreverJogadoresArquivoBinario(JOGADOR *jogadores, int n);
void LerJogadoresArquivoBinario(JOGADOR *jogadoreslidos, int n);
void AlterarDadosJogadorArquivoBinario(JOGADOR *jogadores, int a);
void InserirVitoriaEmpateDerrota(JOGADOR *jogadores, int a);
void BuscarJogadorNome(JOGADOR *jogadores, string100 chave);
void BuscarJogadorRank(JOGADOR *jogadores, int chave);
void MostrarMediaSeguidoresJogadores(JOGADOR *jogadores, int n);


#endif

