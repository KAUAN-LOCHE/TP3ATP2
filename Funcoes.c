 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <math.h>
 #include "Funcoes.h"
// #include <locale.h>

//função de pular linha
void PularLinha(int num){
    for(int i = 0; i < num;i++){
        printf("\n");
    }
}

//Função Escrever Jogadores Vetor e no Arquivo Binario//

void EscreverJogadoresArquivoBinario(int n){
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
        
        //Gênero//
        printf("Genero (Masculino=0/Feminino=1):");
        scanf("%u", &jogadores[i].genero);
        if(jogadores[i].genero!=0 && jogadores[i].genero!=1){
            printf("Invalido! Digite novamente: Genero (Masculino=0/Feminino=1):");
            scanf("%u", &jogadores[i].genero);
        }
        else{}

        //Estado Civil//
        printf("Estado civil (Casado=0/Solteiro=1/Divorciado=2/Viuvo=3):");
        scanf("%u", &jogadores[i].civil);
        if(jogadores[i].civil!=0 && jogadores[i].civil!=1 && jogadores[i].civil!=2 && jogadores[i].civil!=3){
            printf("Invalido! Digite novamente: Estado civil (Casado=0/Solteiro=1/Divorciado=2/Viuvo=3):");
            scanf("%u", &jogadores[i].civil);
        }
        else{}

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
        printf("Desktop(0) ou Notebook(1)? ");
        scanf("%u", &jogadores[i].hardware.computer);
        if(jogadores[i].hardware.computer!=0 && jogadores[i].hardware.computer!=1){
            printf("Invalido! Digite novamente: Desktop(0) ou Notebook(1)?");
            scanf("%u", &jogadores[i].hardware.computer);
        }
        else{}
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

        //Títulos mundiais//
        printf("Titulos: ");
        scanf("%d", &jogadores[i].titulos.titles);

        //Ranking//
        printf("Ranking: ");
        scanf("%d", &jogadores[i].ranking.rank);
    }
    //Escrever Vetor no Arquivo Binario//
        FILE *file;
        file = fopen("TrabalhoPratico.dat", "wb");
        if(file != NULL){
            for(int i=0; i<n; i++){
                fwrite(&jogadores[i], sizeof(JOGADOR), 1, file);
            }
            fclose(file);
        }
        
        else{
            printf("Arquivo populado!");
        }
    return;
}

//Função ler jogadores arquivo binario//

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
        printf("Nome %d: %s\n", i+1, jogadores[i].nome);
        //Nascimento//
        printf("Dia %d: %d \n", i+1, jogadores[i].data.dia);
        printf("Mes %d: %d \n", i+1, jogadores[i].data.mes);
        printf("Ano %d: %d \n", i+1, jogadores[i].data.ano);

        //CPF//
        printf("CPF %d: %s \n", i+1, jogadores[i].cpf);

        //Gênero//
        if(jogadores[i].genero == 0){
            printf("Gênero %d: Masculino \n", i+1);
        }
        else{
            printf("Gênero %d: Feminino \n", i+1);
        }
        
        //Estado Civil//
        if(jogadores[i].civil == 0){
            printf("Estado Civil %d: Casado \n", i+1);
        }
        if(jogadores[i].civil == 1){
            printf("Estado Civil %d: Solteiro \n", i+1);
        }
        if(jogadores[i].civil == 2){
            printf("Estado Civil %d: Divorciado \n", i+1);
        }
        if(jogadores[i].civil == 3){
            printf("Estado Civil %d: Viuvo \n", i+1);
        }
        

        //Equipe//
        printf("Nome Equipe %d: %s \n", i+1, jogadores[i].time.nome_equipe);
        printf("Nickname Equipe Rede Social %d: %s \n", i+1, jogadores[i].time.nickname_equipe);               
        printf("Seguidores Equipe Rede Social %d: %d \n", i+1, jogadores[i].time.seguidores_equipe);

        //Patrociadora Principal//
        printf("Patrocinadora Principal %d: %s \n", i+1, jogadores[i].patrocinadora);

        //Rede Social//
        printf("Rede Social %d: %s \n", i+1, jogadores[i].redesocial_jogador.nickname_jogador);

        //Seguidors Rede Social//
        printf("Seguidores %d: %d \n", i+1, jogadores[i].redesocial_jogador.seguidores_jogador);

        //Equipmento de Hardware//
        if(jogadores[i].hardware.computer==0){
            printf("Computador %d: Desktop \n", i+1);
        }
        else{
            printf("Computador %d: Laptop \n", i+1);
        }
        printf("CPU %d: %s \n", i+1, jogadores[i].hardware.cpu);
        printf("GPU %d: %s \n", i+1, jogadores[i].hardware.gpu);
        printf("RAM %d: %d \n", i+1, jogadores[i].hardware.ram);

        //Dados Campeonato//
        printf("Vitorias %d: %d \n", i+1, jogadores[i].campeonato.victories);
        printf("Empates %d: %d \n", i+1, jogadores[i].campeonato.draws);
        printf("Derrotas %d: %d \n", i+1, jogadores[i].campeonato.losses);
        printf("Pontos %d: %d \n", i+1, jogadores[i].campeonato.points);

        //Títulos mundiais//
        printf("Titulos %d: %d \n", i+1, jogadores[i].titulos.titles);

        //Ranking//
        printf("Rank %d: %d \n", i+1, jogadores[i].ranking.rank);
        }

    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

