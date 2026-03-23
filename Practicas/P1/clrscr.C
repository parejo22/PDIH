#include <stdio.h>
#include <dos.h>

// Cambia el modo de video usando la interrupción BIOS 10h
void cambiar_modo_video(unsigned char modo) {
    union REGS regs;
    regs.h.ah = 0x00;   // Función BIOS: cambiar modo de video
    regs.h.al = modo;   // Modo de video deseado
    int86(0x10, &regs, &regs);  // Llamada a la interrupción 10h
}
unsigned char getvideomode() {
    union REGS regs;
    regs.h.ah = 0x0F;    
    int86(0x10, &regs, &regs); 
    return regs.h.al;       // AL contiene el modo de video
}
int main() {

    unsigned char modo;
	modo = getvideomode();
    cambiar_modo_video((unsigned char)modo);


    return 0;
}
