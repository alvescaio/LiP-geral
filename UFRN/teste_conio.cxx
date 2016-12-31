#include <iostream>
#include <curses.h>
#include <stdlib.h>


using namespace std;


int main()
{
   while(1)
   {
      char tecla;
      initscr();
      clear();
      printw("digite um caracter... \n");
      keypad(stdscr, TRUE);
      noecho();
      tecla = (int)getch();
      if(tecla == 32)
      {
         printw("tecla espaço\n");
      }
      else if( (tecla == 3 ))
      {
         printw("tecla acima\n");
      }
      else if( tecla == 4 )
      {
         printw("tecla esquerda\n");
      }
      else if( tecla == 5 )
      {
         printw("tecla direita\n");
      }
      else if( tecla == 2 )
      {
         printw("tecla abaixo\n");
      }
      else
      {
         printw("tecla %c\n", tecla);
      }
      printw( "código: %d\n", tecla );
      refresh();
      delay_output(2000);
      endwin();
   }
   return(0);
}
