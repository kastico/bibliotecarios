#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10
#define MAX_STR 40

typedef struct{
    char titulo[MAX_STR];
    char autor[MAX_STR];
    int ano;
    char editora[MAX_STR];
}t_livro;



void print_livro(t_livro livro){
    printf("Título: %s\tAutor: %s\nEditora: %s\t Ano: %d", livro.titulo, livro.autor, livro.editora, livro.ano);
}

void print_matriz(t_livro livros[], int n){

    for(int i=0;i<n;i++)
        print_livro(livros[i]);
}

void le_ficheiro(FILE *fic,t_livro *livros,int *n){

    int ano;
    char tit[MAX],aut[MAX],edi[MAX];

    while( (fscanf(fic,"%[^#]#%[^#]#%d#%[^#]",tit,aut,&ano,edi))!=EOF )
    {
        strcpy(livros->titulo,tit);
        strcpy(livros->autor,aut);
        livros->ano=ano;
        strcpy(livros->editora,edi);
        n++;
        livros++;
    }
}

void inserir_livro(t_livro *p){


    printf("Introduza o título do livro: ");
    fflush(stdin);
    gets(p->titulo);

    printf("\nIntroduza o autor do livro: ");
    fflush(stdin);
    gets(p->autor);

    do {

        printf("\nIntroduza o ano de publicação do livro: ");
        scanf("%d", &p->ano);

    }while(p->ano < 1500 && p-> ano > 2023);


    printf("\nIntroduza a editora do livro: ");
    fflush(stdin);
    gets(p->editora);
}

FILE *abrir_ficheiro(char tipo[],char url[])
{

    FILE *fic;
    char op='2';

    do
    {
        if (strlen(url)!=0)
        {

            printf("\n1- Manter ficheiro \"%s\"",url);
            printf("\n2- Novo\n");
            while ((op=getchar())!= '1' && op!= '2');
        }
        if(op == '2')
        {
            printf("\nNome do ficheiro: ");
            fflush(stdin);
            gets(url);
        }
        fic = fopen(url,tipo);
        if(fic == NULL)
        {
            system("cls");
            printf("Erro, nao foi possivel abrir o arquivo\n");
            printf("\nTentar novamente? 1- sim 0- nao  ");
            fflush(stdin);
            op=getchar();
            if(op != '1')
                return NULL;
        }
        else
        {
            printf("\n Ficheiro: %s guardado com sucesso",url);
            return fic;
        }
    }
    while (fic==NULL);

}

void escreve_ficheiro(FILE *fic, t_livro *livros,int n)
{

    for (int i=0; i<n; i++)
    {

        fprintf (fic, "%s#%s#%d#%s", livros->titulo, livros->autor, livros->ano, livros->editora);

        livros++;
    }
}


void main ()

{
    int n_livros;
    t_livro livros[MAX];
    int op;
    do{
    system("cls");
    printf("\n*** ** Gestao de livros ** ***\n\n");
    printf("\n1- Lista de livros");
    printf("\n2- Atualizar lista de livros");
    printf("\n3- Sair\n");
    scanf ("%d",&op);
    }while((op=getchar())!= '1' && op != '2' && op != '3');

    switch (op);

        case 3:
        break;

        case 1:
        break;

        case 2:
        break;

    return op;

}
