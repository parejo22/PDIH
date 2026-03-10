#include <stdio.h>
#include <dos.h>


void mi_pausa() {
    union REGS inregs, outregs;
    inregs.h.ah = 8;
    int86(0x21, &inregs, &outregs);
}


int mi_getchar() {
    union REGS inregs, outregs;
    int caracter;
    inregs.h.ah = 1;
    int86(0x21, &inregs, &outregs);
    caracter = outregs.h.al;
    return caracter;
}


void mi_putchar(char c) {
    union REGS inregs, outregs;
    inregs.h.ah = 2;
    inregs.h.dl = c;
    int86(0x21, &inregs, &outregs);
}


void setcursortype(int tipo_cursor) {
    union REGS inregs, outregs;
    inregs.h.ah = 0x01;
    switch(tipo_cursor) {
        case 0: // invisible
            inregs.h.ch = 010;
            inregs.h.cl = 000;
            break;
        case 1: // normal
            inregs.h.ch = 010;
            inregs.h.cl = 010;
            break;
        case 2: // grueso
            inregs.h.ch = 000;
            inregs.h.cl = 010;
            break;
        default: 
            inregs.h.ch = 010;
            inregs.h.cl = 010;
            break;
    }
    int86(0x10, &inregs, &outregs);
}

int main() {
    int tmp;

    printf("Pulsa un numero para elegir cursor (0=invisible, 1=normal, 2=grueso): ");
    tmp = mi_getchar();

    printf("\nHas pulsado: ");
    mi_putchar((char)tmp);

    // Convertir el carácter ASCII a número
    if (tmp >= '0' && tmp <= '2') {
        int tipo = tmp - '0';
        setcursortype(tipo);
        printf("\nCursor cambiado segun tu eleccion.\n");
    } else {
        printf("\nNumero no valido. Se mantiene cursor normal.\n");
        setcursortype(1);
    }

    mi_pausa();
    return 0;
}