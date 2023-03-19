#ifndef PROMOTE_H
#define PROMOTE_H
#define REQUIRED_EXP_FOR_ADVENTURER 0

#include "axis.h"
#include "adventurer.h"
#include "archer.h"
#include "warrior.h"

void list_all_adventurers() {
	mvprintw(X + 0, Y, "[1] Warrior");
	mvprintw(X + 1, Y, "[2] Archer");
}

void choose_adventurer(Player** ptr) {
	int chosen_adventurer;
	Player* tmp_ptr;
	while (true) {
		clear();
		list_all_adventurers();
		mvprintw(XX + 0, Y, "Dear %s, which advernturer would you like to be?", (*ptr)->fetch_name());
		mvprintw(XX + 1, Y, "Your choice (-1 to leave): ");
		echo();
		scanw("%d", &chosen_adventurer);
		clear();

		switch(chosen_adventurer) {
			case -1:
				mvprintw(XX + 0, Y, "Oh, you are not ready to become a adventurer? Come back when you make up your mind.");
				mvprintw(XX + 1, Y, " => Press any key to continue...\n");
				scanw("\r");
				return;

			case 1:
				tmp_ptr = *ptr;
				*ptr = new Warrior((*ptr)->fetch_name());
				delete tmp_ptr;
				mvprintw(XX + 0, Y, "Dear %s, now you are a %s !!", (*ptr)->fetch_name(), "powerful warrior");
				mvprintw(XX + 1, Y, " => Press any key to leave...\n");
				scanw("\r");
				return;

			case 2:
				tmp_ptr = *ptr;
				*ptr = new Archer((*ptr)->fetch_name());
				delete tmp_ptr;
				mvprintw(XX + 0, Y, "Dear %s, now you are a %s !!", (*ptr)->fetch_name(), "execellent archer");
				mvprintw(XX + 1, Y, " => Press any key to leave...\n");
				scanw("\r");
				return;

			default:
				mvprintw(XX + 0, Y, "Sorry, %d is not a valid choice of adventurer", chosen_adventurer);
				mvprintw(XX + 1, Y, " => Press any key to continue...\n");
				scanw("\r");
				break;
		}
	}
}

void promote(Player** ptr) {
	int chosen_adventurer = 0;
	if (dynamic_cast<Adventurer*>(*ptr) != nullptr) { /* already an adventurer */
		mvprintw(XX + 5, Y, "Ummm, %s has alreadly been an Adventurer.", (*ptr)->fetch_name());	
		mvprintw(XX + 6, Y, " => Press Enter to leave...\n");
		scanw("\r");
	} else {	/* not an adventurer, still a player */
		if ((*ptr)->fetch_exp() < REQUIRED_EXP_FOR_ADVENTURER) {
			mvprintw(X + 5, Y, "Ummm, %s. Your EXP is only %d..... You are not qualified to be a Adventurer.", 
				(*ptr)->fetch_name(), (*ptr)->fetch_exp()
			);
			mvprintw(X + 6, Y, " => Press any key to leave...\n");
			scanw("\r");
		} 
		else {
			choose_adventurer(ptr);
		}
	}
}

#endif
 

