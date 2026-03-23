#include <stdio.h>
#include <dos.h>

// Función auxiliar para imprimir un carácter en una posición
void imprimir(int x, int y, char c, unsigned char atributo){
    union REGS r;

    r.h.ah = 0x02;
    r.h.dh = y;
    r.h.dl = x;
    r.h.bh = 0;
    int86(0x10, &r, &r);

    r.h.ah = 0x09;
    r.h.al = c;
    r.h.bl = atributo;
    r.x.cx = 1;
    int86(0x10, &r, &r);
}

void recuadro(int x1, int y1, int x2, int y2, char color, char fondo){
    int i;
    unsigned char attr = (fondo << 4) | (color & 0x0F);

    // Líneas horizontales
    for(i = x1 + 1; i < x2; i++){
        imprimir(i, y1, 205, attr);
        imprimir(i, y2, 205, attr);
    }

    // Líneas verticales
    for(i = y1 + 1; i < y2; i++){
        imprimir(x1, i, 186, attr);
        imprimir(x2, i, 186, attr);
    }

    // Esquinas
    imprimir(x1, y1, 201, attr);
    imprimir(x2, y1, 187, attr);
    imprimir(x1, y2, 200, attr);
    imprimir(x2, y2, 188, attr);
}
int main() {
    union REGS r;

    int x1, y1, x2, y2;

    // Modo texto
    r.h.ah = 0x00;
    r.h.al = 0x03;
    int86(0x10, &r, &r);

    printf("Introduce esquina superior izquierda (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Introduce esquina inferior derecha (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    recuadro(x1, y1, x2, y2, 15, 15);

    getch();

    return 0;
}