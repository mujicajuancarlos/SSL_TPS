/*

Ejercicio 1-24 K&R
Grupo #
Curso
Integrantes:
Juan Carlos Mujica
Alejandro Elustondo
Nicolas Zarratea
*/

#include <stdio.h>
#include <stdlib.h>

#define	EN_CODIGO				0
#define	EN_STRING				1
#define EN_CARACTER				2
#define EN_ESCAPE_STRING		3
#define EN_ESCAPE_CARACTER		4

typedef struct pila{
	int c;
	struct pila *sig;
}pila;

pila *puntero=NULL;

pila* datoNuevo(){
	pila *bloque = (pila*)malloc(sizeof(pila));
	if (bloque==NULL){
		printf("Falta memoria");
		exit(0);
	}

	return bloque;
}

void push(int dato){
	pila *bloque = datoNuevo();
	bloque->sig = puntero;
	bloque->c = dato;
	puntero = bloque;

}
int pop(void){
	pila *bloque;
	int valor;
	if (puntero==NULL) {
		puts("Lista vacia");
		return EOF;
	}else{
		valor = puntero->c;
		bloque = puntero;
		puntero = puntero->sig;
		free(bloque);

		return valor;

	}
}
int getTop(){
	return puntero->c;
}

int main(void) {

	int currentState, currentChar;
	currentState = EN_CODIGO;

	while ((currentChar = getchar()) != EOF){
		switch (currentState){
			case EN_CODIGO:
				switch (currentChar){
					case '{':
					case '(':
					case '[':
						push(currentChar);
						putchar(currentChar);
					break;
					case '}':
						if (getTop() != '{') {
							printf("Error de sintaxis, se esperaba: \"}\"\n");
							return -1;
						}
						pop();
						putchar(currentChar);
					break;

					case ')':
						if (getTop() != '(') {
							printf("Error de sintaxis, se esperaba: \")\"\n");
							return -1;
						}
						pop();
						putchar(currentChar);
					break;
					case ']':
						if (getTop() != '[') {
							printf("Error de sintaxis, se esperaba: \"]\"\n");
							return -1;
						}
						pop();
						putchar(currentChar);
					break;
					case '"':
						currentState = EN_STRING;
						putchar(currentChar);
						break;
					case '\'':
						currentState = EN_CARACTER;
						putchar(currentChar);
						break;
					default:
						putchar(currentChar);
				};
				break;
			case EN_STRING:
				switch (currentChar){
					case '\\':
						currentState = EN_ESCAPE_STRING;
						putchar(currentChar);
						break;
					case '\"':
						currentState = EN_CODIGO;
						putchar(currentChar);
						break;
					default:
						putchar(currentChar);
				};
				break;
			case EN_CARACTER:
				switch (currentChar){
					case '\\':
						currentState = EN_ESCAPE_CARACTER;
						putchar(currentChar);
						break;
					case '\'':
						currentState = EN_CODIGO;
						putchar(currentChar);
						break;
					default:
						putchar(currentChar);
				};
				break;
			case EN_ESCAPE_STRING:
				currentState = EN_STRING;
				putchar(currentChar);
				break;
			case EN_ESCAPE_CARACTER:
				currentState = EN_CARACTER;
				putchar(currentChar);
				break;
			default:
				printf("\n%s\n","ERROR");
		}
	}
	if (puntero==NULL){
		printf("\n%s\n","No se encontraron errores sintacticos de balanceo");
		return 0;
	} else {
		printf("\n%s\n","Error de balanceo");
		return -1;
	}
}
