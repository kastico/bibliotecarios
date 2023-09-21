#include <stdlib.h>
#include <stdio.h>

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


int main() {

printf("Olla");


return 0;

}
