
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
int primo(int numero);
void concat();

int main()
{
    char maincadena[51];
    char auxiliar[3];
    int contador=0;
    int p;
    printf("Ingrese valores a la cadena de caracteres: ");
    fgets(maincadena, sizeof(maincadena), stdin);
    int final = strlen(maincadena)-2;
    concat(maincadena,auxiliar,final,p);
}

void concat(char maincadena[],char auxiliar[],int final,int p){
    for(int i=0 ; (i<final+1) ; i++){
        if(final==i){
            auxiliar[0]=maincadena[i];
            auxiliar[1]='\0';
        }else{
            auxiliar[0]=maincadena[i];
            auxiliar[1]=maincadena[final];
            auxiliar[2]='\0';
        }

        final--;
        int p = atoi(auxiliar);
        primo(p);
    }

}

int primo(int numero){
    int x = 1, c = 0;
    while (x <= numero){
        if (numero % x == 0){
            c = c +1;
        }
        x = x +1 ;
    }
    if (c == 2){
        printf("\nel numero %d es primo ",numero);
        return TRUE;

    }
    printf("\nel numero %d no es primo ",numero);
    return FALSE;

}
