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

void multiplicacion_division(char *cadenaleida);

int main(void) {
	char cadenaleida[5];

	printf("Ingrese valores\nLos valores válidos son [0-9,+,-,*,/]:");
	scanf("%[0-9,+,-,*,/]s", cadenaleida);
	multiplicacion_division(cadenaleida);
	return 0;
	}




void multiplicacion_division(char *cadenaleida){
	int a,b;
	char *ptr;
	ptr = cadenaleida;

	while(*ptr != '\0'){
		if(*ptr == '*'){

			a = atoi(*(ptr--));
			b = atoi(*(ptr++));
			printf("%d",a);

		}
		ptr++;

	}
}
