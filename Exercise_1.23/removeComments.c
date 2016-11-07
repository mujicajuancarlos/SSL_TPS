/*

	Ejercicio 1-23 K&R
	Grupo #
	Curso
	Integrantes:
		Juan Carlos Mujica

*/

#include <stdio.h>

#define	EN_PROGRAMA				0
#define	INICIO_COMENTARIO		1
#define	EN_BLOQUE_COMENTARIO	2
#define EN_LINEA_COMENTARIO		3
#define	FIN_COMENTARIO			4
#define	EN_STRING				5
#define EN_CARACTER				6
#define EN_ESCAPE_STRING		7
#define EN_ESCAPE_CARACTER		8

int main(void) {
	
	int currentState, currentChar;
	currentState = EN_PROGRAMA;
	
	while ((currentChar = getchar()) != EOF){
		switch (currentState){
			case EN_PROGRAMA:
				switch (currentChar){
					case '/':
						currentState = INICIO_COMENTARIO;
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
			case INICIO_COMENTARIO:
				switch (currentChar){
					case '/':
						currentState = EN_LINEA_COMENTARIO;
						break; 
					case '*':
						currentState = EN_BLOQUE_COMENTARIO;
						break;
					default:
						currentState = EN_PROGRAMA;
						putchar('/');
						putchar(currentChar);
				};
				break; 
			case EN_BLOQUE_COMENTARIO:
				switch (currentChar){
					case '*':
						currentState = FIN_COMENTARIO;
						break;
				};
				break; 
			case EN_LINEA_COMENTARIO:
				switch (currentChar){
					case '\n':
						currentState = EN_PROGRAMA;
						putchar(' ');
						break;
				};
				break; 
			case FIN_COMENTARIO:
				switch (currentChar){
					case '/':
						currentState = EN_PROGRAMA;
						putchar(' ');
						break;
					case '*':
						currentState = FIN_COMENTARIO;
						break;
					default:
						currentState = EN_BLOQUE_COMENTARIO;
				};
				break;
			case EN_STRING:
				switch (currentChar){
					case '\\':
						currentState = EN_ESCAPE_STRING;
						putchar(currentChar);
						break;
					case '\"':
						currentState = EN_PROGRAMA;
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
						currentState = EN_PROGRAMA;
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
	return 0;
}
