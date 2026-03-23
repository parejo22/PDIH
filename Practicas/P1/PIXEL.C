#include <dos.h>
#include <stdio.h>

void dibujarPixel(int posX, int posY, unsigned char color){
    union REGS regs;

    regs.x.cx = posX;   
    regs.x.dx = posY;   
    regs.h.al = color;  
    regs.h.ah = 0x0C;   

    int86(0x10, &regs, &regs);
}

int main() {
    union REGS regs;

    // Cambiar a modo gráfico 320x200 256 colores (modo 13h)
    regs.h.ah = 0x00;
    regs.h.al = 0x13;
    int86(0x10, &regs, &regs);

     // Cambio solo el color del texto,,,,,,colores, negro=0,azul=1,verde=2,cyan=3, rojo,4magenta=5, marron=6, grisclaro=7,blanco=15
    dibujarPixel(102,100,1);

    dibujarPixel(100,102,2);
    dibujarPixel(104, 102,3);

    dibujarPixel(98,104, 4);
    dibujarPixel(106,104, 5);

    dibujarPixel(100,106,6);
    dibujarPixel(104,106,7);

    dibujarPixel(102,108,15);

    // Esperar tecla
    getch();

    // Volver a modo texto
    regs.h.ah = 0x00;
    regs.h.al = 0x03;
    int86(0x10, &regs, &regs);

    return 0;
}