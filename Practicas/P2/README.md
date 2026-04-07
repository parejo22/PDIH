# Práctica 2: Uso de la librería ncurses

---

## 1. Objetivos

### Los objetivos de esta práctica son:

- Instalar la librería ncurses en Linux
- Aprender a crear interfaces de texto
- Desarrollar programas interactivos en terminal
- Implementar un juego sencillo tipo Pong

## 2. Instalación de ncurses
   
Para instalar la librería en un sistema Ubuntu/Debian se ha utilizado el siguiente comando:

`sudo apt-get update
sudo apt-get install libncurses5-dev libncursesw5-dev`
<img width="803" height="438" alt="image" src="https://github.com/user-attachments/assets/f5963b7a-dc63-44a5-8d15-a67d6650a21f" />


Una vez instalada, ya se pueden compilar programas usando:

`gcc programa.c -o programa -lncurses`

---

## 3. Programas de ejemplo

### 3.1 Ejemplo 1: Hola mundo

Código

```c
#include <ncurses.h>

int main() {
    initscr();
    printw("Hola Alberto");
    refresh();
    getch();
    endwin();
    return 0;
}
```

Explicación

- initscr() inicia el modo ncurses
- printw() escribe texto en pantalla
- refresh() actualiza la pantalla
- getch() espera una tecla
- endwin() finaliza ncurses

Compilamos y ejecutamos:

`gcc hello.c -o hello -lncurses` 

`./hello `
  
<img width="957" height="115" alt="image" src="https://github.com/user-attachments/assets/bcb10091-c1dd-428a-b7e7-c67e5c07f60e" />

---

## 3.2 Ejemplo 2: Ventana con colores

Código

```c 
#include <stdlib.h>
#include <ncurses.h>

int main(void) {
    int rows, cols;

    initscr();

    if (has_colors() == FALSE) {
    	endwin();
    	printf("Your terminal does not support color\n");
    	exit(1);
	}

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3,COLOR_WHITE,COLOR_BLUE);
    clear();

    refresh();
    getmaxyx(stdscr, rows, cols); 

    WINDOW *window = newwin(rows,cols,0,0);
    wbkgd(window, COLOR_PAIR(3));
    box(window, '|', '-'); 

    mvwprintw(window, 10, 10, "una cadena");
    wrefresh(window);

    getch(); 
    endwin();
    return 0;
}
```
Explicación
- newwin() crea una ventana
- box() dibuja bordes
- init_pair() define colores
- wbkgd() aplica color de fondo
- mvwprintw() imprime texto en coordenadas
  
Compilamos y ejecutamos:

`gcc ventana.c -o ventana -lncurses`

`./ventana `

<img width="952" height="566" alt="image" src="https://github.com/user-attachments/assets/a9dda23d-7bd5-455c-b24f-474738fb689b" />

--- 

## 3.3 Ejemplo 3: Pelota en movimiento

Código

```c 
#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int main(int argc, char *argv[]) {
 int x = 0, y = 0;
 int max_y = 20, max_x = 20;
 int next_x = 0;
 int direction = 1;

 initscr();
 noecho();
 curs_set(FALSE);

 while(1) {
 	clear();
 	mvprintw(y, x, "o");
 	refresh();

 	usleep(DELAY);

 	next_x = x + direction;

 	if (next_x >= max_x || next_x < 0) {
 		direction*= -1;
 	} else {
 		x+= direction;
 	}
 }

 endwin();
}
```

Explicación
- Se mueve una pelota en horizontal
- Rebota en los bordes de la pantalla (bordes acotados con el int max_ )
- next_x: próxima posición en el eje horizontal
- initscr(): inicia el modo ncurses
- noecho(): evita que se muestren las teclas pulsadas
- curs_set(FALSE): oculta el cursor
- usleep() controla la velocidad

<img width="796" height="212" alt="image" src="https://github.com/user-attachments/assets/04429064-492e-48e5-a7e7-f7fe8a9c458c" />

---

## 4. Juego Pong

### 4.1 Descripción

Se ha desarrollado un juego básico tipo Pong que incluye:

- Una pelota en movimiento
- Una pala controlada por el usuario
- Detección de colisiones
- Fin de partida

Código [Ver código del Pong en C](https://github.com/parejo22/PDIH/blob/main/Practicas/P2/pong.c)

Explicación
1. Librerias:
- ncurses.h: Permite manejar la terminal para dibujar ventanas, texto, mover el cursor y leer teclas.
- unistd.h: Usado para usleep(), que pausa la ejecución en microsegundos.
- stdlib.h: Para funciones estándar como exit().
- DELAY: Define la velocidad de movimiento de la pelota (en microsegundos).
    
2. Pantalla de bienvenida:
- Crea una ventana centrada que muestra: título, autor y controles.
- box() dibuja un borde alrededor de la ventana.
- wrefresh() actualiza la ventana en la pantalla.
- getch() espera que el jugador pulse cualquier tecla para continuar.
- nodelay(stdscr, FALSE) permite que getch() bloquee hasta recibir una tecla, luego se vuelve a TRUE para el juego.
  
3. Función para dibujar el tablero
- werase(): limpia el contenido anterior de la ventana.
- box(): dibuja el borde del tablero.
- mvwprintw(): dibuja la pelota y la pala en las coordenadas dadas.
- wrefresh(): actualiza la ventana para mostrar los cambios.
4. main()
- Inicializa la pantalla de ncurses.
- noecho(): evita que las teclas se muestren en pantalla.
- curs_set(FALSE): oculta el cursor.
- keypad(): permite leer teclas especiales como flechas.
- nodelay(): hace que getch() no bloquee en el juego.
- La lógica que sigue el juego usa las variables para mover la pelota que vista en pelotita.c y añadimos la lectura de teclado para mover la pala paddle

<img width="629" height="512" alt="image" src="https://github.com/user-attachments/assets/2273ba7e-135d-48dc-accc-336c6df3a77c" />

<img width="636" height="514" alt="image" src="https://github.com/user-attachments/assets/4c44a532-ff8b-4b55-8d41-9ea8d097496c" />

<img width="629" height="512" alt="image" src="https://github.com/user-attachments/assets/6c91fa71-9bc2-4720-b9be-10d4a91b382c" />


