/*

	Ejercicio 1-23 K&R
	Grupo #
	Curso
	Integrantes:
		Juan Carlos Mujica

*/

#include <stdio.h>

#define	EN_PROGRAMA			0
#define	INICIO_COMENTARIO	1
#define	EN_COMENTARIO		2
#define	FIN_COMENTARIO		3
#define	EN_STRING			4
#define EN_CARACTER			5

int main(void)
{
	int currentState, currentChar;
	
	currentState = EN_PROGRAMA;
	
	while ((currentChar = getchar()) != EOF){
		
	}
}
