 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <math.h>
 #include "Funcoes.h"
// #include <locale.h>

//funÃ§Ã£o de pular linha
void PularLinha(int num){
    for(int i = 0; i < num;i++){
        printf("\n");
    }
}

//FunÃ§Ã£o Escrever Jogadores Vetor e no Arquivo Binario//

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
        fflush(stdin);
        //CPF//
        printf("CPF: ");
        gets(jogadores[i].cpf);
        fflush(stdin);
        
        //GÃªnero//
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
        printf("VitÃ³rias: ");
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

        //TÃ­tulos mundiais//
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

//FunÃ§Ã£o ler jogadores arquivo binario//

void LerJogadoresArquivoBinario(){
     FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

        for(int i=0; i<tamanhoArquivo; i++){
        //Nome//
        printf("Nome %d: %s", i+1, jogadores[i].nome);
        //Nascimento//
        printf("Dia %d: %d", i+1, jogadores[i].data.dia);
        printf("Mes %d: %d", i+1, jogadores[i].data.mes);
        printf("Ano %d: %d", i+1, jogadores[i].data.ano);

        //CPF//
        printf("CPF %d: %s", i+1, jogadores[i].cpf);

        //GÃªnero//
        if(jogadores[i].genero == 0){
            printf("GÃªnero %d: Masculino", i+1);
        }
        else{
            printf("GÃªnero %d: Feminino", i+1);
        }
        
        //Estado Civil//
        printf("Estado Civil %d: %d", i+1, jogadores[i].civil);

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
        printf("GPU %d: %s", i+1, jogadores[i].hardware.gpu);
        printf("RAM %d: %d", i+1, jogadores[i].hardware.ram);

        //Dados Campeonato//
        printf("Vitorias %d: %d", i+1, jogadores[i].campeonato.victories);
        printf("Empates %d: %d", i+1, jogadores[i].campeonato.draws);
        printf("Derrotas %d: %d", i+1, jogadores[i].campeonato.losses);
        printf("Pontos %d: %d", i+1, jogadores[i].campeonato.points);

        //TÃ­tulos mundiais//
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

//FunÃ§Ã£o alterar dados jogador arquivo binario//

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

            //GÃªnero//
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
            printf("VitÃ³rias: ");
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

            //TÃ­tulos mundiais//
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

//FunÃ§Ã£o atualizar pontuaÃ§Ã£o jogador//

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

//FunÃ§Ã£o buscar jogador por nome//

void BuscarJogadorNome(string100 chave){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
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
        printf("CPF: %s", jogadores[i].cpf);

        //GÃªnero//
        if(jogadores[i].genero == 0){
            printf("GÃªnero: Masculino");
        }
        else{
            printf("GÃªnero: Feminino");
        }
        
        //Estado Civil//
        printf("Estado Civil: %d", jogadores[i].civil);

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
        printf("GPU: %s", jogadores[i].hardware.gpu);
        printf("RAM: %d", jogadores[i].hardware.ram);

        //Dados Campeonato//
        printf("Vitorias: %d", jogadores[i].campeonato.victories);
        printf("Empates: %d", jogadores[i].campeonato.draws);
        printf("Derrotas: %d", jogadores[i].campeonato.losses);
        printf("Pontos: %d", jogadores[i].campeonato.points);

        //TÃ­tulos mundiais//
        printf("Titulos: %d", jogadores[i].titulos.titles);

        //Ranking//
        printf("Rank: %d", jogadores[i].ranking.rank);
        
    }
    return;
}

//FunÃ§Ã£o buscar jogador por rank//

void BuscarJogadorRank(int chave){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

        int i=0;
        while(jogadores[i].ranking.rank != chave){
            i++;
        }
        i++;

        //Nome//
        printf("Nome: %s", jogadores[i].nome);

         //Nascimento//
        printf("Dia: %d", jogadores[i].data.dia);
        printf("Mes: %d", jogadores[i].data.mes);
        printf("Ano: %d", jogadores[i].data.ano);

        //CPF//
        printf("CPF: %s", jogadores[i].cpf);

        //GÃªnero//
        if(jogadores[i].genero == 0){
            printf("GÃªnero: Masculino");
        }
        else{
            printf("GÃªnero: Feminino");
        }
        
        //Estado Civil//
        printf("Estado Civil: %d", jogadores[i].civil);

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
        printf("GPU: %s", jogadores[i].hardware.gpu);
        printf("RAM: %d", jogadores[i].hardware.ram);

        //Dados Campeonato//
        printf("Vitorias: %d", jogadores[i].campeonato.victories);
        printf("Empates: %d", jogadores[i].campeonato.draws);
        printf("Derrotas: %d", jogadores[i].campeonato.losses);
        printf("Pontos: %d", jogadores[i].campeonato.points);

        //TÃ­tulos mundiais//
        printf("Titulos: %d", jogadores[i].titulos.titles);

    }
    return;
}

