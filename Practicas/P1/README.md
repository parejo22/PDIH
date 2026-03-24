
# Práctica 1
El código de los ejercicios se encuentra en la misma carpeta, su nombre se corresponde con el nombre del ejercicio
## Ejercicio 1 gotoxy():
Para este ejercicio se ha modificado el codgio facilitado, cambiando el main para que el usuario determine la posición en la que mostrar el *
<img width="1030" height="677" alt="image" src="https://github.com/user-attachments/assets/0ef9a070-c20c-4348-80ac-e02d0d5c08e1" />

---

## Ejercicio 2 setcursortype():
Primer cursor: Vemos cómo el cursor "desaparece", es decir, es invisible.
<img width="1023" height="146" alt="Captura desde 2026-03-10 17-28-32" src="https://github.com/user-attachments/assets/2f6dec91-8b92-4915-971c-ae6b3c8acd27" />

Segundo cursor: Cursor por defecto, una pequeña raya baja que parpadea
<img width="1023" height="146" alt="image" src="https://github.com/user-attachments/assets/f7649919-10b3-49ed-9ae9-7ee3cb0e6c9e" />

Tercer cursor: Cursor grueso que rellena el espacio, indicando claramente dónde se va a escribir.
<img width="1017" height="144" alt="image" src="https://github.com/user-attachments/assets/b6ad61f0-4950-4e78-b4fe-160182faa6c7" />

---

## Ejercicio 3 setvideomode():
Este programa nos muestra los diferentes modos de vídeo que podemos usar y nos da la posibilidad de cambiar entre ellos.
<img width="1021" height="434" alt="image" src="https://github.com/user-attachments/assets/bb5f6921-ff16-4dec-aaf3-f88d5a6d359a" />
<img width="1014" height="664" alt="image" src="https://github.com/user-attachments/assets/0e6e1ac5-a6b5-4d12-99ac-1c3bc9824ec2" />
<img width="1014" height="664" alt="image" src="https://github.com/user-attachments/assets/95cb013e-924b-495a-86e8-0d4849220bce" />
<img width="1014" height="664" alt="image" src="https://github.com/user-attachments/assets/40626b19-c11d-4924-9d15-b5ca2bbcbd9a" />


---

## Ejercicio 4 getvideomode():
Para mostrar el funcionamiento me ayudaré de setvideomode(), para así poder demostrar que realmente se está leyendo el modo de video y que no se está mostrando un mensaje:
<img width="1009" height="556" alt="image" src="https://github.com/user-attachments/assets/07e9e052-1318-4761-886b-42f5b49fd976" />
<img width="1009" height="556" alt="image" src="https://github.com/user-attachments/assets/01fc3f64-0060-41f2-b9da-947c4d5da6fe" />

---

## Ejercicio 5 textcolor():
Esta función cambia el color del texto que escribimos por terminal: 
```c
void textcolor(unsigned char color) {
    ctexto = color;
}
int main() {
    printf("Texto normal en la pantalla:\n");

    // Cambio solo el color del texto,,,,,,colores, negro=0,azul=1,verde=2,cyan=3, rojo,4magenta=5, marron=6, grisclaro=7,blanco=15
    textcolor(4); // Rojo
    cputchar('o');

    return 0;
}
```

<img width="598" height="340" alt="image" src="https://github.com/user-attachments/assets/0f217239-c434-455c-a0dd-3bda5570c375" />

---

## Ejercicio 6 textbackground():
Ejercicio muy similar al anterior, pero esta vez nos enfocamos en el color de fondo del texto.

```c
void fondocolor(unsigned char color2){
    cfondo = color2;
}
```

<img width="986" height="138" alt="image" src="https://github.com/user-attachments/assets/9ac4078c-7f14-4524-8595-24c272610fe9" />

---
## Ejercicio 7 clrscr():
Hay distintas maneras de realizar este ejercicio, en mi caso he decidido, utilizar la funcion para obtener el modo de video actual y seguidamente cambiar un set del mismo modo de video de esta manera limpiamos la pantalla.

