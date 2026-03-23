
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
## Ejercicio 8 cputchar():
## Ejercicio 9 getche():
## Ejercicio 10 pixel():
## Ejercicio 11 Implementar una función para dibujar recuadros en la pantalla (en modo texto):
## Ejercicio 12 Programa que realice dibujos sencillos en pantalla (en modo gráﬁco):
## Ejercicio 13 Programa que realice un dibujo sencillo de tipo “ascii art” (en modo texto):

.....

