#include <stdio.h>
#include <dos.h>

unsigned char cfondo=0;
unsigned char ctexto=1;

void textcolor(unsigned char color) {
    ctexto = color;
}

void cputchar(char c) {
    union REGS inregs, outregs;
    inregs.h.ah = 0x09;                 
    inregs.h.al = c;                     
    inregs.h.bl = (cfondo << 15) | ctexto; 
    inregs.h.bh = 0x00;                  
    inregs.x.cx = 1;                    
    int86(0x10, &inregs, &outregs);
}

int main() {
    printf("Texto normal en la pantalla:\n");

    // Cambio solo el color del texto,,,,,,colores, negro=0,azul=1,verde=2,cyan=3, rojo,4magenta=5, marron=6, grisclaro=7,blanco=15
    textcolor(4); // Rojo
    cputchar('o');

    return 0;
}
