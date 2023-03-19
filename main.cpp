#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <curses.h>
#include "menu.h"
#include "player.h"
#include "archer.h"
#include "warrior.h"

// enum subject {
//     warrior,
//     archer,
// } Subject;

int main() {
    initscr();
    show_welcome();
	scanw("\r");
    
    ifstream in_file("record.log");
    while (!in_file.eof()) {
		char name[100];
		int dmg, hp, exp, subject = -1;
		in_file >> name >> dmg >> hp >> exp >> subject;
		if (subject == 0)
			player_ptrs[Player::fetch_n_players() - 1] = new Player(name, dmg, hp, exp);
        else if (subject == 1)
			player_ptrs[Player::fetch_n_players() - 1] = new Warrior(name, dmg, hp, exp);
		else if (subject == 2)
			player_ptrs[Player::fetch_n_players() - 1] = new Archer(name, dmg, hp, exp);
	}
	in_file.close();

    show_menu();
    refresh();
	endwin();
	return 0;
}