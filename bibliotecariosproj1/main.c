#include <stdlib.h>
#include <stdio.h>
#define MAX 30

<<<<<<< HEAD
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

int main() {
int n_livros;
t_livro livros[MAX];

=======
FILE *abrir_ficheiro(char tipo[],char url[])
{

    FILE *fic;
    char op='2';
>>>>>>> c86aaffa9f010205fee53643620b5c8cba2f22cc

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


void le_ficheiro(FILE *fic,t_livro *livros,int *n){

    int ano;
    char tit[MAX],aut[MAX],edi[MAX];

    while( (fscanf(fic,"%[^#]#%[^#]#%d#%[^#]",titulo,autor,&ano,editora))!=EOF )
    {
        strcpy(livros->titulo,tit);
        strcpy(livros->autor,aut);
        livros->ano=ano;
        strcpy(livros->editora,edi);
        n++;
        livros++;
    }
}
