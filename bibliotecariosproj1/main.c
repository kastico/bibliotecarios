#include <stdlib.h>
#include <stdio.h>
#define MAX 30


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
