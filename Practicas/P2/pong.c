#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 30000

void pantalla_bienvenida() {
    clear();
    refresh(); // refrescar la pantalla principal

    int term_y, term_x;
    getmaxyx(stdscr, term_y, term_x);

    int box_height = 12, box_width = 60;
    int start_y = (term_y - box_height) / 2;
    int start_x = (term_x - box_width) / 2;

    // crear ventana de bienvenida centrada
    WINDOW *bienvenida = newwin(box_height, box_width, start_y, start_x);
    box(bienvenida, 0, 0);

    mvwprintw(bienvenida, 1, 2, "Juego de Pong en C - ncurses");
    mvwprintw(bienvenida, 2, 2, "Creado por: ALBERTO PAREJO BELLIDO");
    mvwprintw(bienvenida, 4, 2, "Controles:");
    mvwprintw(bienvenida, 5, 4, "Flecha ARRIBA - Mover pala hacia arriba");
    mvwprintw(bienvenida, 6, 4, "Flecha ABAJO - Mover pala hacia abajo");
    mvwprintw(bienvenida, 8, 2, "Presiona cualquier tecla para comenzar...");

    wrefresh(bienvenida); // refrescar la ventana

    // Esperar tecla pulsada
    nodelay(stdscr, FALSE);
    getch();
    nodelay(stdscr, TRUE);

    delwin(bienvenida);
}

void dibujar_tablero(WINDOW *tablero, int max_y, int max_x, int paddle_y, int ball_y, int ball_x) {
    werase(tablero);
    box(tablero, 0, 0);
    // dibujar pelota
    mvwprintw(tablero, ball_y, ball_x, "o");
    // dibujar pala
    mvwprintw(tablero, paddle_y, 2, "|");
    mvwprintw(tablero, paddle_y + 1, 2, "|");
    mvwprintw(tablero, paddle_y + 2, 2, "|");
    wrefresh(tablero);
}

int main() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    pantalla_bienvenida(); // ahora se ve correctamente

    int jugar = 1;
    int max_y = 20, max_x = 60;

    while (jugar) {
        int x = max_x / 2, y = max_y / 2;
        int dir_x = 1, dir_y = 1;
        int paddle_y = max_y / 2 - 1;
        int puntaje = 0;

        WINDOW *tablero = newwin(max_y + 2, max_x + 2, 0, 0); // ventana del tablero

        while (1) {
            dibujar_tablero(tablero, max_y, max_x, paddle_y, y, x);

            int ch = getch();
            if (ch == KEY_UP && paddle_y > 1) paddle_y--;
            if (ch == KEY_DOWN && paddle_y < max_y - 2) paddle_y++;

            usleep(DELAY);

            x += dir_x;
            y += dir_y;

            if (y <= 1 || y >= max_y - 1) dir_y *= -1;
            if (x >= max_x - 1) dir_x *= -1;
            if (x == 3 && (y >= paddle_y && y <= paddle_y + 2)) {
                dir_x *= -1;
                puntaje++;
            }

            if (x <= 1) {
                werase(tablero);
                box(tablero, 0, 0);
                mvwprintw(tablero, max_y / 2 - 1, max_x / 2 - 10, "FIN DEL JUEGO");
                mvwprintw(tablero, max_y / 2, max_x / 2 - 12, "Tu puntuacion: %d", puntaje);
                mvwprintw(tablero, max_y / 2 + 2, max_x / 2 - 18, "Presiona R para jugar otra vez o Q para salir");
                wrefresh(tablero);

                int opc;
                while (1) {
                    opc = getch();
                    if (opc == 'r' || opc == 'R') break;
                    if (opc == 'q' || opc == 'Q') { jugar = 0; break; }
                }
                break;
            }
        }

        delwin(tablero);
    }

    endwin();
    return 0;
}