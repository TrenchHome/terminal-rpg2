#ifndef ANIME_H
#define ANIME_H
#define AX 6
#define AY 15
#define AYY 2
#include<iostream>
#include<curses.h>

void gameover()
{
	mvaddstr(AX+0, AYY, " ￭￭￭    ￭   ￭    ￭ ￭￭￭￭  ￭￭￭ ￭       ￭ ￭￭￭￭ ￭￭￭ ");
	mvaddstr(AX+1, AYY, "￭      ￭ ￭  ￭￭  ￭￭ ￭    ￭   ￭ ￭     ￭  ￭    ￭  ￭");
	mvaddstr(AX+2, AYY, "￭ ￭￭￭ ￭￭￭￭￭ ￭  ￭ ￭ ￭￭￭￭ ￭   ￭  ￭   ￭   ￭￭￭￭ ￭ ￭ ");
	mvaddstr(AX+3, AYY, "￭  ￭  ￭   ￭ ￭    ￭ ￭    ￭   ￭   ￭ ￭    ￭    ￭ ￭ ");
	mvaddstr(AX+4, AYY, " ￭￭￭  ￭   ￭ ￭    ￭ ￭￭￭￭  ￭￭￭     ￭     ￭￭￭￭ ￭  ￭");
}
void win()
{
	mvprintw(AX+0, AY, "￭   ￭  ￭￭￭  ￭   ￭   ￭   ￭   ￭ ￭￭￭￭￭ ￭   ￭   ￭￭");
	mvprintw(AX+1, AY, " ￭ ￭  ￭   ￭ ￭   ￭    ￭ ￭ ￭ ￭    ￭   ￭￭  ￭   ￭￭");
	mvprintw(AX+2, AY, "  ￭   ￭   ￭ ￭   ￭     ￭   ￭     ￭   ￭ ￭ ￭    ");
    // mvprintw(AX+3, AY, "  ￭    ￭￭￭   ￭￭￭      ￭   ￭   ￭￭￭￭￭ ￭   ￭    ￭");
	mvprintw(AX+3, AY, "  ￭   ￭   ￭ ￭   ￭     ￭   ￭     ￭   ￭  ￭￭     ");
	mvprintw(AX+4, AY, "  ￭    ￭￭￭   ￭￭￭      ￭   ￭   ￭￭￭￭￭ ￭   ￭    ￭");
}
void show_welcome()
{
	mvprintw(AX+0, AY, "￭   ￭   ￭￭￭  ￭￭￭￭￭  ￭   ￭  ￭￭￭￭  ￭￭￭  ￭￭￭￭ ");
	mvprintw(AX+1, AY, "￭￭  ￭  ￭     ￭    ￭   ￭  ￭    ￭     ￭    ");
	mvprintw(AX+2, AY, "￭ ￭ ￭  ￭       ￭    ￭   ￭  ￭￭￭￭ ￭     ￭￭￭￭ ");
	mvprintw(AX+3, AY, "￭  ￭￭  ￭       ￭    ￭   ￭  ￭    ￭     ￭    ");
	mvprintw(AX+4, AY, "￭   ￭   ￭￭￭    ￭     ￭ ￭   ￭￭￭￭  ￭￭￭  ￭￭￭￭ ");
	mvprintw(AX+8, AY, "Press Enter to start the game...\n");
}
#endif
