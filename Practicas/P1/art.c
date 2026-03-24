#include <conio.h>
#include <stdio.h>
#include <dos.h>

unsigned char cfondo = 0;  // fondo negro
unsigned char ctexto = 14; // color amarillo

void mi_pausa() {
    union REGS inregs, outregs;
    inregs.h.ah = 8;
    int86(0x21, &inregs, &outregs);
}
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

void dibujar(int posX, int posY, unsigned char color) {
    const char *dibujo[] = {
        "   /^ ^\\",
        "  / 0 0 \\",
        "  V\\ Y /V",
        "   / - \\",
        "  |     \\",
        "  || (__V"
    };
    
    int total_lineas = sizeof(dibujo) / sizeof(dibujo[0]);
    int f;

    textcolor(color);
    textbackground(cfondo);

    for(f = 0; f < total_lineas; f++){
        gotoxy(posX, posY + f);
        cputs(dibujo[f]);  // imprime la línea completa
    }
}

int main() {
    unsigned char modo;
	modo = getvideomode();
    cambiar_modo_video((unsigned char)modo);//limpio pantalla 
    dibujar(10, 5, ctexto); // dibujar el perrito
    mi_pausa();                      // espera tecla
    return 0;
}