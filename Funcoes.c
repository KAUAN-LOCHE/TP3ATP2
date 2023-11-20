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

void EscreverJogadoresVetor(JOGADOR *jogadores, int n){
    for(int i=0; i<n; i++){
        //Nome Jogador//
        printf("Nome jogador: ");
        fflush(stdin);
        gets(*(jogadores+i)->nome);

        //Nascimento//
        printf("Dia nascimento: ");
        scanf("%d", &*(jogadores+i)->data->dia);
        printf("Mes nascimento: ");
        scanf("%d", &*(jogadores+i)->data->mes);
        printf("Ano nascimento: ");
        scanf("%d", &*(jogadores+i)->data->ano);

        //CPF//
        printf("CPF: ");
        scanf("%u", &*(jogadores+i)->CPF->cpf);

        //Gênero//
        printf("Genero: ");
        fflush(stdin);
        gets(*(jogadores+i)->genero->gender);

        //Estado Civil//
        printf("Estado civil: ");
        scanf("%d", &*(jogadores+i)->estadocivil->civil_state);

        //Equipe//
        printf("Nome Equipe: ");
        fflush(stdin);
        gets(*(jogadores+i)->equipe->nome_equipe);
        printf("Nickname equipe rede social: ");
        fflush(stdin);
        gets(*(jogadores+i)->equipe->nickname_equipe);
        printf("Seguidores rede social equipe: ");
        scanf("%d", &*(jogadores+i)->equipe->seguidores_equipe);

        //Patrocinadora Principal//
        printf("Patrocinadora principal: ");
        fflush(stdin);
        gets(*(jogadores+i)->patrocinadora->sponsor);

        //Rede Social//
        printf("Rede social: ");
        fflush(stdin);
        gets(*(jogadores+i)->redesocial->social_network);

        //Seguidores Rede Social//
        printf("Seguidores rede social: ");
        scanf("%d", &*(jogadores+i)->seguidores->followers);

        //Equipamento de Hardware//
        printf("Desktop(0) ou Notebook(1)?");
        scanf("%d", &*(jogadores+i)->hardware->computer);
        printf("CPU: ");
        fflush(stdin);
        gets(*(jogadores+i)->hardware->cpu);
        printf("GPU: ");
        fflush(stdin);
        gets(*(jogadores+i)->hardware->gpu);
        printf("Quantidade RAM: ");
        scanf("%d", &*(jogadores+i)->hardware->ram);

        //Dados Campeonato//
        printf("Vitórias: ");
        scanf("%d", &*(jogadores+i)->campeonato->victories);
        printf("Empates: ");
        scanf("%d", &*(jogadores+i)->campeonato->draws);
        printf("Derrotas: ");
        scanf("%d", &*(jogadores+i)->campeonato->losses);
        int vitorias = *(jogadores+i)->campeonato->victories*3;
        int empates = *(jogadores+i)->campeonato->draws*1;
        int derrotas = *(jogadores+i)->campeonato->losses*0;
        int pontos = vitorias+empates+derrotas;
        *(jogadores+i)->campeonato->points=pontos;
        scanf("%d", &*(jogadores+i)->campeonato->points);

        //Títulos mundiais//
        printf("Titulos: ");
        scanf("%d", &*(jogadores+i)->titulos->titles);

        //Ranking//
        printf("Ranking: ");
        scanf("%d", &*(jogadores+i)->ranking->rank);
    }
    return;
}

//Função para Escrever Vetor no Arquivo Binário//

