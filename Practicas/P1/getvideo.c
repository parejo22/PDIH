#include <stdio.h>
#include <dos.h>

unsigned char getvideomode() {
    union REGS regs;
    regs.h.ah = 0x0F;    
    int86(0x10, &regs, &regs); 
    return regs.h.al;       // AL contiene el modo de video
}

int main() {
    unsigned char modo;

    modo = getvideomode();

    printf("El modo de video actual es: 0x%X\n", modo);

    return 0;
}