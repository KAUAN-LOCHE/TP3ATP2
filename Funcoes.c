#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Funcoes.h"
#include <locale.h>

//função de pular linha
void PularLinha(int num){
    for(int i = 0; i < num;i++){
        printf("\n");
    }
}

//Função Escrever Jogadores Vetor//

void EscreverJogadoresVetor(JOGADOR jogadores[], int n){
    for(int i=0; i<n; i++){
        //Nome Jogador//
        printf("Nome jogador: ");
        fflush(stdin);
        gets(jogadores[i].nome);

        //Nascimento//
        printf("Dia nascimento: ");
        scanf("%d", &jogadores[i].data.dia);
        printf("Mes nascimento: ");
        scanf("%d", &jogadores[i].data.mes);
        printf("Ano nascimento: ");
        scanf("%d", &jogadores[i].data.ano);

        //CPF//
        printf("CPF: ");
        gets(jogadores[i].cpf);

        //Gênero//
        printf("Genero: ");
        fflush(stdin);
        scanf("%u", &jogadores[i].genero);

        //Estado Civil//
        printf("Estado civil: ");
        scanf("%u", &jogadores[i].civil);

        //Equipe//
        printf("Nome Equipe: ");
        fflush(stdin);
        gets(jogadores[i].time.nome_equipe);
        printf("Nickname equipe rede social: ");
        fflush(stdin);
        gets(jogadores[i].time.nickname_equipe);
        printf("Seguidores rede social equipe: ");
        scanf("%d", &jogadores[i].time.seguidores_equipe);

        //Patrocinadora Principal//
        printf("Patrocinadora principal: ");
        fflush(stdin);
        gets(jogadores[i].patrocinadora);

        //Rede Social//
        printf("Rede social: ");
        fflush(stdin);
        gets(jogadores[i].redesocial_jogador.nickname_jogador);

        //Seguidores Rede Social//
        printf("Seguidores rede social: ");
        scanf("%d", &jogadores[i].redesocial_jogador.seguidores_jogador);

        //Equipamento de Hardware//
        printf("Desktop(0) ou Notebook(1)?");
        scanf("%u", &jogadores[i].hardware.computer);
        printf("CPU: ");
        fflush(stdin);
        gets(jogadores[i].hardware.cpu);
        printf("GPU: ");
        fflush(stdin);
        gets(jogadores[i].hardware.gpu);
        printf("Quantidade RAM: ");
        scanf("%d", &jogadores[i].hardware.ram);

        //Dados Campeonato//
        printf("Vitórias: ");
        scanf("%d", &jogadores[i].campeonato.victories);
        printf("Empates: ");
        scanf("%d", &jogadores[i].campeonato.draws);
        printf("Derrotas: ");
        scanf("%d", &jogadores[i].campeonato.losses);
        int vitorias = jogadores[i].campeonato.victories*3;
        int empates = jogadores[i].campeonato.draws*1;
        int derrotas = jogadores[i].campeonato.losses*0;
        int pontos = vitorias+empates+derrotas;
        jogadores[i].campeonato.points=pontos;
        scanf("%d", &jogadores[i].campeonato.points);

        //Títulos mundiais//
        printf("Titulos: ");
        scanf("%d", &jogadores[i].titulos.titles);

        //Ranking//
        printf("Ranking: ");
        scanf("%d", &jogadores[i].ranking.rank);
    }
    return;
}

//Função para Escrever Vetor no Arquivo Binário//

