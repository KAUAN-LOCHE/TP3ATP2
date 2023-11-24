//✓Nome do Jogador
//✓Data de Nascimento
//✓CPF
//✓Gênero
//✓ Estado civil
//✓ Equipe
//➢ Nome
//➢ Nickname da rede social
//➢ Número de seguidores na rede social
//✓ Patrocinadora principal
//✓ Nickname da rede social
//✓ Número de seguidores em redes sociais

// ✓ Equipamento de Hardware
// ➢ Modelo do computador/notebook
// ➢ Processador
// ➢ Placa de vídeo
// ➢ Quantidade de Memória RAM
// ✓ Dados do campeonato
// ➢ Pontuação no campeonato
// ➢ Quantidade de vitórias (3 pontos por vitória)
// ➢ Quantidade de derrotas (0 pontos por derrota)
// ➢ Quantidade de empates (1 ponto por empate)
// ✓ Quantidade de títulos que o jogador ganhou
// ✓ Posição do rank mundial

//✓Funções para a escrita e leitura de diferentes jogadores e de todos os dados que o norteiam. Assim possibilitando cadastro de jogadores.
//✓ Possibilitar a alteração, ou seja, correção dos dados de um jogador.
//✓ Inserir vitória, derrota ou empate para um jogador e com isso atualizar sua pontuação no campeonato.
//✓ Listar todos os jogadores ordem alfabética
//✓ Listar todos os jogadores por ordem de sua posição no rank mundial
//✓ Listar jogadores que possuem maior número de vitórias no campeonato
//✓ Mostrar (listar) classificação do campeonato com nome, posição no campeonato, pontuação, quantidade de vitorias, derrotas e empates.
//✓ Listar jogadores com pontuação no campeonato maior que um certo valor
// ✓ Listar jogadores com pontuação no campeonato menor que um certo valor
// ✓ Buscar um jogador por nome
// ✓ Buscar um jogador por posição no rank mundial
// ✓ Mostrar a quantidade média de seguidores de um jogador do campeonato, ou seja, um jogador do campeonato possui em média quantos seguidores.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Funcoes.h"

int main(){
    //Menu e utilizacao funções//
    int n;
    printf("Este e um programa para manipular structs de jogadores gravados em arquivos binarios\n");
    printf("Digite quantidade de jogadores: ");
    scanf("%d", &n);

    JOGADOR jogadores[n], jogadoreslidos[n];
    AUX auxiliar[n];

    CriarVetor_aux(jogadores, auxiliar, n);

    int limite;
    
    int opcao;
    do{
        printf("Escolha uma opcao: \n");
        printf("1 - Gravar jogadores;\n");
        printf("2 - Ler jogadores;\n");
        printf("3 - Alterar jogador;\n");
        printf("4 - Alterar pontuacao;\n");
        printf("5 - Listar jogadores ordem alfabetica;\n");
        printf("6 - Listar jogadores posicao rank mundial;\n");
        printf("7 - Listar jogadores que possuem maior numero de vitorias;\n");
        printf("8 - Listar classificacao campeonato;\n");
        printf("9 - Listar jogadores com pontuacao maior que;\n");
        printf("10 - Listar jogadores com pontuacao menor que;\n");
        printf("11 - Buscar jogador por nome;");
        printf("12 - Buscar jogador por rank mundial;\n");
        printf("13 - Mostrar media seguidores jogadores;\n");
        printf("14 - Sair");
        scanf("%d", &opcao);

        string100 chaves;
        int a;


        switch (opcao){
            case 1:
                EscreverJogadoresVetor(n);
                EscreverJogadoresArquivoBinario(n);
                break;

            case 2:
                LerJogadoresArquivoBinario(jogadoreslidos, n);
                break;

            case 3:
                printf("Digite numero jogador alterar: ");
                scanf("%d", &a);
                AlterarDadosJogadorArquivoBinario(a, n);
                break;

            case 4:
                printf("Digite numero jogador alterar: ");
                scanf("%d", &a);
                InserirVitoriaEmpateDerrota(a);
                break;

            
             case 5:
                OrdenarJogadores_alfabeto( n);
                break;
            
            case 6:
                OrdenarJogadores_posicao( n);
                break;
            
            case 7:
                OrdenarJogadores_vitoria( n);
                break;
            
            case 8:
                ListarJogadores_posicaoCampeonato(n);
                break;
            
            case 9:
                printf("Digite o liimite de pontos para que seja listado os jogadores com pontuaÃ§Ã£o maior: ");
                scanf("%d", &limite);
                ListarJogadores_PontuacaoMaior(n, limite );
                break;
            
            case 10:
                printf("Digite o liimite de pontos para que seja listado os jogadores com pontuaÃ§Ã£o menor: ");
                scanf("%d", &limite);
                ListarJogadores_PontuacaoMenor( n , limite);
                break;
            
            case 11:
                printf("Digite nome: ");
                gets(chaves);
                BuscarJogadorNome(chaves);
                break;

            case 12:
                int chave;
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
    }while(opcao != 14);
}




