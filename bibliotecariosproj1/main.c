#include <stdlib.h>
#include <stdio.h>


int main() {

printf("Olla");


return 0;

}


void inserir_livro(t_livro *p){


    printf("Introduza o título do livro: ");
    fflush(stdin);
    gets(p->titulo);

    printf("\nIntroduza o autor do livro: ");
    fflush(stdin);
    gets(p->.autor);

    do {

        printf("\nIntroduza o ano de publicação do livro: ");
        scanf("%d", p->ano);

    }while(p->ano < 1500 && p-> ano > 2023);


    printf("\nIntroduza a editora do livro: ");
    fflush(stdin);
    gets(p->editora);
}