void EscreverJogadoresArquivoBinario(JOGADOR *jogadores, int n){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "wb");
    if(file != NULL){
        fwrite(jogadores, sizeof(JOGADOR), n, file);
    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

//Função ler jogadores arquivo binario//

void LerJogadoresArquivoBinario(JOGADOR *jogadoreslidos, int n){
     FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    if(file != NULL){
        fread(jogadoreslidos, sizeof(JOGADOR), n, file);
    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

//Função alterar dados jogador arquivo binario//

void AlterarDadosJogadorArquivoBinario(int a, int n){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "wb");
    
    if(file != NULL){

        JOGADOR auxiliar[1];

        for(int i=0; i<1; i++){
            //Nome Jogador//
            printf("Nome jogador: ");
            fflush(stdin);
            gets(auxiliar[i].nome);

            //Nascimento//
            printf("Dia nascimento: ");
            scanf("%d", &auxiliar[i].data.dia);
            printf("Mes nascimento: ");
            scanf("%d", &auxiliar[i].data.mes);
            printf("Ano nascimento: ");
            scanf("%d", &auxiliar[i].data.ano);

            //CPF//
            printf("CPF: ");
            gets(auxiliar[i].cpf);

            //Gênero//
            printf("Genero: ");
            scanf("%u", &auxiliar[i].genero);

            //Estado Civil//
            printf("Estado civil: ");
            scanf("%u", &auxiliar[i].civil);

            //Equipe//
            printf("Nome Equipe: ");
            fflush(stdin);
            gets(auxiliar[i].time.nome_equipe);
            printf("Nickname equipe rede social: ");
            fflush(stdin);
            gets(auxiliar[i].time.nickname_equipe);
            printf("Seguidores rede social equipe: ");
            scanf("%d", &auxiliar[i].time.seguidores_equipe);

            //Patrocinadora Principal//
            printf("Patrocinadora principal: ");
            fflush(stdin);
            gets(auxiliar[i].patrocinadora);

            //Rede Social//
            printf("Rede social: ");
            fflush(stdin);
            gets(auxiliar[i].redesocial_jogador.nickname_jogador);

            //Seguidores Rede Social//
            printf("Seguidores rede social: ");
            scanf("%d", &auxiliar[i].redesocial_jogador.seguidores_jogador);

            //Equipamento de Hardware//
            printf("Desktop(0) ou Notebook(1)?");
            scanf("%u", &auxiliar[i].hardware.computer);
            printf("CPU: ");
            fflush(stdin);
            gets(auxiliar[i].hardware.cpu);
            printf("GPU: ");
            fflush(stdin);
            gets(auxiliar[i].hardware.gpu);
            printf("Quantidade RAM: ");
            scanf("%d", &auxiliar[i].hardware.ram);

            //Dados Campeonato//
            printf("Vitórias: ");
            scanf("%d", &auxiliar[i].campeonato.victories);
            printf("Empates: ");
            scanf("%d", &auxiliar[i].campeonato.draws);
            printf("Derrotas: ");
            scanf("%d", &auxiliar[i].campeonato.losses);
            int vitorias = auxiliar[i].campeonato.victories*3;
            int empates = auxiliar[i].campeonato.draws*1;
            int derrotas = auxiliar[i].campeonato.losses*0;
            int pontos = vitorias+empates+derrotas;
            auxiliar[i].campeonato.points=pontos;
            scanf("%d", &auxiliar[i].campeonato.points);

            //Títulos mundiais//
            printf("Titulos: ");
            scanf("%d", &auxiliar[i].titulos.titles);

            //Ranking//
            printf("Ranking: ");
            scanf("%d", &auxiliar[i].ranking.rank);
        }

        fseek(file, a*sizeof(JOGADOR), SEEK_SET);
        fwrite(auxiliar, a*sizeof(JOGADOR), 1, file);
        fclose(file);
    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

//Função atualizar pontuação jogador//

void InserirVitoriaEmpateDerrota(int a, int n){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "wb");
    
    if(file != NULL){

        JOGADOR auxiliar[1];

        for(int i=0; i<1; i++){
            printf("Digite vitorias: ");
            scanf("%d", &auxiliar[i].campeonato.victories);

            printf("Digite empates: ");
            scanf("%d", &auxiliar[i].campeonato.draws);

            printf("Digite derrotas: ");
            scanf("%d", &auxiliar[i].campeonato.losses);
        }

        fseek(file, a*sizeof(JOGADOR), SEEK_SET);
        fwrite(auxiliar, a*sizeof(JOGADOR), 1, file);
        fclose(file);
        
    }
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

//Função buscar jogador por nome//

void BuscarJogadorNome(string100 chave){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

        int i=0;
        while(strcmp(jogadores[i].nome, chave)!=0){
            i++;
        }
        i++;

        //Nascimento//
        printf("Dia: %d", jogadores[i].data.dia);
        printf("Mes: %d", jogadores[i].data.mes);
        printf("Ano: %d", jogadores[i].data.ano);

        //CPF//
        printf("CPF: %d", jogadores[i].cpf);

        //Gênero//
        if(jogadores[i].genero == 0){
            printf("Gênero: Masculino");
        }
        else{
            printf("Gênero: Feminino");
        }
        
        //Estado Civil//
        printf("Estado Civil: %s", jogadores[i].civil);

        //Equipe//
        printf("Nome Equipe: %s", jogadores[i].time.nome_equipe);
        printf("Nickname Equipe Rede Social: %s", jogadores[i].time.nickname_equipe);               
        printf("Seguidores Equipe Rede Social: %d", jogadores[i].time.seguidores_equipe);

        //Patrociadora Principal//
        printf("Patrocinadora Principal: %s", jogadores[i].patrocinadora);

        //Rede Social//
        printf("Rede Social: %s", jogadores[i].redesocial_jogador.nickname_jogador);

        //Seguidors Rede Social//
        printf("Seguidores: %d", jogadores[i].redesocial_jogador.seguidores_jogador);

        //Equipmento de Hardware//
        if(jogadores[i].hardware.computer==0){
            printf("Computador: Desktop");
        }
        else{
            printf("Computador: Laptop");
        }
        printf("CPU: %s", jogadores[i].hardware.cpu);
        printf("GPU: %S", jogadores[i].hardware.gpu);
        printf("RAM: %d", jogadores[i].hardware.ram);

        //Dados Campeonato//
        printf("Vitorias: %d", jogadores[i].campeonato.victories);
        printf("Empates: %d", jogadores[i].campeonato.draws);
        printf("Derrotas: %d", jogadores[i].campeonato.losses);
        printf("Pontos: %d", jogadores[i].campeonato.points);

        //Títulos mundiais//
        printf("Titulos: %d", jogadores[i].titulos.titles);

        //Ranking//
        printf("Rank: %d", jogadores[i].ranking.rank);
        
    }
    return;
}

//Função buscar jogador por rank//

void BuscarJogadorRank(int chave){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

        int i=0;
        while(jogadores[i].ranking.rank != chave){
            i++;
        }
        i++;

        //Nome//
        string100 nome = fread(jogadores[i].nome, sizeof(jogadores[i].nome), 1, file);
        printf("Nome: %s", nome);

         //Nascimento//
        printf("Dia: %d", jogadores[i].data.dia);
        printf("Mes: %d", jogadores[i].data.mes);
        printf("Ano: %d", jogadores[i].data.ano);

        //CPF//
        printf("CPF: %d", jogadores[i].cpf);

        //Gênero//
        if(jogadores[i].genero == 0){
            printf("Gênero: Masculino");
        }
        else{
            printf("Gênero: Feminino");
        }
        
        //Estado Civil//
        printf("Estado Civil: %s", jogadores[i].civil);

        //Equipe//
        printf("Nome Equipe: %s", jogadores[i].time.nome_equipe);
        printf("Nickname Equipe Rede Social: %s", jogadores[i].time.nickname_equipe);               
        printf("Seguidores Equipe Rede Social: %d", jogadores[i].time.seguidores_equipe);

        //Patrociadora Principal//
        printf("Patrocinadora Principal: %s", jogadores[i].patrocinadora);

        //Rede Social//
        printf("Rede Social: %s", jogadores[i].redesocial_jogador.nickname_jogador);

        //Seguidors Rede Social//
        printf("Seguidores: %d", jogadores[i].redesocial_jogador.seguidores_jogador);

        //Equipmento de Hardware//
        if(jogadores[i].hardware.computer==0){
            printf("Computador: Desktop");
        }
        else{
            printf("Computador: Laptop");
        }
        printf("CPU: %s", jogadores[i].hardware.cpu);
        printf("GPU: %S", jogadores[i].hardware.gpu);
        printf("RAM: %d", jogadores[i].hardware.ram);

        //Dados Campeonato//
        printf("Vitorias: %d", jogadores[i].campeonato.victories);
        printf("Empates: %d", jogadores[i].campeonato.draws);
        printf("Derrotas: %d", jogadores[i].campeonato.losses);
        printf("Pontos: %d", jogadores[i].campeonato.points);

        //Títulos mundiais//
        printf("Titulos: %d", jogadores[i].titulos.titles);

    }
    return;
}

//Função mostrar média seguidores jogadores//

void MostrarMediaSeguidoresJogadores(int n){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    fseek(file, 0, SEEK_END);
    int tamanhoArquivo = ftell(file);
    fseek(file, 0, SEEK_SET);
    JOGADOR jogadores[tamanhoArquivo];

    int soma=0;
    for(int i=0; i<n; i++){
        soma = soma+jogadores[i].redesocial_jogador.seguidores_jogador;
    }
    return;
}

//Cria vetor auxiliar para as funções de listar
void CriarVetor_aux(JOGADOR* jogadores, AUX * auxiliar, int n){
    int i;

    for(i = 0; i < n; i++){
        *(auxiliar+i)->nome_aux = *(jogadores+i)->nome;
        *(auxiliar+i)->ranking_aux = *(jogadores+i)->ranking->rank;
        *(auxiliar+i)->vitorias_aux = *(jogadores+i)->campeonato->victories;
        *(auxiliar+i)->pontuacao_aux = *(jogadores+i)->campeonato->points;
        *(auxiliar+i)->derrotas_aux = *(jogadores+i)->campeonato->losses;
        *(auxiliar+i)->empates_aux = *(jogadores+i)->campeonato->draws;

    }
}


//ordena os nomes dos jogadores por ordem alfabética
void OrdenarJogadores_alfabeto( AUX*auxiliares, int n){
    int i, j, conferidor;
    string100 aux;
    
    for(j = 0; j < n; j++){
        for(i = 0; i < n - 1; i++){
            conferidor = strcmp(*(auxiliares+i)->nome_aux, *(auxiliares+i+1)->nome_aux);
            if(conferidor > 0){
                strcpy(aux, *(auxiliares+i)->nome_aux);
                strcpy(*(auxiliares+i)->nome_aux, *(auxiliares+i+1)->nome_aux);
                strcpy(*(auxiliares+i+1)->nome_aux, aux);
            }
        }
    }

    printf("Lista ordenada dos nomes dos jogadores:\n\n");

    for(i = 0; i < n; i++){
        printf("%s\n", *(auxiliares+i)->nome_aux);
    }

    PularLinha(1);

}


//Ordena todos os jogadores de acordo com a posição no campeonato
void OrdenarJogadores_VetorAux(AUX * auxiliar, int n){
    int i, j, conferidor;
    int aux;
    string100 aux2;

    
    for(j = 0; j < n; j++){
        for(i = 0; i < n - 1; i++){
            if(*(auxiliar+i)->ranking_aux > *(auxiliar+i+1)->ranking_aux){
                aux = *(auxiliar+i)->ranking_aux;
                strcpy(aux2, *(auxiliar+1)->nome_aux);
                *(auxiliar+i)->ranking_aux = *(auxiliar+1+i)->ranking_aux;
                strcpy(*(auxiliar+i)->nome_aux, *(auxiliar+i+1)->nome_aux);
                *(auxiliar+i+1)->ranking_aux = aux;
                strcpy(*(auxiliar+i+1)->nome_aux, aux2);

                aux = *(auxiliar+1)->vitorias_aux;
                *(auxiliar+i)->vitorias_aux = *(auxiliar+i+1)->vitorias_aux;
                *(auxiliar+i+1)->vitorias_aux = aux;

                aux = *(auxiliar+1)->derrotas_aux;
                *(auxiliar+i)->derrotas_aux = *(auxiliar+i+1)->derrotas_aux;
                *(auxiliar+i+1)->derrotas_aux = aux;

                aux = *(auxiliar+1)->pontuacao_aux;
                *(auxiliar+i)->pontuacao_aux = *(auxiliar+i+1)->pontuacao_aux;
                *(auxiliar+i+1)->pontuacao_aux = aux;

                aux = *(auxiliar+1)->derrotas_aux;
                *(auxiliar+i)->derrotas_aux = *(auxiliar+i+1)->derrotas_aux;
                *(auxiliar+i+1)->derrotas_aux = aux;

            }
        }
    }

}

//Ordena os posições dos jogadores em ordem crescente
void OrdenarJogadores_posicao( AUX * auxiliar, int n){
    
    OrdenarJogadores_VetorAux(&AUX->ranking_aux, n);
    printf("\nLista ordenada das posições dos jogadores:\n\n");

    for(i = 0; i < n; i++){
        printf("%s, %dª posição!\n", *(auxiliar+i)->ranking_aux, *(auxiliar+i)->ranking_aux);
    }

    PularLinha(1);

}

//Ordena os jogadores em ordem crescente por número de Vitórias
void OrdenarJogadores_vitoria ( AUX * auxiliar, int n){
    int i, j, conferidor;
    int aux;
    string100 aux2;

    
    for(j = 0; j < n; j++){
        for(i = 0; i < n - 1; i++){
            if(*(auxiliar+i)->vitorias_aux < *(auxiliar+i+1)->vitorias_aux){
                aux = *(auxiliar+i)->vitorias_aux;
                strcpy(aux2, *(auxiliar+1)->nome_aux);
                *(auxiliar+i)->vitorias_aux = *(auxiliar+1+i)->vitorias_aux;
                strcpy(*(auxiliar+i)->nome_aux, *(auxiliar+i+1)->nome_aux);
                *(auxiliar+i+1)->vitorias_aux = aux;
                strcpy(*(auxiliar+i+1)->nome_aux, aux2);

            }
        }
    }

    printf("\nLista ordenada das posições dos jogadores:\n\n");

    for(i = 0; i < n; i++){
        printf("%s, %d vitórias!\n", *(auxiliar+i)->vitorias_aux, *(auxiliar+i)->vitorias_aux);
    }

    PularLinha(1);

}

//Mostrar (listar) classificação do campeonato com nome, posição no campeonato, pontuação, quantidade de vitorias, derrotas e empates.
void ListarJogadores_posicaoCampeonato ( AUX * auxiliar, int n, JOGADOR * jogadores){
    OrdenarJogadores_VetorAux(&AUX->ranking_aux, n);

    for(int i = 0; i < n; i++){

        printf("Nome: %s; %dª posição; Pontuação: %d; Vitórias: %d; Derrotas: %d; Empates: %d\n", *(auxiliar+i)->nome_aux, *(auxiliar)->ranking_aux, *(auxiliar)->pontuacao_aux, *(auxiliar)->vitorias_aux, *(auxiliar)->derrotas_aux, *(auxiliar)->empates_aux);
    }
}

//Lista jogadores com pontuação menor que um determinado numero
void ListarJogadores_PontuacaoMenor (AUX * auxiliar, int n, int limite){
    int i;

    printf("Jogadores com pontuação menor que %d:\n", limite);
    for(i = 0; i < n; i++){
        if(*(auxiliar+i)->pontuacao_aux < limite){
            printf("Nome: %s - %d pontos!\n", *(auxiliar+i)->nome_aux, *(auxiliar+i)->pontuacao_aux);
        }
    }
    
}

void ListarJogadores_PontuacaoMaior (AUX * auxiliar, int n, int limite){
    int i;

    printf("Jogadores com pontuação maior que %d:\n", limite);
    for(i = 0; i < n; i++){
        if(*(auxiliar+i)->pontuacao_aux > limite){
            printf("Nome: %s - %d pontos!\n", *(auxiliar+i)->nome_aux, *(auxiliar+i)->pontuacao_aux);
        }
    }
    
}




