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

//Função Escrever Jogadores Vetor e no Arquivo Binario//

void EscreverJogadoresVetor(int n){
    JOGADOR jogadores[n];
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

        //Escrever Vetor no Arquivo Binario//

        FILE *file;
        file = fopen("TrabalhoPratico.dat", "wb");
        if(file != NULL){
            JOGADOR jogadores[n];
            fwrite(jogadores, sizeof(JOGADOR), n, file);
        }
        
        else{
            printf("Arquivo nao aberto!");
        }
    }
    return;
}

//Função ler jogadores arquivo binario//

void LerJogadoresArquivoBinario(){
     FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

        for(int i=0; i<tamanhoArquivo; i++){
        //Nome//
        printf("Nome %d: %d", i+1, jogadores[i].nome);
        //Nascimento//
        printf("Dia %d: %d", i+1, jogadores[i].data.dia);
        printf("Mes %d: %d", i+1, jogadores[i].data.mes);
        printf("Ano %d: %d", i+1, jogadores[i].data.ano);

        //CPF//
        printf("CPF %d: %d", i+1, jogadores[i].cpf);

        //Gênero//
        if(jogadores[i].genero == 0){
            printf("Gênero %d: Masculino", i+1);
        }
        else{
            printf("Gênero %d: Feminino", i+1);
        }
        
        //Estado Civil//
        printf("Estado Civil %d: %s", i+1, jogadores[i].civil);

        //Equipe//
        printf("Nome Equipe %d: %s", i+1, jogadores[i].time.nome_equipe);
        printf("Nickname Equipe Rede Social %d: %s", i+1, jogadores[i].time.nickname_equipe);               
        printf("Seguidores Equipe Rede Social %d: %d", i+1, jogadores[i].time.seguidores_equipe);

        //Patrociadora Principal//
        printf("Patrocinadora Principal %d: %s", i+1, jogadores[i].patrocinadora);

        //Rede Social//
        printf("Rede Social %d: %s", i+1, jogadores[i].redesocial_jogador.nickname_jogador);

        //Seguidors Rede Social//
        printf("Seguidores %d: %d", i+1, jogadores[i].redesocial_jogador.seguidores_jogador);

        //Equipmento de Hardware//
        if(jogadores[i].hardware.computer==0){
            printf("Computador %d: Desktop", i+1);
        }
        else{
            printf("Computador %d: Laptop", i+1);
        }
        printf("CPU %d: %s", i+1, jogadores[i].hardware.cpu);
        printf("GPU %d: %S", i+1, jogadores[i].hardware.gpu);
        printf("RAM %d: %d", i+1, jogadores[i].hardware.ram);

        //Dados Campeonato//
        printf("Vitorias %d: %d", i+1, jogadores[i].campeonato.victories);
        printf("Empates %d: %d", i+1, jogadores[i].campeonato.draws);
        printf("Derrotas %d: %d", i+1, jogadores[i].campeonato.losses);
        printf("Pontos %d: %d", i+1, jogadores[i].campeonato.points);

        //Títulos mundiais//
        printf("Titulos %d: %d", i+1, jogadores[i].titulos.titles);

        //Ranking//
        printf("Rank %d: %d", i+1, jogadores[i].ranking.rank);
        }

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

void InserirVitoriaEmpateDerrota(int a){
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

    int soma=0, media=0;

    for(int i=0; i<n; i++){
        soma = soma+jogadores[i].redesocial_jogador.seguidores_jogador;
    }
    media = soma/tamanhoArquivo;
    return;
}

//Cria vetor auxiliar para as funÃ§Ãµes de listar
void CriarVetor_aux(JOGADOR jogadores, AUX auxiliar, int n){
    int i;
    
    for(i = 0; i < n; i++){
       strcpy(auxiliar[i].nome_aux, jogadores[i].nome);
       auxiliar[i].ranking_aux = jogadores[i].ranking.rank;
       auxiliar[i].vitorias_aux = jogadores[i].campeonato.victories;
       auxiliar[i].pontuacao_aux = jogadores[i].campeonato.points;
       auxiliar[i].derrotas_aux = jogadores[i].campeonato.losses;
       auxiliar[i].empates_aux = jogadores[i].campeonato.draws;

    }
}


//ordena os nomes dos jogadores por ordem alfabÃ©tica
void OrdenarJogadores_alfabeto(  int n){
    int i, j, conferidor;
    string100 aux;
    AUX auxiliares[n];
    for(j = 0; j < n; j++){
        for(i = 0; i < n - 1; i++){
            conferidor = strcmp(auxiliares[i].nome_aux, auxiliares[i+1].nome_aux);
            if(conferidor > 0){
                strcpy(aux,auxiliares[i].nome_aux);
                strcpy(auxiliares[i].nome_aux, auxiliares[i+1].nome_aux);
                strcpy(auxiliares[i+1].nome_aux, aux);
            }
        }
    }

    printf("Lista ordenada dos nomes dos jogadores:\n\n");

    for(i = 0; i < n; i++){
        printf("%s\n", auxiliares[i].nome_aux);
    }

    PularLinha(1);

}


//Ordena todos os jogadores de acordo com a posiÃ§Ã£o no campeonato
void OrdenarJogadores_VetorAux( int n){
    int i, j;
    int aux;
    string100 aux2;

    AUX auxiliar[n];

    
    for(j = 0; j < n; j++){
        for(i = 0; i < n - 1; i++){
            if(auxiliar[i].ranking_aux > auxiliar[i+1].ranking_aux){
                aux = auxiliar[i].ranking_aux;
                strcpy(aux2, auxiliar[i].nome_aux);
                auxiliar[i].ranking_aux = auxiliar[i+1].ranking_aux;
                strcpy(auxiliar[i].nome_aux, auxiliar[i+1].nome_aux);
                auxiliar[i+1].ranking_aux = aux;
                strcpy(auxiliar[i+1].nome_aux, aux2);

                aux = auxiliar[i].vitorias_aux;
                auxiliar[i].vitorias_aux = auxiliar[i+1].vitorias_aux;
                auxiliar[i+1].vitorias_aux = aux;

                aux = auxiliar[i].derrotas_aux;
                auxiliar[i].derrotas_aux = auxiliar[i+1].derrotas_aux;
                auxiliar[i+1].derrotas_aux = aux;

                aux = auxiliar[i].pontuacao_aux;
                auxiliar[i].pontuacao_aux = auxiliar[i+1].pontuacao_aux;
                auxiliar[i+1].pontuacao_aux = aux;

                aux = auxiliar[i].derrotas_aux;
                auxiliar[i].derrotas_aux = auxiliar[i+1].derrotas_aux;
                auxiliar[i+1].derrotas_aux = aux;

            }
        }
    }

}

//Ordena os posiÃ§Ãµes dos jogadores em ordem crescente
void OrdenarJogadores_posicao( int n){
    int i;
    AUX auxiliar[n];
    OrdenarJogadores_VetorAux( n);
    printf("\nLista ordenada das posiÃ§Ãµes dos jogadores:\n\n");

    for(i = 0; i < n; i++){
        printf("%s, %dÂª posiÃ§Ã£o!\n", auxiliar[i].nome_aux, auxiliar[i].ranking_aux);
    }

    PularLinha(1);

}

//Ordena os jogadores em ordem crescente por nÃºmero de VitÃ³rias
void OrdenarJogadores_vitoria ( int n){
    int i, j;
    int aux;
    string100 aux2;

    AUX auxiliar[n];

    
    for(j = 0; j < n; j++){
        for(i = 0; i < n - 1; i++){
            if(auxiliar[i].vitorias_aux < auxiliar[i+1].vitorias_aux){
                aux = auxiliar[i].vitorias_aux;
                strcpy(aux2, auxiliar[i].nome_aux);
                auxiliar[i].vitorias_aux = auxiliar[i+1].vitorias_aux;
                strcpy(auxiliar[i].nome_aux,auxiliar[i+1].nome_aux);
                auxiliar[i+1].vitorias_aux = aux;
                strcpy(auxiliar[i+1].nome_aux, aux2);

            }
        }
    }

    printf("\nLista ordenada das posiÃ§Ãµes dos jogadores:\n\n");

    for(i = 0; i < n; i++){
        printf("%s, %d vitÃ³rias!\n", auxiliar[i].nome_aux, auxiliar[i].vitorias_aux);
    }

    PularLinha(1);

}

//Mostrar (listar) classificaÃ§Ã£o do campeonato com nome, posiÃ§Ã£o no campeonato, pontuaÃ§Ã£o, quantidade de vitorias, derrotas e empates.
void ListarJogadores_posicaoCampeonato (  int n){
    AUX auxiliar[n];
    OrdenarJogadores_VetorAux( n);

    for(int i = 0; i < n; i++){

        printf("Nome: %s; %dÂª posiÃ§Ã£o; PontuaÃ§Ã£o: %d; VitÃ³rias: %d; Derrotas: %d; Empates: %d\n", auxiliar[i].nome_aux, auxiliar[i].ranking_aux, auxiliar[i].pontuacao_aux, auxiliar[i].vitorias_aux, auxiliar[i].derrotas_aux, auxiliar[i].empates_aux);
    }
}

//Lista jogadores com pontuaÃ§Ã£o menor que um determinado numero
void ListarJogadores_PontuacaoMenor (int n, int limite){
    int i;

    AUX auxiliar[n];
    printf("Jogadores com pontuaÃ§Ã£o menor que %d:\n", limite);
    for(i = 0; i < n; i++){
        if(auxiliar[i].pontuacao_aux < limite){
            printf("Nome: %s - %d pontos!\n", auxiliar[i].nome_aux, auxiliar[i].pontuacao_aux);
        }
    }
    
}

void ListarJogadores_PontuacaoMaior (int n, int limite){
    int i;
    AUX auxiliar[n];
    printf("Jogadores com pontuaÃ§Ã£o maior que %d:\n", limite);
    for(i = 0; i < n; i++){
        if(auxiliar[i].pontuacao_aux > limite){
            printf("Nome: %s - %d pontos!\n", auxiliar[i].nome_aux, auxiliar[i].pontuacao_aux);
        }
    }
    
}








