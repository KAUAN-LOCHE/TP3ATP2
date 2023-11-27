/*
? Nome do Jogador
? Data de Nascimento
? CPF
? G?nero
? Estado civil
? Equipe
? Nome
? Nickname da rede social
? N?mero de seguidores na rede social
? Patrocinadora principal
? Nickname da rede social
? N?mero de seguidores em redes sociais
? Equipamento de Hardware
? Modelo do computador/notebook
? Processador
? Placa de v?deo
? Quantidade de Mem?ria RAM
? Dados do campeonato
? Pontua??o no campeonato
? Quantidade de vit?rias (3 pontos por vit?ria)
? Quantidade de derrotas (0 pontos por derrota)
? Quantidade de empates (1 ponto por empate)
? Quantidade de t?tulos que o jogador ganhou
? Posi??o do rank mundial

? Fun??es para a escrita e leitura de diferentes jogadores e de todos os
dados que o norteiam. Assim possibilitando cadastro de jogadores.
? Possibilitar a altera??o, ou seja, corre??o dos dados de um jogador.
? Inserir vit?ria, derrota ou empate para um jogador e com isso atualizar sua pontua??o no campeonato.
? Listar todos os jogadores ordem alfab?tica por nome
? Listar todos os jogadores por ordem de sua posi??o no rank mundial
? Listar jogadores que possuem maior n?mero de vit?rias no campeonato
? Mostrar (listar) classifica??o do campeonato com nome, posi??o no
campeonato, pontua??o, quantidade de vitorias, derrotas e empates.
? Listar jogadores com pontua??o no campeonato maior que um certo valor
? Listar jogadores com pontua??o no campeonato menor que um certo valor
? Buscar um jogador por nome
? Buscar um jogador por posi??o no rank mundial
? Mostrar a quantidade m?dia de seguidores de um jogador do campeonato, ou seja, um jogador do campeonato possui em m?dia quantos seguidores.
*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Funcoes.h"
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    //Menu e utiliza??o fun??es//
    int n;
    printf("Este e um programa para manipular structs de jogadores gravados em arquivos binarios\n");
    printf("Digite quantidade de jogadores: ");
    scanf("%d", &n);

    JOGADOR jogadores[n], jogadoreslidos[n];



    
    int opcao;
    do{
        printf("1 - Gravar jogadores;\n");
        printf("2 - Ler jogadores;\n");
        printf("3 - Alterar jogador;\n");
        printf("4 - Alterar pontuação;\n");
        printf("5 - Listar jogadores ordem alfabética;\n");
        printf("6 - Listar jogadores posição rank mundial;\n");
        printf("7 - Listar jogadores que possuem maior número de vitórias;\n");
        printf("8 - Listar classificação campeonato;\n");
        printf("9 - Listar jogadores com pontuação maior que;\n");
        printf("10 - Listar jogadores com pontuação menor que;\n");
        printf("11 - Buscar jogador por nome;\n");
        printf("12 - Buscar jogador por rank mundial;\n");
        printf("13 - Mostrar m?dia seguidores jogadores;\n");
        printf("14 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        string100 chaves;
        int a, chave, limite;


        switch (opcao){
            case 1:
                EscreverJogadoresArquivoBinario(n);
                break;

            case 2:
                LerJogadoresArquivoBinario();
                break;

            case 3:
                printf("Digite numero jogador alterar: ");
                scanf("%d", &a);
                AlterarDadosJogadorArquivoBinario(a);
                break;

            case 4:
                printf("Digite numero jogador alterar: ");
                scanf("%d", &a);
                InserirVitoriaEmpateDerrota(a);
                break;

            
             case 5:
                LerArquivo_Vetor(jogadores);
                OrdenarJogadores_alfabeto( jogadores, n);

                break;
            
            case 6:
                LerArquivo_Vetor(jogadores);
                OrdenarJogadores_posicao( jogadores, n);

                break;
            
            case 7:
                LerArquivo_Vetor(jogadores);
                OrdenarJogadores_vitoria( jogadores, n);

                break;
            
            case 8:
                LerArquivo_Vetor(jogadores);
                ListarJogadores_posicaoCampeonato(jogadores, n);
                break;
            
            case 9:
                LerArquivo_Vetor(jogadores);
                printf("Digite o liimite de pontos para que seja listado os jogadores com pontuaÃÂ§ÃÂ£o maior: ");
                scanf("%d", &limite);
                ListarJogadores_PontuacaoMaior(jogadores, n, limite );
                break;
            
            case 10:
                LerArquivo_Vetor(jogadores);
                printf("Digite o liimite de pontos para que seja listado os jogadores com pontuaÃÂ§ÃÂ£o menor: ");
                scanf("%d", &limite);
                ListarJogadores_PontuacaoMenor(jogadores, n , limite);
                break;
            
            case 11:
                printf("Digite nome: ");
                fflush(stdin);
                gets(chaves);
                BuscarJogadorNome(chaves);
                break;

            case 12:
                printf("Digite rank: ");
                scanf("%d", &chave);
                BuscarJogadorRank(chave);
                break;

            case 13:
                MostrarMediaSeguidoresJogadores(n);
                break;

            case 14:
                printf("Saiu do programa");
                break;

            default:
                printf("Opcao invalida! Digite outra:");
                break;
        }
        system("pause");
    }while(opcao != 14);
}




