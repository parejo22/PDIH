// gcc hello.c -o hello -lncurses

#include <ncurses.h>
#include <stdio.h>
int main() {
initscr();
printw("Hola Alberto");
refresh();
getch();
endwin();
return 0;
}

