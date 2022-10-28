/*
 ============================================================================
 Name        : Laboratorio7.c
 Author      : Ramon Chacal
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

char **creaMatriz(int filas,int columnas);
void llenarMatriz(int filas,int columnas, char **matriz);
void imprimirMatriz(int filas,int columnas, char **matriz);

int main()
{
    int filas,columnas;
    char **matriz;
    scanf("%d",&filas);
    scanf("%d",&columnas);
    matriz = creaMatriz(filas,columnas);
    llenarMatriz(filas,columnas,matriz);
    imprimirMatriz(filas,columnas,matriz);





    return 0;
}

char **creaMatriz(int filas,int columnas){
    char ** pmat;
    // crear el vector de punteros filas
    pmat = malloc(filas*sizeof(char*));
    if(!pmat) return NULL;


    for(int i = 0 ;i < filas;i++){
        pmat[i] = malloc(columnas * sizeof(char));
        if (pmat[i] == NULL){
            for(;i >= 0; i--) free(pmat[i]);
            free(pmat);
            return NULL;
        }
    }
    return pmat;
}


void llenarMatriz(int filas,int columnas, char **matriz){

    for (int i = 0; i < filas; i++){
        for(int j = 0; j< columnas; j++){
            printf("\nIngrese [%d][%d]: ",i,j);
            scanf("%c",&matriz[i][j]);
        }
    }

}

void imprimirMatriz(int filas,int columnas, char **matriz){

    for (int i = 0; i < filas; i++){
        for(int j = 0; j< columnas; j++){
            printf("%c   ",matriz[i][j]);
        }
        printf("\n");
    }

}
