//âNome do Jogador
//âData de Nascimento
//âCPF
//âGÃªnero
//â Estado civil
//â Equipe
//â¢ Nome
//â¢ Nickname da rede social
//â¢ NÃºmero de seguidores na rede social
//â Patrocinadora principal
//â Nickname da rede social
//â NÃºmero de seguidores em redes sociais

// â Equipamento de Hardware
// â¢ Modelo do computador/notebook
// â¢ Processador
// â¢ Placa de vÃ­deo
// â¢ Quantidade de MemÃ³ria RAM
// â Dados do campeonato
// â¢ PontuaÃ§Ã£o no campeonato
// â¢ Quantidade de vitÃ³rias (3 pontos por vitÃ³ria)
// â¢ Quantidade de derrotas (0 pontos por derrota)
// â¢ Quantidade de empates (1 ponto por empate)
// â Quantidade de tÃ­tulos que o jogador ganhou
// â PosiÃ§Ã£o do rank mundial

//âFunÃ§Ãµes para a escrita e leitura de diferentes jogadores e de todos os dados que o norteiam. Assim possibilitando cadastro de jogadores.
//â Possibilitar a alteraÃ§Ã£o, ou seja, correÃ§Ã£o dos dados de um jogador.
//â Inserir vitÃ³ria, derrota ou empate para um jogador e com isso atualizar sua pontuaÃ§Ã£o no campeonato.
//â Listar todos os jogadores ordem alfabÃ©tica
//â Listar todos os jogadores por ordem de sua posiÃ§Ã£o no rank mundial
//â Listar jogadores que possuem maior nÃºmero de vitÃ³rias no campeonato
//â Mostrar (listar) classificaÃ§Ã£o do campeonato com nome, posiÃ§Ã£o no campeonato, pontuaÃ§Ã£o, quantidade de vitorias, derrotas e empates.
//â Listar jogadores com pontuaÃ§Ã£o no campeonato maior que um certo valor
// â Listar jogadores com pontuaÃ§Ã£o no campeonato menor que um certo valor
// â Buscar um jogador por nome
// â Buscar um jogador por posiÃ§Ã£o no rank mundial
// â Mostrar a quantidade mÃ©dia de seguidores de um jogador do campeonato, ou seja, um jogador do campeonato possui em mÃ©dia quantos seguidores.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Funcoes.h"
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    //Menu e utilizacao funÃ§Ãµes//
    int n;
    printf("Este e um programa para manipular structs de jogadores gravados em arquivos binarios\n");
    printf("Digite quantidade de jogadores: ");
    scanf("%d", &n);

    JOGADOR jogadores[n], jogadoreslidos[n];

    LerArquivo_Vetor(jogadores, n);


    
    int opcao;
    do{
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
        printf("14 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        string100 chaves;
        int a, chave, limite;


        switch (opcao){
            case 1:
                EscreverJogadoresVetor(n);
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
                OrdenarJogadores_alfabeto( jogadores, n);
                break;
            
            case 6:
                OrdenarJogadores_posicao( jogadores, n);
                break;
            
            case 7:
                OrdenarJogadores_vitoria( jogadores, n);
                break;
            
            case 8:
                OrdenarJogadores_posicao(jogadores, n);
                ListarJogadores_posicaoCampeonato(jogadores, n);
                break;
            
            case 9:
                printf("Digite o liimite de pontos para que seja listado os jogadores com pontuaÃÂ§ÃÂ£o maior: ");
                scanf("%d", &limite);
                ListarJogadores_PontuacaoMaior(jogadores, n, limite );
                break;
            
            case 10:
                printf("Digite o liimite de pontos para que seja listado os jogadores com pontuaÃÂ§ÃÂ£o menor: ");
                scanf("%d", &limite);
                ListarJogadores_PontuacaoMenor(jogadores, n , limite);
                break;
            
            case 11:
                printf("Digite nome: ");
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
    }while(opcao != 14);
}




