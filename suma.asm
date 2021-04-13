

segment .text
        global  suma_asm

suma_asm:
        push   ebp ; guarda el valor del antiguo EBP en el stack
        mov    ebp, esp ; copia el valor de ESP en el puntero EBP, creando un nuevo stack frame
           
	mov    DWORD eax,[ebx+8]           
	add    DWORD eax,[ebx+12]
	mov    [ebx+16],eax        
     
        mov    esp, ebp
        pop    ebp
        ret

