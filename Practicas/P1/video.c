#include <stdio.h>
#include <dos.h>

// Cambia el modo de video usando la interrupción BIOS 10h
void cambiar_modo_video(unsigned char modo) {
    union REGS regs;
    regs.h.ah = 0x00;   // Función BIOS: cambiar modo de video
    regs.h.al = modo;   // Modo de video deseado
    int86(0x10, &regs, &regs);  // Llamada a la interrupción 10h
}

int main() {
    int modo;

    printf("Selecciona el modo de video deseado:\n");
    printf("00h - 40x25 16 colores (Texto)\n");
    printf("01h - 40x25 16 colores (Texto)\n");
    printf("02h - 80x25 16 colores (Texto)\n");
    printf("03h - 80x25 16 colores (Texto)\n");
    printf("04h - 320x200 4 colores (Grafico)\n");
    printf("05h - 320x200 4 colores (Grafico)\n");
    printf("06h - 640x200 2 colores (Grafico)\n");
    printf("07h - 80x25 2 colores (Texto)\n");
    printf("0Dh - 320x200 16 colores (Grafico)\n");
    printf("0Eh - 640x200 16 colores (Grafico)\n");
    printf("0Fh - 640x350 2 colores (Grafico)\n");
    printf("12h - 640x480 16 colores (Grafico)\n");
    printf("13h - 320x200 256 colores (Grafico)\n");

    printf("\nIntroduce el modo de video (en hexadecimal, sin 0x): ");
    scanf("%x", &modo); // %x para leer hex

    cambiar_modo_video((unsigned char)modo);

    printf("Modo de video cambiado.\n");

    return 0;
}