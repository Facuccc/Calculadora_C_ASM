AS		:= nasm
ASFLAGS := -f elf
CFLAGS	:= -m32
CC		:= gcc
EJECUTABLE := calc_asm
DEP := calc_asm.o suma_asm.o resta_asm.o


$(EJECUTABLE): $(DEP) 
	$(CC) $(CFLAGS) $(DEP)  -o calc_asm
calc_asm.o: main.c
	$(CC) $(CFLAGS) -c  main.c -o calc_asm.o
suma_asm.o: suma.asm 
	$(AS) $(ASFLAGS) -d ELF_TYPE suma.asm -o suma_asm.o
resta_asm.o: resta.asm 
	$(AS) $(ASFLAGS) -d ELF_TYPE resta.asm -o resta_asm.o


iPHONY:clean
clean:
	rm -f *.o $(EJECUTABLE)
