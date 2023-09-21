#include <stdlib.h>
#include <stdio.h>

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


printf("Olla");


return 0;

}
