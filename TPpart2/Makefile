CC= gcc 
CFLAGS= -g -m32 -fno-stack-protector
all: ejemplo1 ejemplo2

ejemplo1: Ejemplo1.c
	$(CC) $(CFLAGS) Ejemplo1.c -o ejemplo1
ejemplo2: Ejemplo2.c
	$(CC) $(CFLAGS) Ejemplo2.c -o ejemplo2
	
iPHONY:clean
clean:
	rm -f ejemplo1 ejemplo2
