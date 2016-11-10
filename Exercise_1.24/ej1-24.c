#include<stdio.h>
 
int llave,parentesis,corchete;
 
void dentroDelComentario();
void comillaSyD(int c);
void texto(int c);
 
int main(void){
	int c; 
	extern int llave,parentesis,corchete;
 
	while((c=getchar())!=EOF){
		if( c == '/'){
			if((c=getchar())== '*')
				dentroDelComentario();
			else 
				texto(c);
		}			
		else if( c == '\'' || c == '"')
			comillaSyD(c);
		else
			texto(c);		
	}		
 
	if( llave != 0)	{
		printf("Error en una/s llave/s\n");
		llave = 0;
	}   
	if( parentesis != 0)	{
		printf("Error en un/unos parentesis\n");
		parentesis = 0;
	}
	if( corchete != 0)	{
		printf("Error en un/unos corchete/s\n");
		corchete = 0;
	}
 
	return 0;
}
 
void dentroDelComentario(){
	int actual,siguiente; 
	actual = getchar();
	siguiente = getchar();
 
	while(actual != '*' || siguiente != '/')	{
		actual = siguiente;
		siguiente = getchar();
	}
}
 
void comillaSyD(int c){
	int nuevo; 	 
	while((nuevo=getchar())!=c)
		if( nuevo == '\\')
			getchar();
}
 
void texto(int c){
	extern int llave,parentesis,corchete;
 
	if ( c == '{')
		--llave;
	else if ( c == '}')
		++llave;
	else if( c == '(')
		--parentesis;
	else if( c == ')')
		++parentesis;
	else if( c == '[')
		--corchete;
	else if( c == ']')
		++corchete;
}