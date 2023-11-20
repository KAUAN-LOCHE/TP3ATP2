#ifndef FUNCOES_H
#define FUNCOES_H


//Variavel string100//
typedef char string100[100];

//variável CPF 
typedef char CPF[11];

//Genero
typedef enum genero{
    masculino, feminino
}GENERO;

typedef enum Est_civil{
    casado, solteiro, divorciado, viúvo
}EST_CIVIL;

//Data de nascimento
typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

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


typedef struct jogador{
    string100 nome;
    DATA data;
    CPF cpf;
    GENERO genero;
    EST_CIVIL civil;
    EQUIPE equipe;  
    string100 patrocinadora;
    string100 nickname_jogador;
    int seguidores_jogador;
    HARDWARE hardware;
    CAMPEONATO campeonato;
    TITULOS titulo;
    RANKING ranking;
}JOGADOR;


typedef struct aux{
    string100 nome_aux;
    int ranking_aux;
    int vitorias_aux;
    int pontuacao_aux;
    int derrotas_aux;
    int empates_aux;
}AUX;



void EscreverJogadoresVetor(JOGADOR *jogadores, int n);
void EscreverJogadoresArquivoBinario(JOGADOR *jogadores, int n);
void LerJogadoresArquivoBinario(JOGADOR *jogadoreslidos, int n);
void AlterarDadosJogadorArquivoBinario(JOGADOR *jogadores, int a);
void InserirVitoriaEmpateDerrota(JOGADOR *jogadores, int a);
void BuscarJogadorNome(JOGADOR *jogadores, string100 chave);
void BuscarJogadorRank(JOGADOR *jogadores, int chave);
void MostrarMediaSeguidoresJogadores(JOGADOR *jogadores, int n);
void CriarVetor_aux(JOGADOR* jogadores, AUX * auxiliar, int n);
void OrdenarJogadores_alfabeto( AUX*auxiliares, int n);
void OrdenarJogadores_VetorAux(AUX * auxiliar, int n);
void OrdenarJogadores_posicao( AUX * auxiliar, int n,);
void OrdenarJogadores_vitoria ( AUX * auxiliar, int n,);
void ListarJogadores_posicaoCampeonato ( AUX * auxiliar, int n, JOGADOR * jogadores);
void ListarJogadores_PontuacaoMenor (AUX * auxiliar, int n, int limite);
void ListarJogadores_PontuacaoMaior (AUX * auxiliar, int n, int limite)


#endif