//Função alterar dados jogador arquivo binario//

void AlterarDadosJogadorArquivoBinario(int a){
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
            fflush(stdin);

            //CPF//
            printf("CPF: ");
            gets(auxiliar[i].cpf);
            fflush(stdin);
            
            //Gênero//
            printf("Genero (Masculino=0/Feminino=1): ");
            scanf("%u", &auxiliar[i].genero);
            if(auxiliar[i].genero!=0 && auxiliar[i].genero!=1){
                printf("Invalido! Digite novamente: Genero (Masculino=0/Feminino=1):");
                scanf("%u", &auxiliar[i].genero);
            }
            else{}

            //Estado Civil//
            printf("Estado civil (Casado=0/Solteiro=1/Divorciado=2/Viuvo=3): ");
            scanf("%u", &auxiliar[i].civil);
            if(auxiliar[i].civil!=0 && auxiliar[i].civil!=1 && auxiliar[i].civil!=2 && auxiliar[i].civil!=3){
                printf("Invalido! Digite novamente: Estado civil (Casado=0/Solteiro=1/Divorciado=2/Viuvo=3):");
                scanf("%u", &auxiliar[i].civil);
            }
            else{}

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
            printf("Desktop(0) ou Notebook(1)? ");
            scanf("%u", &auxiliar[i].hardware.computer);
            if(auxiliar[i].hardware.computer!=0 && auxiliar[i].hardware.computer!=1){
                printf("Invalido! Digite novamente: Desktop(0) ou Notebook(1)?");
                scanf("%u", &auxiliar[i].hardware.computer);
            }
            else{}
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

            //Títulos mundiais//
            printf("Titulos: ");
            scanf("%d", &auxiliar[i].titulos.titles);

            //Ranking//
            printf("Ranking: ");
            scanf("%d", &auxiliar[i].ranking.rank);
        }

        fseek(file, a-1*sizeof(JOGADOR), SEEK_SET);
        fwrite(auxiliar, sizeof(JOGADOR), 1, file);
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

        fseek(file, a-1*sizeof(JOGADOR), SEEK_SET);
        fwrite(auxiliar, sizeof(JOGADOR), 1, file);
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
        int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
        fseek(file, 0, SEEK_SET);
        JOGADOR jogadores[tamanhoArquivo];
        fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

        int i=0;
        while(strcmp(jogadores[i].nome, chave)!=0){
            i++;
        }

        //Nascimento//
        printf("Dia: %d\n", jogadores[i].data.dia);
        printf("Mes: %d\n", jogadores[i].data.mes);
        printf("Ano: %d\n", jogadores[i].data.ano);

        //CPF//
        printf("CPF: %s\n", jogadores[i].cpf);

        //Gênero//
        if(jogadores[i].genero == 0){
            printf("Gênero: Masculino\n");
        }
        else{
            printf("Gênero: Feminino\n");
        }
        
        //Estado Civil//
        printf("Estado Civil: %d\n", jogadores[i].civil);

        //Equipe//
        printf("Nome Equipe: %s\n", jogadores[i].time.nome_equipe);
        printf("Nickname Equipe Rede Social: %s\n", jogadores[i].time.nickname_equipe);               
        printf("Seguidores Equipe Rede Social: %d\n", jogadores[i].time.seguidores_equipe);

        //Patrociadora Principal//
        printf("Patrocinadora Principal: %s\n", jogadores[i].patrocinadora);

        //Rede Social//
        printf("Rede Social: %s\n", jogadores[i].redesocial_jogador.nickname_jogador);

        //Seguidors Rede Social//
        printf("Seguidores: %d\n", jogadores[i].redesocial_jogador.seguidores_jogador);

        //Equipmento de Hardware//
        if(jogadores[i].hardware.computer==0){
            printf("Computador: Desktop\n");
        }
        else{
            printf("Computador: Laptop\n");
        }
        printf("CPU: %s\n", jogadores[i].hardware.cpu);
        printf("GPU: %s\n", jogadores[i].hardware.gpu);
        printf("RAM: %d\n", jogadores[i].hardware.ram);

        //Dados Campeonato//
        printf("Vitorias: %d\n", jogadores[i].campeonato.victories);
        printf("Empates: %d\n", jogadores[i].campeonato.draws);
        printf("Derrotas: %d\n", jogadores[i].campeonato.losses);
        printf("Pontos: %d\n", jogadores[i].campeonato.points);

        //Títulos mundiais//
        printf("Titulos: %d\n", jogadores[i].titulos.titles);

        //Ranking//
        printf("Rank: %d\n", jogadores[i].ranking.rank);
        
    }
    return;
}

