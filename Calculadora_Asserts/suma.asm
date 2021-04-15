

segment .text
    global  suma_asm

suma_asm:
	enter	0,0
    push   ebx ; guarda el valor del antiguo EBP en el stack
    
           
	mov    eax,[ebp+8]; numA           
    add    eax,[ebp+12]; numB
	mov    ebx,[ebp+16];EBP=&RESULTADO

    mov    [ebx],eax ;*EBP=EAX   
    pop     ebx
	leave
    ret

