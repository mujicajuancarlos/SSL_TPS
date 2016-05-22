#DEFINO MI ENTORNO

#programa
MAIN=hello
#cofigo fuente
SOURCE=hello.c

#compilador
CC=gcc
#version del compilador
C_OPTIONS=-std=c11 -Wall -pedantic-errors 
#propiedades varias
C_FLAGS=-I$(IDIR)
#librerias
C_LIBRARIES=por ahora nada

all: $(MAIN)
	@echo "Se compilo exitosamente!"
#Link de .objects
$(MAIN): hello.o
	cc -o $(MAIN) hello.o
#ejecuto el conversor de assemble a codigo objeto
hello.o: hello.s
	as -o hello.o hello.s
#ejecuto el compilador *(para que genere el codigo assembler)
hello.s: hello.i
	$(CC) -S $(C_OPTIONS) hello.i
#ejecuto el preprocesador
hello.i:
	cpp $(SOURCE) > hello.i
	
clean:
	rm hello.i hello.s hello.o hello
	@echo "Se eliminaron todos los archivos intermedios"
	
rebuild:
	clean all