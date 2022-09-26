/*
 ============================================================================
 Name        : lab5.c
 Author      : Ramon Chacal
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void conversion(char *cadenaleida,int *vectorNumeros);
void conversionOperadores(char *cadenaleida,char *operadores);
int procesamiento(int *numeros,char *operadores);
void separar(char *cadenaleida,int *vectorNumeros);
void conversionOperadores2(char *cadenaleida,char *operadores);
void reversaArrays(int arr[], int n);
void reverseCadena(char *operadores);

int main(void) {

	char cadenaleida[100];
	int vectorNumeros[100];
	char operadores[100];
	int resultado,modo;
	char c;

	printf("Bienvenido a la calculadora basica!\n");
	printf("1.- Original\n");
	printf("2.- Inversa\n");
	printf("3.- Precedencia\n");
	printf("Selecciona modo:");
	scanf("%d", &modo);
	switch(modo){
		case 1 :
			printf("Ingrese valores\nLos valores válidos son [0-9,+,-,*,/]:");
			scanf("%[0-9,+,-,*,/]s", cadenaleida);
			conversion(cadenaleida,vectorNumeros);
			conversionOperadores(cadenaleida,operadores);
			resultado = procesamiento(vectorNumeros,operadores);
			printf("\nel resultado es %d",resultado);
			break;


		case 2:
			printf("Ingrese valores\nLos valores válidos son [0-9,+,-,*,/]:");
			scanf("%[0-9,+,-,*,/]s", cadenaleida);
			conversion(cadenaleida,vectorNumeros);
			conversionOperadores(cadenaleida,operadores);
			int n = sizeof(vectorNumeros)/sizeof(vectorNumeros[0]); // longitud
			reversaArrays(vectorNumeros, n);
			reverseCadena(operadores);
			resultado = procesamiento(vectorNumeros,operadores);
			printf("\nel resultado es %d",resultado);
			break;


		case 3:

			printf("Ingrese valores\nLos valores válidos son [0-9,+,-,*,/]:");
			while((c = getchar()) != '\n' && c != EOF);
			scanf("%[0-9,+,-,*,/]s", cadenaleida);
			separar(cadenaleida,vectorNumeros);
			conversionOperadores2(cadenaleida,operadores);
			resultado = procesamiento(vectorNumeros,operadores);
			printf("\nel resultado es %d",resultado);
			break;
		default:
			printf("Error de modo");
			break;
	}

	return 0;
}

void conversion(char *cadenaleida,int *vectorNumeros){

	char *ptr = cadenaleida;
	char aux[100];
	int i = 0;
	int *punteroNumeros = vectorNumeros;

	for(;*ptr != '\0';ptr++){
		if(*ptr >= 48 && *ptr <= 57){
			aux[i] = *ptr;
			i++;
		}else{
			*punteroNumeros = atoi(aux);
			punteroNumeros++;
			memset(aux,'\0',10);
			i = 0; //resetear i
		}
	}
	*punteroNumeros = atoi(aux);
}


void conversionOperadores(char *cadenaleida,char *operadores){
	char *ptr = cadenaleida;
	for(;*ptr != '\0';ptr++){
		if(*ptr == 42 || *ptr == 43 || *ptr == 45 || *ptr == 47 ){
			*operadores = *ptr;
			operadores++;
		}
	}
}

int procesamiento(int *numeros,char *operadores){

    int resultado = numeros[0];
    int *ptrNumeros = numeros;
    char *ptrOperadores= operadores;
    ptrNumeros++;
    for(;*(ptrNumeros) != '\0';(ptrNumeros)++){
        switch(*ptrOperadores){
            case '+':
                resultado = resultado + *ptrNumeros;
                break;
            case '*':
                resultado = resultado * *ptrNumeros;
                break;
            case '/':
                resultado = resultado / *ptrNumeros;
                break;
            case '-':
                resultado = resultado - *ptrNumeros;
                break;
            default :
            	break;
        }
        ptrOperadores++;
    }
    return resultado;
}

void separar(char *cadenaleida,int *vectorNumeros){
    int numeros[100];
    char aux[100];
    char operadores[100];
    char *ptrAux = aux;
    char *respaldo = aux;
    int resultado;
	for(;*cadenaleida != '\0';cadenaleida++){
	    if(*cadenaleida != '+' && *cadenaleida != '-'){
	       *ptrAux = *cadenaleida;
	        ptrAux++;
	    }else{
	        conversion(aux,numeros);
	        conversionOperadores(aux,operadores);
	        resultado = procesamiento(numeros,operadores);
	        *vectorNumeros = resultado;
	        vectorNumeros++;
			memset(aux,'\0',100);
			memset(numeros,'\0',1000);
		    ptrAux = respaldo;
	    }
	}
	conversion(aux,numeros);
	conversionOperadores(aux,operadores);
	resultado = procesamiento(numeros,operadores);
	*vectorNumeros = resultado;
	vectorNumeros++;
	memset(aux,'\0',100);
	ptrAux = respaldo;
}


void conversionOperadores2(char *cadenaleida,char *operadores){
	char *ptr = cadenaleida;
	for(;*ptr != '\0';ptr++){
		if(*ptr == '+' || *ptr == '-' ){
			*operadores = *ptr;
			operadores++;
		}
	}
}

void reversaArrays(int arr[], int n)
{
    int aux[n];

    for (int i = 0; i < n; i++) {
        aux[n - 1 - i] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = aux[i];
    }
}

void reverseCadena(char *operadores)
{
    int n = strlen(operadores);
    char aux[n];

    for (int i = 0; i < n; i++) {
        aux[n - 1 - i] = operadores[i];
    }

    for (int i = 0; i < n; i++) {
        operadores[i] = aux[i];
    }
}

