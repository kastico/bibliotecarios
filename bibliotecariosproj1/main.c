
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX 10
#define MAX_STR 40
#define ANO_ACTUAL 2023

typedef struct{
    char titulo[MAX_STR];
    char autor[MAX_STR];
    int ano;
    char editora[MAX_STR];
}t_livro;



void print_livro(t_livro livro){
    printf("\n\nTítulo: %s\tAutor: %s\nEditora: %s\tAno: %d", livro.titulo, livro.autor, livro.editora, livro.ano);
}

void print_matriz(t_livro livros[], int n){


    for(int i=0;i<n;i++)
    {
        print_livro(livros[i]);
    }

}

void le_ficheiro(FILE *fic,t_livro *livros,int *n){

    int an;
    char tit[MAX_STR],aut[MAX_STR],edi[MAX_STR];

    while( (fscanf(fic,"%[^#]#%[^#]#%d#%s\n",tit,aut,&an,edi))!=EOF )
    {
        strcpy(livros->titulo,tit);
        strcpy(livros->autor,aut);
        livros->ano=an;
        strcpy(livros->editora,edi);
        (*n)++;
        livros++;
    }
}

void inserir_livro(t_livro *p, int *n){


    printf("Introduza o título do livro: ");
    fflush(stdin);
    gets(p->titulo);

    printf("\nIntroduza o autor do livro: ");
    fflush(stdin);
    gets(p->autor);

    do {

        printf("\nIntroduza o ano de publicação do livro: ");
        scanf("%d", &p->ano);

    }while(p->ano < 1500 || p-> ano > ANO_ACTUAL);


    printf("\nIntroduza a editora do livro: ");
    fflush(stdin);
    gets(p->editora);
    (*n)++;
}

FILE *abrir_ficheiro(char tipo)
{
    FILE *fic;

    fic = fopen("livros.txt",&tipo);
    return fic;

}

void escreve_ficheiro( t_livro livros[],int n)
{
    FILE *fic;
    fic = fopen("livros.txt","w");
    printf("FILE:  %s ",fic);
    for (int i=0; i<n; i++)
    {
        fprintf(fic, "%s#%s#%d#%s\n", livros[i].titulo, livros[i].autor, livros[i].ano, livros[i].editora);
    }
    fclose(fic);
}

int main ()

{
    setlocale(LC_ALL,"PORTUGUESE");
    int n_livros;
    t_livro livros[MAX];
    FILE *fic;
    int op;
    fic=abrir_ficheiro('r');
    le_ficheiro(fic, livros, &n_livros);
    fclose(fic);


    do{
   // system("cls");
    printf("\n*** ** Gestao de livros ** ***\n\n");
    printf("\n1- Lista de livros");
    printf("\n2- Inserir novo livro");
    printf("\n3- Sair\n");
    do
    {
        scanf ("%d",&op);
    }while(op>3 || op<1);

    switch (op)
        {
            case 3:
                escreve_ficheiro( livros, n_livros);
                break;
            case 1:
                print_matriz(livros, n_livros);
            break;
            case 2:
                inserir_livro(&livros[n_livros], &n_livros);
            break;
        }
    }while(op!=3);



return 0;
}
