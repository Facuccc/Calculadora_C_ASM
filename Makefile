main: main.o
	gcc main.c -o main
# Elimina los objetos creados
iPHONY:clean
clean:
	rm *.o main