//Função buscar jogador por rank//

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

        //Nome//
        printf("Nome: %s\n", jogadores[i].nome);

         //Nascimento//
        printf("Dia: %d\n", jogadores[i].data.dia);
        printf("Mes: %d\n", jogadores[i].data.mes);
        printf("Ano: %d\n", jogadores[i].data.ano);

        //CPF//
        printf("CPF: %s\n", jogadores[i].cpf);

        //Gênero//
        if(jogadores[i].genero == 0){
            printf("Gênero: Masculino\n");
        }
        else{
            printf("Gênero: Feminino\n");
        }
        
        //Estado Civil//
        printf("Estado Civil: %d\n", jogadores[i].civil);

        //Equipe//
        printf("Nome Equipe: %s\n", jogadores[i].time.nome_equipe);
        printf("Nickname Equipe Rede Social: %s\n", jogadores[i].time.nickname_equipe);               
        printf("Seguidores Equipe Rede Social: %d\n", jogadores[i].time.seguidores_equipe);

        //Patrociadora Principal//
        printf("Patrocinadora Principal: %s\n", jogadores[i].patrocinadora);

        //Rede Social//
        printf("Rede Social: %s\n", jogadores[i].redesocial_jogador.nickname_jogador);

        //Seguidors Rede Social//
        printf("Seguidores: %d\n", jogadores[i].redesocial_jogador.seguidores_jogador);

        //Equipmento de Hardware//
        if(jogadores[i].hardware.computer==0){
            printf("Computador: Desktop\n");
        }
        else{
            printf("Computador: Laptop\n");
        }
        printf("CPU: %s\n", jogadores[i].hardware.cpu);
        printf("GPU: %s\n", jogadores[i].hardware.gpu);
        printf("RAM: %d\n", jogadores[i].hardware.ram);

        //Dados Campeonato//
        printf("Vitorias: %d\n", jogadores[i].campeonato.victories);
        printf("Empates: %d\n", jogadores[i].campeonato.draws);
        printf("Derrotas: %d\n", jogadores[i].campeonato.losses);
        printf("Pontos: %d\n", jogadores[i].campeonato.points);

        //Títulos mundiais//
        printf("Titulos: %d\n", jogadores[i].titulos.titles);

    }
    return;
}

