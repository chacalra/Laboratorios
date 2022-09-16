/*
 ============================================================================
 Name        : Lab4.c
 Author      : Ramon Chacal
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <string.h>

int isStr(char* buscar, char* dondeBuscar);

int main()
{
    char cadena[20], subcadena[20];
    printf("Ingresa la cadena: ");
    scanf("%s",cadena);
    printf("Ingresa la Subcadena: ");
    scanf("%s",subcadena);
    printf("%d",isStr(subcadena,cadena));


    return 0;
}

int isStr(char* buscar, char* dondeBuscar){
    int count = 0;
    int posicion;
    char * temp = dondeBuscar;
    char * temp2 = buscar;

    while (*dondeBuscar != '\0'){
        if(*dondeBuscar == *buscar){
            count ++;
            buscar ++;

        }
        dondeBuscar ++;
    }
    printf("count %d long_buscar %d\n",count,strlen(temp2));
    if (count == strlen(temp2)){
        return buscar - temp  ;
    }
    return -1;

}
