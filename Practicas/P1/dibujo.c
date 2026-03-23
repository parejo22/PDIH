#include <stdio.h>
#include <dos.h>

// Cambia el modo de video usando la interrupción BIOS 10h
void cambiar_modo_video(unsigned char modo) {
    union REGS regs;
    regs.h.ah = 0x00;   // Función BIOS: cambiar modo de video
    regs.h.al = modo;   // Modo de video deseado
    int86(0x10, &regs, &regs);  // Llamada a la interrupción 10h
}
void dibujarPixel(int posX, int posY, unsigned char color){
    union REGS regs;

    regs.x.cx = posX;   
    regs.x.dx = posY;   
    regs.h.al = color;  
    regs.h.ah = 0x0C;   

    int86(0x10, &regs, &regs);
}
void mi_pausa(){
   union REGS inregs, outregs;
	 inregs.h.ah = 8;
	 int86(0x21, &inregs, &outregs);
}

int main() {
        int i, j;

    // Pasar a modo gráfico 320x200, 4 colores (modo 4 CGA)
    cambiar_modo_video(4);

    // --- Dos pisos ---
    // Piso 1
    for(i = 170; i <= 230; i++){
        for(j = 80; j <= 180; j++){
            dibujarPixel(i, j, 1); // azul
        }
    }

    // Piso 2
    for(i = 100; i <= 160; i++){
        for(j = 80; j <= 180; j++){
            dibujarPixel(i, j, 2); // verde
        }
    }
    // Ventanas Piso 1 (azul)
for(i = 180; i <= 190; i++){
    for(j = 100; j <= 120; j++){
        dibujarPixel(i, j, 0); // amarillo
    }
}
for(i = 200; i <= 210; i++){
    for(j = 100; j <= 120; j++){
        dibujarPixel(i, j, 0); // amarillo
    }
}

// Ventanas Piso 2 (verde)
for(i = 120; i <= 130; i++){
    for(j = 100; j <= 120; j++){
        dibujarPixel(i, j, 0); // amarillo
    }
}
for(i = 140; i <= 150; i++){
    for(j = 100; j <= 120; j++){
        dibujarPixel(i, j, 0); // amarillo
    }
}
    //Avion
    // Cuerpo horizontal
for(i = 50; i <= 70; i++){
    for(j = 40; j <= 42; j++){
        dibujarPixel(i, j, 15); // fuselaje blanco
    }
}

// Cabina frontal
for(i = 68; i <= 70; i++){
    for(j = 39; j <= 43; j++){
        dibujarPixel(i, j, 15);
    }
}

// Ala superior
for(i = 55; i <= 65; i++){
    for(j = 38; j <= 39; j++){
        dibujarPixel(i, j, 15);
    }
}

// Ala inferior
for(i = 55; i <= 65; i++){
    for(j = 43; j <= 44; j++){
        dibujarPixel(i, j, 15);
    }
}

// Cola vertical
for(i = 50; i <= 51; i++){
    for(j = 40; j <= 42; j++){
        dibujarPixel(i, j, 15);
    }
}

// Cola horizontal
for(i = 50; i <= 53; i++){
    for(j = 39; j <= 39; j++){
        dibujarPixel(i, j, 15);
    }
    for(j = 43; j <= 43; j++){
        dibujarPixel(i, j, 15);
    }
}
    printf("Pulsa una tecla para salir...");
    mi_pausa();

    // Restaurar modo texto
    cambiar_modo_video(3);

    return 0;

}