//FunÃ§Ã£o mostrar mÃ©dia seguidores jogadores//

void MostrarMediaSeguidoresJogadores(int n){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    fseek(file, 0, SEEK_END);
    int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
    fseek(file, 0, SEEK_SET);
    JOGADOR jogadores[tamanhoArquivo];
    fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

    int soma=0, media=0;

    for(int i=0; i<n; i++){
        soma = soma+jogadores[i].redesocial_jogador.seguidores_jogador;
    }
    media = soma/tamanhoArquivo;
    return;
}

//Lê os conteúdos do arquivo para o vetor
void LerArquivo_Vetor(JOGADOR jogadores[], int n){
    FILE * file;
    file = fopen("TrabalhoPratico.dat", "rb");
    fseek(file, 0, SEEK_END);
    int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
    fseek(file, 0, SEEK_SET);
    fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);
}


//ordena os nomes dos jogadores por ordem alfabÃÂ©tica
void OrdenarJogadores_alfabeto( JOGADOR auxiliares[], int n){
    int conferidor, i, j;
    JOGADOR aux;
    for(j = 0; j < n; j++){
        for(i = 0; i < n - 1; i++){
            conferidor = strcasecmp(auxiliares[i].nome , auxiliares[i+1].nome);
            if(conferidor > 0){
                aux = auxiliares[i];
                auxiliares[i] = auxiliares[i+1];
                auxiliares[i+1] = aux;
            }
        }
    }

    printf("Lista ordenada dos nomes dos jogadores:\n\n");

    for(i = 0; i < n; i++){
        printf("%s\n", auxiliares[i].nome);
    }

    PularLinha(1);

}




//Ordena os posiÃÂ§ÃÂµes dos jogadores em ordem crescente
void OrdenarJogadores_posicao(JOGADOR auxiliar[], int n){
    JOGADOR aux;
    int i, j;

    for(j = 0; j < n; j++){
        for(i = 0; i < n - 1; i++){
            if(auxiliar[i].ranking.rank > auxiliar[i+1].ranking.rank){
                aux = auxiliar[i]; 
                auxiliar[i] = auxiliar[i+1];
                auxiliar[i+1] = aux;
            }
        }
    }
    

    printf("\nLista ordenada das posições dos jogadores:\n\n");

    for(i = 0; i < n; i++){
        printf("%s, %dª posição!\n", auxiliar[i].nome, auxiliar[i].ranking.rank);
    }

    PularLinha(1);

}

//Ordena os jogadores em ordem crescente por nÃÂºmero de VitÃÂ³rias
void OrdenarJogadores_vitoria ( JOGADOR jogadores[], int n){
    int i, j;
    string100 aux2;

    JOGADOR aux;

    
    for(j = 0; j < n; j++){
        for(i = 0; i < n - 1; i++){
            if(jogadores[i].campeonato.victories < jogadores[i+1].campeonato.victories){
                aux = jogadores[i];
                jogadores[i] = jogadores[i+1];
                jogadores[i+1] = aux;
            }
        }
    }

    printf("\nLista ordenada das posição dos jogadores:\n\n");

    for(i = 0; i < n; i++){
        printf("%s, %d vitÃÂ³rias!\n", jogadores[i].nome, jogadores[i].campeonato.victories);
    }

    PularLinha(1);

}

//Mostrar (listar) classificaÃÂ§ÃÂ£o do campeonato com nome, posiÃÂ§ÃÂ£o no campeonato, pontuaÃÂ§ÃÂ£o, quantidade de vitorias, derrotas e empates.
void ListarJogadores_posicaoCampeonato (JOGADOR auxiliar[], int n){

    for(int i = 0; i < n; i++){
        printf("Nome: %s; %dª posição; Pontuação: %d; Vitórias: %d; Derrotas: %d; Empates: %d\n", auxiliar[i].nome, auxiliar[i].ranking.rank, auxiliar[i].campeonato.points, auxiliar[i].campeonato.victories, auxiliar[i].campeonato.losses, auxiliar[i].campeonato.draws);
    }
}

//Lista jogadores com pontuaÃÂ§ÃÂ£o menor que um determinado numero
void ListarJogadores_PontuacaoMenor (JOGADOR auxiliar[],int n, int limite){
    int i;

    printf("Jogadores com pontuação menor que %d:\n", limite);
    for(i = 0; i < n; i++){
        if(auxiliar[i].campeonato.points < limite){
            printf("Nome: %s - %d pontos!\n", auxiliar[i].nome, auxiliar[i].campeonato.points);
        }
    }
    
}

void ListarJogadores_PontuacaoMaior (JOGADOR auxiliar[], int n, int limite){
    int i;
    printf("Jogadores com pontuação maior que %d:\n", limite);
    for(i = 0; i < n; i++){
        if(auxiliar[i].campeonato.points > limite){
            printf("Nome: %s - %d pontos!\n", auxiliar[i].nome, auxiliar[i].campeonato.points);
        }
    }
    
}








