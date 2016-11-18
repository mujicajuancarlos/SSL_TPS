#DEFINO MI ENTORNO

#cobre del programa
NAME=parser
#archivo final
MAIN=$(NAME).out
#cofigo fuente
SOURCE=$(NAME).c

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
$(MAIN): $(NAME).o
	cc -o $(MAIN) $(NAME).o
#ejecuto el conversor de assemble a codigo objeto
$(NAME).o: $(NAME).s
	as -o $(NAME).o $(NAME).s
#ejecuto el compilador *(para que genere el codigo assembler)
$(NAME).s: $(NAME).i
	$(CC) -S $(C_OPTIONS) $(NAME).i
#ejecuto el preprocesador
$(NAME).i:
	cpp $(SOURCE) > $(NAME).i
	
clean:
	rm $(NAME).i $(NAME).s $(NAME).o $(MAIN)
	@echo "Se eliminaron todos los archivos intermedios"
	
rebuild:
	clean all
