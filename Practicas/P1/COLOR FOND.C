#include <stdio.h>
#include <dos.h>

unsigned char cfondo=1;
unsigned char ctexto=1;

void textcolor(unsigned char color) {
    ctexto = color;
}
void fondocolor(unsigned char color2){
    cfondo = color2;
}

void cputchar(char c) {
    union REGS inregs, outregs;
    inregs.h.ah = 0x09;                 
    inregs.h.al = c;                     
    inregs.h.bl = (cfondo << 4) | (ctexto & 0x0F); 
    inregs.h.bh = 0x00;                  
    inregs.x.cx = 1;                    
    int86(0x10, &inregs, &outregs);
}

int main() {
    printf("Texto normal en la pantalla:\n");

    // Cambio solo el color del texto,,,,,,colores, negro=0,azul=1,verde=2,cyan=3, rojo,4magenta=5, marron=6, grisclaro=7,blanco=15
    fondocolor(2);
    textcolor(15);
    cputchar('o');

    return 0;
}