void EscreverJogadoresArquivoBinario(JOGADOR *jogadores, int n){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "wb");
    if(file != NULL){
        for(int i=0; i<n; i++){
            //Nome Jogador//
            fwrite(*(jogadores+i)->nome, sizeof(*(jogadores+i)->nome), 1, file);

            //Nascimento//
            fwrite(*(jogadores+i)->data->dia, sizeof(*(jogadores+i)->data->dia), 1, file);
            fwrite(*(jogadores+i)->data->mes, sizeof(*(jogadores+i)->data->mes), 1, file);
            fwrite(*(jogadores+i)->data->ano, sizeof(*(jogadores+i)->data->ano), 1, file);

            //CPF//
            fwrite(*(jogadores+i)->CPF->cpf, sizeof(*(jogadores+i)->CPF->cpf), 1, file);

            //Gênero//
            fwrite(*(jogadores+i)->genero->gender, sizeof(*(jogadores+i)->genero->gender), 1, file);

            //Estado Civil//
            fwrite(*(jogadores+i)->estadocivil->civil_state, sizeof(*(jogadores+i)->estadocivil->civil_state), 1, file);

            //Equipe//
            fwrite(*(jogadores+i)->equipe->nome_equipe, sizeof(*(jogadores+i)->equipe->nome_equipe), 1, file);
            fwrite(*(jogadores+i)->equipe->nickname_equipe, sizeof(*(jogadores+i)->equipe->nickname_equipe), 1 ,file);                
            fwrite(*(jogadores+i)->equipe->seguidores_equipe, sizeof(*(jogadores+i)->equipe->seguidores_equipe), 1, file);

            //Patrociadora Principal//
            fwrite(*(jogadores+i)->patrocinadora->sponsor, sizeof(*(jogadores+i)->patrocinadora->sponsor), 1, file);

            //Rede Socil//
            fwrite(*(jogadores+i)->redesocial->social_network, sizeof(*(jogadores+i)->redesocial->social_network), 1, file);

            //Seguidors Rede Social//
            fwrite(*(jogadores+i)->seguidores->followers, sizeof(*(jogadores+i)->seguidores->followers), 1, file);

            //Equipmento de Hardware//
            if(*(jogadores+i)->hardware->computr==0){
                fwrite("Desktop", sizeof(*(jogadores+i)->hardware->computer), 1, file);
            }
            else{
            fwrite("Laptop", sizeof(*(jogadores+i)->hardware->computer), 1, file);
            }
            fwrite(*(jogadores+i)->hardware->cpu, sizeof(*(jogadores+i)->hardware->cpu), 1, file);
            fwrite(*(jogadores+i)->hardware->gpu, sizeof(*(jogadores+i)->hardware->gpu), 1, file);
            fwrite(*(jogadores+i)->hardware->ram, sizeof(*(jogadores+i)->hardware->ram), 1, file);

            //Dados Campeonato//
            fwrite(*(jogadores+i)->campeonato->victories, sizeof(*(jogadores+i)->campeonato->victories), 1, file);
            fwrite(*(jogadores+i)->campeonato->draws, sizeof(*(jogadores+i)->campeonato->draws), 1, file);
            fwrite(*(jogadores+i)->campeonato->losses, sizeof(*(jogadores+i)->campeonato->losses), 1, file);
            fwrite(*(jogadores+i)->campeonato->points, sizeof(*(jogadores+i)->campeonato->losses), 1, file);

            //Títulos Mundiais//
            fwrite(*(jogadores+i)->titulos->titles, sizeof(*(jogadores+i)->titulos->titles), 1, file);

            //Ranking//
            fwrite(*(jogadores+i)->ranking->rank, sizeof(*(jogadores+i)->ranking->rank), 1, file);
        }
    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

//Função ler jogadores arquivo binario//

void LerJogadoresArquivoBinario(JOGADOR *jogadoreslidos, int n){
     FILE *file;
    file = fopen("TrabalhoPratico.dat", "wb");
    if(file != NULL){
        for(int i=0; i<n; i++){
            //Nome Jogador//
            fread(*(jogadoreslidos+i)->nome, sizeof(*(jogadoreslidos+i)->nome), 1, file);

            //Nascimento//
            fread(*(jogadoreslidos+i)->data->dia, sizeof(*(jogadoreslidos+i)->data->dia), 1, file);
            fread(*(jogadoreslidos+i)->data->mes, sizeof(*(jogadoreslidos+i)->data->mes), 1, file);
            fread(*(jogadoreslidos+i)->data->ano, sizeof(*(jogadoreslidos+i)->data->ano), 1, file);

            //CPF//
            fread(*(jogadoreslidos+i)->CPF->cpf, sizeof(*(jogadoreslidos+i)->CPF->cpf), 1, file);

            //Gênero//
            fread(*(jogadoreslidos+i)->genero->gender, sizeof(*(jogadoreslidos+i)->genero->gender), 1, file);

            //Estado Civil//
            fread(*(jogadoreslidos+i)->estadocivil->civil_state, sizeof(*(jogadoreslidos+i)->estadocivil->civil_state), 1, file);

            //Equipe//
            fread(*(jogadoreslidos+i)->equipe->nome_equipe, sizeof(*(jogadoreslidos+i)->equipe->nome_equipe), 1, file);
            fread(*(jogadoreslidos+i)->equipe->nickname_equipe, sizeof(*(jogadoreslidos+i)->equipe->nickname_equipe), 1 ,file);                
            fread(*(jogadoreslidos+i)->equipe->seguidores_equipe, sizeof(*(jogadoreslidos+i)->equipe->seguidores_equipe), 1, file);

            //Patrociadora Principal//
            fread(*(jogadoreslidos+i)->patrocinadora->sponsor, sizeof(*(jogadoreslidos+i)->patrocinadora->sponsor), 1, file);

            //Rede Socil//
            fread(*(jogadoreslidos+i)->redesocial->social_network, sizeof(*(jogadoreslidos+i)->redesocial->social_network), 1, file);

            //Seguidors Rede Social//
            fread(*(jogadoreslidos+i)->seguidores->followers, sizeof(*(jogadoreslidos+i)->seguidores->followers), 1, file);

            //Equipmento de Hardware//
            if(*(jogadoreslidos+i)->hardware->computr==0){
                fread("Desktop", sizeof(*(jogadoreslidos+i)->hardware->computer), 1, file);
            }
            else{
            fread("Laptop", sizeof(*(jogadoreslidos+i)->hardware->computer), 1, file);
            }
            fread(*(jogadoreslidos+i)->hardware->cpu, sizeof(*(jogadoreslidos+i)->hardware->cpu), 1, file);
            fread(*(jogadoreslidos+i)->hardware->gpu, sizeof(*(jogadoreslidos+i)->hardware->gpu), 1, file);
            fread(*(jogadoreslidos+i)->hardware->ram, sizeof(*(jogadoreslidos+i)->hardware->ram), 1, file);

            //Dados Campeonato//
            fread(*(jogadoreslidos+i)->campeonato->victories, sizeof(*(jogadoreslidos+i)->campeonato->victories), 1, file);
            fread(*(jogadoreslidos+i)->campeonato->draws, sizeof(*(jogadoreslidos+i)->campeonato->draws), 1, file);
            fread(*(jogadoreslidos+i)->campeonato->losses, sizeof(*(jogadoreslidos+i)->campeonato->losses), 1, file);
            fread(*(jogadoreslidos+i)->campeonato->points, sizeof(*(jogadoreslidos+i)->campeonato->losses), 1, file);

            //Títulos mundiais//
            fread(*(jogadoreslidos+i)->titulos->titles, sizeof(*(jogadoreslidos+i)->titulos->titles), 1, file);

            //Ranking//
            fread(*(jogadoreslidos+i)->ranking->rank, sizeof(*(jogadoreslidos+i)->ranking->rank), 1, file);
        }
    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

//Função alterar dados jogador arquivo binario//

void AlterarDadosJogadorArquivoBinario(JOGADOR *jogadores, int a){
        FILE *file;
    file = fopen("TrabalhoPratico.dat", "wb");
    if(file != NULL){
        int i;
        for(i=0; i!=a; i++){
        }
        i++;
        //Nome Jogador//
            fwrite(*(jogadores+i)->nome, sizeof(*(jogadores+i)->nome), 1, file);

            //Nascimento//
            fwrite(*(jogadores+i)->data->dia, sizeof(*(jogadores+i)->data->dia), 1, file);
            fwrite(*(jogadores+i)->data->mes, sizeof(*(jogadores+i)->data->mes), 1, file);
            fwrite(*(jogadores+i)->data->ano, sizeof(*(jogadores+i)->data->ano), 1, file);

            //CPF//
            fwrite(*(jogadores+i)->CPF->cpf, sizeof(*(jogadores+i)->CPF->cpf), 1, file);

            //Gênero//
            fwrite(*(jogadores+i)->genero->gender, sizeof(*(jogadores+i)->genero->gender), 1, file);

            //Estado Civil//
            fwrite(*(jogadores+i)->estadocivil->civil_state, sizeof(*(jogadores+i)->estadocivil->civil_state), 1, file);

            //Equipe//
            fwrite(*(jogadores+i)->equipe->nome_equipe, sizeof(*(jogadores+i)->equipe->nome_equipe), 1, file);
            fwrite(*(jogadores+i)->equipe->nickname_equipe, sizeof(*(jogadores+i)->equipe->nickname_equipe), 1 ,file);                
            fwrite(*(jogadores+i)->equipe->seguidores_equipe, sizeof(*(jogadores+i)->equipe->seguidores_equipe), 1, file);

            //Patrociadora Principal//
            fwrite(*(jogadores+i)->patrocinadora->sponsor, sizeof(*(jogadores+i)->patrocinadora->sponsor), 1, file);

            //Rede Socil//
            fwrite(*(jogadores+i)->redesocial->social_network, sizeof(*(jogadores+i)->redesocial->social_network), 1, file);

            //Seguidors Rede Social//
            fwrite(*(jogadores+i)->seguidores->followers, sizeof(*(jogadores+i)->seguidores->followers), 1, file);

            //Equipmento de Hardware//
            if(*(jogadores+i)->hardware->computr==0){
                fwrite("Desktop", sizeof(*(jogadores+i)->hardware->computer), 1, file);
            }
            else{
            fwrite("Laptop", sizeof(*(jogadores+i)->hardware->computer), 1, file);
            }
            fwrite(*(jogadores+i)->hardware->cpu, sizeof(*(jogadores+i)->hardware->cpu), 1, file);
            fwrite(*(jogadores+i)->hardware->gpu, sizeof(*(jogadores+i)->hardware->gpu), 1, file);
            fwrite(*(jogadores+i)->hardware->ram, sizeof(*(jogadores+i)->hardware->ram), 1, file);

            //Dados Campeonato//
            fwrite(*(jogadores+i)->campeonato->victories, sizeof(*(jogadores+i)->campeonato->victories), 1, file);
            fwrite(*(jogadores+i)->campeonato->draws, sizeof(*(jogadores+i)->campeonato->draws), 1, file);
            fwrite(*(jogadores+i)->campeonato->losses, sizeof(*(jogadores+i)->campeonato->losses), 1, file);
            fwrite(*(jogadores+i)->campeonato->points, sizeof(*(jogadores+i)->campeonato->losses), 1, file);

            //Títulos mundiais//
            fwrite(*(jogadores+i)->titulos->titles, sizeof(*(jogadores+i)->titulos->titles), 1, file);

            //Ranking//
            fwrite(*(jogadores+i)->ranking->rank, sizeof(*(jogadores+i)->ranking->rank), 1, file);
    }
    
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

//Função atualizar pontuação jogador//

void InserirVitoriaEmpateDerrota(JOGADOR *jogadores, int a){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "wb");
    if(file != NULL){
        int i;
        for(i=0; i<=a; i++){
        }
        i++;
        //Dados Campeonato//
            fwrite(*(jogadores+i)->campeonato->victories, sizeof(*(jogadores+i)->campeonato->victories), 1, file);
            fwrite(*(jogadores+i)->campeonato->draws, sizeof(*(jogadores+i)->campeonato->draws), 1, file);
            fwrite(*(jogadores+i)->campeonato->losses, sizeof(*(jogadores+i)->campeonato->losses), 1, file);
            fwrite(*(jogadores+i)->campeonato->points, sizeof(*(jogadores+i)->campeonato->losses), 1, file);
    }
    else{
        printf("Arquivo nao aberto!");
    }
    return;
}

//Função buscar jogador por nome//

void BuscarJogadorNome(JOGADOR *jogadores, string100 chave){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    if(file != NULL){
        int i=0;
        while(strcmp(fread(*(jogadores+i)->nome, sizeof(*(jogadores+i)->nome), 1, file), chave)!=0){
            i++;
        }
        i++;
        //Nascimento//
        int dia = fread(*(jogadores+i)->data->dia, sizeof(*(jogadores+i)->data->dia), 1, file);
        printf("Dia: %d", dia);
        int mes = fread(*(jogadores+i)->data->mes, sizeof(*(jogadores+i)->data->mes), 1, file);
        printf("Mes: %d", mes);
        int ano = fread(*(jogadores+i)->data->ano, sizeof(*(jogadores+i)->data->ano), 1, file);
        printf("Ano: %d", ano);

        //CPF//
        int cpf = fread(*(jogadores+i)->CPF->cpf, sizeof(*(jogadores+i)->CPF->cpf), 1, file);
        printf("CPF: %d", cpf);

        //Gênero//
        string100 genero = fread(*(jogadores+i)->genero->gender, sizeof(*(jogadores+i)->genero->gender), 1, file);
        printf("Genero: %s", genero);

        //Estado Civil//
        string100 estadocivil = fread(*(jogadores+i)->estadocivil->civil_state, sizeof(*(jogadores+i)->estadocivil->civil_state), 1, file);
        printf("Estado Civil: %s", estadocivil);

        //Equipe//
        string100 nome_equipe = fread(*(jogadores+i)->equipe->nome_equipe, sizeof(*(jogadores+i)->equipe->nome_equipe), 1, file);
        printf("Nome Equipe: %s", nome_equipe);
        string100 nickname_equipe = fread(*(jogadores+i)->equipe->nickname_equipe, sizeof(*(jogadores+i)->equipe->nickname_equipe), 1 ,file); 
        printf("Nickname Equipe Rede Social: %s", nickname_equipe);               
        int seguidores_equipe = fread(*(jogadores+i)->equipe->seguidores_equipe, sizeof(*(jogadores+i)->equipe->seguidores_equipe), 1, file);
        printf("Seguidores Equipe Rede Social: %d", seguidores_equipe);

        //Patrociadora Principal//
        string100 patrocinadora_principal = fread(*(jogadores+i)->patrocinadora->sponsor, sizeof(*(jogadores+i)->patrocinadora->sponsor), 1, file);
        printf("Patrocinadora Principal: %s", patrocinadora_principal);

        //Rede Socil//
        string100 rede_social = fread(*(jogadores+i)->redesocial->social_network, sizeof(*(jogadores+i)->redesocial->social_network), 1, file);
        printf("Rede Social: %s", rede_social);

        //Seguidors Rede Social//
        int seguidores = fread(*(jogadores+i)->seguidores->followers, sizeof(*(jogadores+i)->seguidores->followers), 1, file);
        printf("Seguidores: %d", seguidores);

        //Equipmento de Hardware//
        if(*(jogadores+i)->hardware->computer==0){
            string100 desktop = fread("Desktop", sizeof(*(jogadores+i)->hardware->computer), 1, file);
            printf("Computador: %s", desktop);
        }
        else{
            string100 laptop = fread("Laptop", sizeof(*(jogadores+i)->hardware->computer), 1, file);
            printf("Computador: %s", laptop);
        }
        string100 cpu = fread(*(jogadores+i)->hardware->cpu, sizeof(*(jogadores+i)->hardware->cpu), 1, file);
        printf("CPU: %s", cpu);
        string100 gpu = fread(*(jogadores+i)->hardware->gpu, sizeof(*(jogadores+i)->hardware->gpu), 1, file);
        printf("GPU: %S", gpu);
        int ram = fread(*(jogadores+i)->hardware->ram, sizeof(*(jogadores+i)->hardware->ram), 1, file);
        printf("RAM: %d", ram);

        //Dados Campeonato//
        int vitorias = fread(*(jogadores+i)->campeonato->victories, sizeof(*(jogadores+i)->campeonato->victories), 1, file);
        printf("Vitorias: %d", vitorias);
        int empates = fread(*(jogadores+i)->campeonato->draws, sizeof(*(jogadores+i)->campeonato->draws), 1, file);
        printf("Empates: %d", empates);
        int derrotas = fread(*(jogadores+i)->campeonato->losses, sizeof(*(jogadores+i)->campeonato->losses), 1, file);
        printf("Derrotas: %d", derrotas);
        int pontos = fread(*(jogadores+i)->campeonato->points, sizeof(*(jogadores+i)->campeonato->losses), 1, file);
        printf("Pontos: %d", pontos);

        //Títulos mundiais//
        int titulos = fread(*(jogadores+i)->titulos->titles, sizeof(*(jogadores+i)->titulos->titles), 1, file);
        printf("Titulos: %d", titulos);

        //Ranking//
        int rank = fread(*(jogadores+i)->ranking->rank, sizeof(*(jogadores+i)->ranking->rank), 1, file);
        printf("Rank: %d");
    }
    return;
}

//Função buscar jogador por rank//

void BuscarJogadorRank(JOGADOR *jogadores, int chave){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    if(file != NULL){
        int i=0;
        while(fread(*(jogadores+i)->ranking->rank, sizeof(*(jogadores+i)->ranking->rank), 1, file)!=chave){
            i++;
        }
        i++;

        //Nome//
        string100 nome = fread(*(jogadores+i)->nome, sizeof(*(jogadores+i)->nome), 1, file);
        printf("Nome: %s", nome);

        //Nascimento//
        int dia = fread(*(jogadores+i)->data->dia, sizeof(*(jogadores+i)->data->dia), 1, file);
        printf("Dia: %d", dia);
        int mes = fread(*(jogadores+i)->data->mes, sizeof(*(jogadores+i)->data->mes), 1, file);
        printf("Mes: %d", mes);
        int ano = fread(*(jogadores+i)->data->ano, sizeof(*(jogadores+i)->data->ano), 1, file);
        printf("Ano: %d", ano);

        //CPF//
        int cpf = fread(*(jogadores+i)->CPF->cpf, sizeof(*(jogadores+i)->CPF->cpf), 1, file);
        printf("CPF: %d", cpf);

        //Gênero//
        string100 genero = fread(*(jogadores+i)->genero->gender, sizeof(*(jogadores+i)->genero->gender), 1, file);
        printf("Genero: %s", genero);

        //Estado Civil//
        string100 estadocivil = fread(*(jogadores+i)->estadocivil->civil_state, sizeof(*(jogadores+i)->estadocivil->civil_state), 1, file);
        printf("Estado Civil: %s", estadocivil);

        //Equipe//
        string100 nome_equipe = fread(*(jogadores+i)->equipe->nome_equipe, sizeof(*(jogadores+i)->equipe->nome_equipe), 1, file);
        printf("Nome Equipe: %s", nome_equipe);
        string100 nickname_equipe = fread(*(jogadores+i)->equipe->nickname_equipe, sizeof(*(jogadores+i)->equipe->nickname_equipe), 1 ,file); 
        printf("Nickname Equipe Rede Social: %s", nickname_equipe);               
        int seguidores_equipe = fread(*(jogadores+i)->equipe->seguidores_equipe, sizeof(*(jogadores+i)->equipe->seguidores_equipe), 1, file);
        printf("Seguidores Equipe Rede Social: %d", seguidores_equipe);

        //Patrociadora Principal//
        string100 patrocinadora_principal = fread(*(jogadores+i)->patrocinadora->sponsor, sizeof(*(jogadores+i)->patrocinadora->sponsor), 1, file);
        printf("Patrocinadora Principal: %s", patrocinadora_principal);

        //Rede Socil//
        string100 rede_social = fread(*(jogadores+i)->redesocial->social_network, sizeof(*(jogadores+i)->redesocial->social_network), 1, file);
        printf("Rede Social: %s", rede_social);

        //Seguidors Rede Social//
        int seguidores = fread(*(jogadores+i)->seguidores->followers, sizeof(*(jogadores+i)->seguidores->followers), 1, file);
        printf("Seguidores: %d", seguidores);

        //Equipmento de Hardware//
        if(*(jogadores+i)->hardware->computer==0){
            string100 desktop = fread("Desktop", sizeof(*(jogadores+i)->hardware->computer), 1, file);
            printf("Computador: %s", desktop);
        }
        else{
            string100 laptop = fread("Laptop", sizeof(*(jogadores+i)->hardware->computer), 1, file);
            printf("Computador: %s", laptop);
        }
        string100 cpu = fread(*(jogadores+i)->hardware->cpu, sizeof(*(jogadores+i)->hardware->cpu), 1, file);
        printf("CPU: %s", cpu);
        string100 gpu = fread(*(jogadores+i)->hardware->gpu, sizeof(*(jogadores+i)->hardware->gpu), 1, file);
        printf("GPU: %S", gpu);
        int ram = fread(*(jogadores+i)->hardware->ram, sizeof(*(jogadores+i)->hardware->ram), 1, file);
        printf("RAM: %d", ram);

        //Dados Campeonato//
        int vitorias = fread(*(jogadores+i)->campeonato->victories, sizeof(*(jogadores+i)->campeonato->victories), 1, file);
        printf("Vitorias: %d", vitorias);
        int empates = fread(*(jogadores+i)->campeonato->draws, sizeof(*(jogadores+i)->campeonato->draws), 1, file);
        printf("Empates: %d", empates);
        int derrotas = fread(*(jogadores+i)->campeonato->losses, sizeof(*(jogadores+i)->campeonato->losses), 1, file);
        printf("Derrotas: %d", derrotas);
        int pontos = fread(*(jogadores+i)->campeonato->points, sizeof(*(jogadores+i)->campeonato->losses), 1, file);
        printf("Pontos: %d", pontos);

        //Títulos mundiais//
        int titulos = fread(*(jogadores+i)->titulos->titles, sizeof(*(jogadores+i)->titulos->titles), 1, file);
        printf("Titulos: %d", titulos);

    }
    return;
}

//Função mostrar média seguidores jogadores//

void MostrarMediaSeguidoresJogadores(JOGADOR *jogadores, int n){
    FILE *file;
    file = fopen("TrabalhoPratico.dat", "rb");
    int soma=0;
    for(int i=0; i<n; i++){
        int seguidores = fread(*(jogadores+i)->seguidores->followers, sizeof(*(jogadores+i)->seguidores->followers), 1, file);
        soma = soma+seguidores;
    }
    return;
}

//Cria vetor auxiliar para as funções de listar
void CriarVetor_aux(JOGADOR* jogadores, AUX * auxiliar, int n){
    int i;

    for(i = 0; i < n; i++){
        *(auxiliar+i)->nome = *(jogadores+i)->nome;
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
            conferidor = strcmp(*(auxiliares+i)->nome, *(auxiliares+i+1)->nome);
            if(conferidor > 0){
                strcpy(aux, *(auxiliares+i)->nome);
                strcpy(*(auxiliares+i)->nome, *(auxiliares+i+1)->nome);
                strcpy(*(auxiliares+i+1)->nome, aux);
            }
        }
    }

    printf("Lista ordenada dos nomes dos jogadores:\n\n");

    for(i = 0; i < n; i++){
        printf("%s\n", *(auxiliares+i)->nome);
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
void OrdenarJogadores_posicao( AUX * auxiliar, int n,){
    
    OrdenarJogadores_VetorAux(&AUX->ranking_aux, n);
    printf("\nLista ordenada das posições dos jogadores:\n\n");

    for(i = 0; i < n; i++){
        printf("%s, %dª posição!\n", *(auxiliar+i)->ranking_aux, *(auxiliar+i)->ranking_aux);
    }

    PularLinha(1);

}

//Ordena os jogadores em ordem crescente por número de Vitórias
void OrdenarJogadores_vitoria ( AUX * auxiliar, int n,){
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




