#ifndef MENU_H
#define MENU_H

#define MAX_N_PLAYERS 5

#include <iostream>
#include <string>
#include <fstream>
#include <curses.h>
#include "axis.h"
#include "player.h"
#include "monster.h"
#include "battlefield.h"
#include "promote.h"
using namespace std;

int n_players;
Player* player_ptrs[MAX_N_PLAYERS];

void list_all_players() {
	mvprintw(X, Y, "Existing players are: \n");
	for (int i = 0; i < Player::fetch_n_players(); ++i)
		mvprintw(X+1+i, Y, "  %d:   %s", i+1, player_ptrs[i]->fetch_name());
}

void show_options() {
	mvprintw(X+0, Y, "------ OPTIONS ------");
	mvprintw(X+1, Y, "[1] Create a new player");
	mvprintw(X+2, Y, "[2] List all players");
	mvprintw(X+3, Y, "[3] Battle with Monsters");
	mvprintw(X+4, Y, "[4] Promote to Adventurer");
	// mvprintw(X+5, Y, "[5] Show leaderboard");
	mvprintw(X+5, Y, "[5] Save");
	mvprintw(X+6, Y, "[6] Quit");
	mvprintw(X+7, Y, "---------------------");
	mvprintw(X+8, Y, "Your choice: ");
}

void show_menu() {
	int choice = 0;
	int chosen_player = 0;
	char player_name[20];
	Monster sneeky_rat("sneeky-rat", 10);
	while(true) {
		clear();
		show_options();
		echo();
		scanw("%d", &choice);
		switch(choice) {
			case 1: /* Create a new player */
				clear();
				n_players = Player::fetch_n_players();
				mvprintw(X + 2, Y, "The maximum number of players is %d", MAX_N_PLAYERS);
				mvprintw(X + 3, Y, "Currently, the number of players you've created is %d", n_players);
				if (n_players == MAX_N_PLAYERS) {
					mvprintw(XX + 5, Y, "Sorry, the maximum number of characters is reached.\n");
					mvprintw(XX + 6, Y, " => Press Enter to continue...\n");
				} else {
					if (n_players == 0) mvprintw(X, Y, "Welcome to \"Terminal-RPG\" !!\n");
					mvprintw(X + 5, Y, "Please give the name to the new player: ");
					echo();
					scanw("%s", player_name);
					player_ptrs[n_players] = new Player(player_name);
					mvprintw(XX + 0, Y, "The new character is created successfully !!\n");
					mvprintw(XX + 1, Y, " => Press any key to continue...\n");
				}
				scanw("\r");
				break;

			case 2: /* List all players */
				clear();
				list_all_players();
				mvprintw(XX + 0, Y, "Enter the index for details (or enter -1 to leave) :");
				mvprintw(XX + 1, Y, "Your choice: ");
				echo();
				scanw("%d", &chosen_player);

				while (chosen_player != -1) {
					list_all_players();
					if (chosen_player > 0 && chosen_player <= Player::fetch_n_players()) {
						player_ptrs[chosen_player-1]->curses_desc(X, YY);
					}
					else {
						mvprintw(XX + 5, Y,"[Warning] %d is an invalid choice !!", chosen_player);
					}

					mvprintw(XX + 0, Y, "Enter the index for details (or enter -1 to leave) :");
					mvprintw(XX + 1, Y, "Your choice: ");
					echo();
					scanw("%d", &chosen_player);
					clear();
				}
				break;

			case 3: /* Battle with monster*/
				clear();
				list_all_players();

				mvprintw(XX + 0, Y, "Choose a player to fight !\n");
				mvprintw(XX + 1, Y, "Your choice: ");

				echo();
				scanw("%d", &chosen_player);
				if (chosen_player >= 1 && chosen_player <= MAX_N_PLAYERS) {
					clear();
					sneeky_rat.set_hp(50);
					BattleField::battle(*player_ptrs[chosen_player - 1], sneeky_rat);
					// player_ptrs[chosen_player-1]->battle(Boss1);
				} else {
					mvprintw(XX + 4, Y, "[Warning] Invaild choice of character !!\n");
					mvprintw(XX + 5, Y, " => Press any key to continue...\n");
					scanw("\r");
				}
				break;

			case 4:
				clear();
				list_all_players();
				mvprintw(XX + 0, Y, "Choose the player that is going to be promoted to Adventurer: ");
				mvprintw(XX + 1, Y, "Your Choice (-1 to leave): ");
				echo();
				scanw("%d", &chosen_player);
				if (chosen_player == -1) {
					mvprintw(XX + 5, Y, "Oh, you are not ready to become a adventurer? Come back when you make up your mind.");
					mvprintw(XX + 6, Y, " => Press any key to continue...\n");
					scanw("\r");
					break;
				}
				else if (chosen_player >= 1 && chosen_player <= Player::fetch_n_players()) {
					// give the address of pointer. Directly change the value of the array.
					promote(&player_ptrs[chosen_player - 1]); 
				}
				else {
					mvprintw(XX + 5, Y, "Player %d does not exist....\n", chosen_player);
					mvprintw(XX + 6, Y, " => Press any key to continue...\n");
					scanw("\r");
				}
				break;
			
			case 5:
				clear();
				if (Player::fetch_n_players() > 0) {
					ofstream out_file("record.log");
					int subject;
					for (size_t i = 0; i < Player::fetch_n_players(); ++i) {
						subject = 0;
						if (dynamic_cast<Warrior*>(player_ptrs[i])) {
							subject = 1;
						}
						else if (dynamic_cast<Archer*>(player_ptrs[i])) {
							subject = 2;
						}
						out_file << player_ptrs[i]->fetch_name() << ' '
							<< player_ptrs[i]->fetch_damage() << ' '
							<< player_ptrs[i]->fetch_hp() << ' '
							<< player_ptrs[i]->fetch_exp() << ' '
							<< subject << endl;
					}
					out_file.close();
					mvprintw(XX + 5, Y, "The record of %d players are successfully saved !!",
						Player::fetch_n_players()
					);
					mvprintw(XX + 6, Y, " => Press any to continue...\n");
					scanw("\r");
				}
				break;

			case 6:	/* Quit the game */
				clear();
				mvprintw(XX + 0, Y, "See you!");
				mvprintw(XX + 1, Y, " => Press any key to quit the game...\n");
				scanw("\r");
				return;

			default: /* Invalid option */
				mvprintw(XX + 5, Y, "[Warning] \"%d\" is an invaild option !!\n\n", choice);
				mvprintw(XX + 6, Y, " => Press any key to continue...\n");
				scanw("\r");
				break;
		}
	
	}
}
 
 
#endif