//Função mostrar média seguidores jogadores//

void MostrarMediaSeguidoresJogadores(int n){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    fseek(file, 0, SEEK_END);
    int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
    fseek(file, 0, SEEK_SET);
    JOGADOR jogadores[tamanhoArquivo];
    fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);

    int soma=0;

    for(int i=0; i<n; i++){
        soma = soma+jogadores[i].redesocial_jogador.seguidores_jogador;
    }
    float media = soma/tamanhoArquivo;
    printf("Media: %f\n", media);
    return;
}

//L� os conte�dos do arquivo para o vetor
void LerArquivo_Vetor(JOGADOR jogadores[]){
    FILE * file;
    file = fopen("TrabalhoPratico.dat", "rb");
    fseek(file, 0, SEEK_END);
    int tamanhoArquivo = ftell(file)/sizeof(JOGADOR);
    fseek(file, 0, SEEK_SET);
    fread(jogadores, sizeof(JOGADOR), tamanhoArquivo, file);
}


//ordena os nomes dos jogadores por ordem alfabÃ©tica
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




//Ordena os posiÃ§Ãµes dos jogadores em ordem crescente
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
    

    printf("\nLista ordenada das posi��es dos jogadores:\n\n");

    for(i = 0; i < n; i++){
        printf("%s, %d� posi��o!\n", auxiliar[i].nome, auxiliar[i].ranking.rank);
    }

    PularLinha(1);

}

//Ordena os jogadores em ordem crescente por nÃºmero de VitÃ³rias
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

    printf("\nLista ordenada das posi��o dos jogadores:\n\n");

    for(i = 0; i < n; i++){
        printf("%s, %d vitÃ³rias!\n", jogadores[i].nome, jogadores[i].campeonato.victories);
    }

    PularLinha(1);

}

//Mostrar (listar) classificaÃ§Ã£o do campeonato com nome, posiÃ§Ã£o no campeonato, pontuaÃ§Ã£o, quantidade de vitorias, derrotas e empates.
void ListarJogadores_posicaoCampeonato (JOGADOR auxiliar[], int n){

    for(int i = 0; i < n; i++){
        printf("Nome: %s; %d� posi��o; Pontua��o: %d; Vit�rias: %d; Derrotas: %d; Empates: %d\n", auxiliar[i].nome, auxiliar[i].ranking.rank, auxiliar[i].campeonato.points, auxiliar[i].campeonato.victories, auxiliar[i].campeonato.losses, auxiliar[i].campeonato.draws);
    }
}

//Lista jogadores com pontuaÃ§Ã£o menor que um determinado numero
void ListarJogadores_PontuacaoMenor (JOGADOR auxiliar[],int n, int limite){
    int i;

    printf("Jogadores com pontua��o menor que %d:\n", limite);
    for(i = 0; i < n; i++){
        if(auxiliar[i].campeonato.points < limite){
            printf("Nome: %s - %d pontos!\n", auxiliar[i].nome, auxiliar[i].campeonato.points);
        }
    }
    
}

void ListarJogadores_PontuacaoMaior (JOGADOR auxiliar[], int n, int limite){
    int i;
    printf("Jogadores com pontua��o maior que %d:\n", limite);
    for(i = 0; i < n; i++){
        if(auxiliar[i].campeonato.points > limite){
            printf("Nome: %s - %d pontos!\n", auxiliar[i].nome, auxiliar[i].campeonato.points);
        }
    }
    
}