<img width="1018" height="676" alt="image" src="https://github.com/user-attachments/assets/856befd7-fb47-49b9-be65-d41f76dee872" />
<img width="1019" height="199" alt="image" src="https://github.com/user-attachments/assets/ab12943e-db61-4364-98eb-f631f482b18a" />

---
## Ejercicio 8 cputchar():
cputchar escribe el caracter que nosotros deseemos por pantalla podemos ver el uso de esta función en los ejercicios 6 y 7:
```c
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
```
---
## Ejercicio 9 getche():
Este ejercicio muestra la última tecla pulsada por teclado.

<img width="982" height="141" alt="image" src="https://github.com/user-attachments/assets/23654afa-2ee2-490f-851a-26a0c15d1585" />

---
## Ejercicio 10 pixel():
Pixel() dibuja un pixel en modo gráfico (la función recibirá la coordinada x,y y el color del punto).

```c
void dibujarPixel(int posX, int posY, unsigned char color){
    union REGS regs;

    regs.x.cx = posX;   
    regs.x.dx = posY;   
    regs.h.al = color;  
    regs.h.ah = 0x0C;   

    int86(0x10, &regs, &regs);
}
```

<img width="952" height="596" alt="image" src="https://github.com/user-attachments/assets/2f4f9f19-90b1-4795-bd4b-fec9d4c08dc0" />


---
## Ejercicio 11 Implementar una función para dibujar recuadros en la pantalla (en modo texto):

El programa dibuja un recuadro en modo texto usando la interrupción 0x10 de la BIOS. Primero coloca el cursor en cada posición con AH=02, y luego imprime caracteres con borde usando AH=09 y colores combinados de fondo y texto. Las líneas horizontales y verticales se dibujan con bucles, y las esquinas se colocan manualmente  por entrada de teclado para completar el marco del rectángulo.
<img width="952" height="596" alt="image" src="https://github.com/user-attachments/assets/e55fd8e3-d101-4680-acc2-eb758951ad86" />

---
## Ejercicio 12 Programa que realice dibujos sencillos en pantalla (en modo gráﬁco):
Dibujo realizado utilizando funciones de otros ejercicios, pixel para hacer los dibujos, pausa y cambio de modo de video.

<img width="1003" height="635" alt="image" src="https://github.com/user-attachments/assets/152affd3-e48a-4313-991d-78eca5d9b51d" />


---
## Ejercicio 13 Programa que realice un dibujo sencillo de tipo “ascii art” (en modo texto):
Por último, este programa se realiza mediante el uso de las funciones cputchar para poner todos los caracteres y el clrscr para limpiar la pantalla.
Algunos ejemplos:
```c
        const char *dibujo[] = {
        "   /^ ^\\",
        "  / 0 0 \\",
        "  V\\ Y /V",
        "   / - \\",
        "  |    \\",
        "  || (__V"
    };
```
<img width="789" height="356" alt="image" src="https://github.com/user-attachments/assets/411bc00b-a318-4114-adec-975329be3ddb" />
```c
        const char *dibujo[] = {

        "________$$$$..",
        "______$$$$$$$$$",
        "______$$$$$$$_$",
        "_____$$$$$$$$$$",
        "______$$$$$$$$$$",
        "_____$$$$$$_$$$$$",
        "____$$$$$$$_____$$$",
        "____$$$$$$$$_____$",
        "____$$$$$$$$$$",
        "_____$$$$$$$$$$",
        "_____$$$$$$$$$$$",
        "______$$$$$$$$$$$",
        "_$$$$___$$$$$$$$$",
        "__$$$$$$$$$$$$$$$",
        "_$$$$$$$$$$$$$$$",
        "$$$$$$$$$$$$$",
        "__$__$$$$$$",
        "____$$$$$$",
        "____$$$$$",
        "___$$$$$$_____$",
        "___$$$$$$___$$_$$",
        "____$$$$$___$__$$",
        "____$$$$$______$$",
        "_____$$$$$____$$$",
        "_______$$$$$$$$$",

    };
```
<img width="985" height="677" alt="image" src="https://github.com/user-attachments/assets/e51cfc10-f17b-4858-a79f-a2df83653610" />



.....

