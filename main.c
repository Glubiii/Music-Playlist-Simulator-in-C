#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionar_Musica( char titulos[][50], char artistas[][50], int duracoes[], int *total_Musicas);
void remover_Musica( char titulos[][50], char artistas[][50], int duracoes[], int *total_Musicas);
void reproduzir_Musica( char titulos[][50], char artistas[][50], int duracoes[], int *total_Musicas);
void lista_Musicas( char titulos[][50], char artistas[][50], int duracoes[50], int *total_Musicas);

int main()
{
    char titulos[50][50]; 
    char artistas[50][50]; 
    
    int duracoes[50]; 
    int musicas = 0;
    int *total_Musicas;
    
    int menu = -1;
    
    total_Musicas = &musicas;

    system("cls");
    while ( menu != 0)
    { 
        printf("======♪ Reprodutor de musicas ♪======\n");
        printf("Total de musicas: %d\n", *total_Musicas);
        printf("[0] Sair\n[1] Adicionar musica \n[2] Remover musica \n[3] Lista de Musicas \n[4] Reproduzir Musica\n");
        scanf ("%d", &menu);

        switch (menu)
        {
        case 0:
            printf("Até a proxima.\n");
            break;
        case 1:
            adicionar_Musica(titulos, artistas, duracoes, total_Musicas);
            break;
        case 2:
            remover_Musica(titulos, artistas, duracoes, total_Musicas);
            break;
        case 3:
            lista_Musicas(titulos, artistas, duracoes, total_Musicas);
            break;
        case 4:
            reproduzir_Musica(titulos, artistas, duracoes, total_Musicas);
            break;
        default:
            printf("Este Numero Não existe na lista;\n");  
        }
    }
    return 0;
}

void adicionar_Musica( char titulos[][50], char artistas[][50], int duracoes[], int *total_Musicas)
{   
    int stop = -1;

    while( stop != 0)
    {
        system("cls");
        printf("Diga o nome da musica\n");
        scanf (" %49[^\n]", artistas[*total_Musicas]);

        printf("Diga o nome do artista ou banda\n");
        scanf (" %49[^\n]", titulos[*total_Musicas]);

        printf("Digite a duração da musica [em minutos] \n");
        scanf ("%d", &duracoes[*total_Musicas]);

        (*total_Musicas)++;

        printf("Adiciionar outra musicas? \n[0] para sair\n[1] pra adicionar outra \n");
        scanf("%d", &stop);
    }
} 

void remover_Musica( char titulos[][50], char artistas[][50], int duracoes[], int *total_Musicas )
{
    int remove;
    int check = 0;

    system("cls");
    printf ("Digite o numero da musica que deseja remover \n");
    for (int i = 0; i < *total_Musicas; i++) {
        printf("[%d] | %s - %s \n", i, titulos[i], artistas[i]);
    }
    scanf("%d", &remove);

    check = (*total_Musicas)-remove; // *totalMusica - Remove = Limite pra ir subindo as musicas na lista;

    for ( int i = 0; i < *total_Musicas; i++) {
        if( remove == i )
        { 
            (*total_Musicas)--;
            for( int j = remove; j < check; j++) {
                strcpy(artistas[j], artistas[j +1]);
                strcpy(titulos[j], titulos[j +1]);
                duracoes[j] = duracoes[j + 1]; 
            }
        }
    }
}

void reproduzir_Musica( char titulos[][50], char artistas[][50], int duracoes[], int *total_Musicas )
{
    int reproduzir = 0, stop = 1;

    system("cls");
    printf("Digite o numero da musica que deseja reproduzir: \n");
    for ( int i = 0; i < *total_Musicas; i++) {
        printf("[%d] | %s - %s \n", i, titulos[i], artistas[i]);
    }
    scanf("%d", &reproduzir);

    while ( stop != 0)
    {
        system("cls");
        printf("♪♪ ▶-------------------------------------------------- %dm ♪♪\n",duracoes[reproduzir]);
        printf("%s - %s        ◁|  ■ ▶  |▷         ⇄ ↩  \n", titulos[reproduzir], artistas[reproduzir]);
        
        printf("[0] Parar \n");
        scanf("%d", &stop);
    }
}

void lista_Musicas( char titulos[][50], char artistas[][50], int duracoes[50], int *total_Musicas)
{
    int voltar = 1;
    system("cls");
    while ( voltar != 0)
    {
        for ( int i = 0; i < *total_Musicas; i++) {
            printf("[%d] | %s - %s | %dm\n", i, titulos[i], artistas[i], duracoes[i]);
        }
        printf("[0] Voltar \n");
        scanf("%d", &voltar);
    }
} 