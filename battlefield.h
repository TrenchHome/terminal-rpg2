#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H
#include "player.h"
#include "adventurer.h"
#include "archer.h"
#include "warrior.h"
#include "anime.h"
#include "axis.h"
#define GET_VAR_NAME(var) (#var)

class BattleField {
public:
    /* constructers */
    // BattleField();

    /* deconstructer */

    /* getter */
    
    /* setter */

    /* other public function */
    static void battle(Player&, Monster&);
	static void battle(Adventurer&, Monster&);
    // virtual void desc() const;

// protected:
//     Player p;
//     Monster m;
};

void BattleField::battle(Player& p, Monster& m) {
    int p_action = 0;
	Adventurer* ptr = dynamic_cast<Adventurer*>(&p);
    while (true) {
        mvprintw(XX + 0, Y, "Hi, %s. What's your action ? \n", p.fetch_name());
		mvprintw(XX + 1, Y, "[1] Escape ~~~\n");
		mvprintw(XX + 2, Y, "[2] Normal Attack!!\n");
		if (ptr != nullptr) { /* if p is an Adventurer */
			mvprintw(XX + 3, Y, "[3] Apply \"%s\" \n", ptr->fetch_skill_name());
		}
		mvprintw(XX + 5, Y, "Your choice: ");
        echo(); 

        /* player decide its action */
        scanw("%d", &p_action);
        switch(p_action) {
			case 1:
				mvprintw(XX + 5, Y, "Successfully escape ~~~");
				mvprintw(XX + 6, Y, "Press any key to leave...\n");
				scanw("\r");
				return;

			case 2:
				Role::normal_attack(p, m);
				mvprintw(X + 0, YYY, "You choose the Normal Attack!!"); 
				mvprintw(X + 1, YYY, "\"%s\" inflicts %d damage to \"%s\".",  
                    p.fetch_name(), p.fetch_damage(), m.fetch_name()
                );
				mvprintw(X + 3, YYY, " => The HP of \"%s\" is %d.", p.fetch_name() , p.fetch_hp() );
				mvprintw(X + 4, YYY, " => The HP of \"%s\" is changed from %d to %d.", 
					m.fetch_name() , m.fetch_hp()+p.fetch_damage(), m.fetch_hp()
				);
				break;

			case 3:
				if (ptr != nullptr) { /* if p is an Adventurer */
					clear();
					m.hp -= (ptr->skill)->fetch_skill_damage();
					mvprintw(X + 0, Y, "You apply \"%s\".", ptr->fetch_skill_name()); 
					/* apply skill damamge to monster */
					mvprintw(X + 1, YYY, "\"%s\" inflicts %d damage to \"%s\".",  
						ptr->fetch_name(), (ptr->skill)->fetch_skill_damage(), m.fetch_name()
					);
					/* apply skill hp_change to adventurer */
					mvprintw(X + 3, YYY, "\"%s\" retrieve %d HP",  
						ptr->fetch_name(), (ptr->skill)->fetch_hp_change()
					);
					mvprintw(X + 4, YYY, " => The HP of \"%s\" is changed from %d to %d.", 
						p.fetch_name(), p.fetch_hp()-(ptr->skill)->fetch_hp_change(), p.fetch_hp()
					);
					mvprintw(X + 5, YYY, " => The HP of \"%s\" is changed from %d to %d.", 
						m.fetch_name(), m.fetch_hp()+(ptr->skill)->fetch_skill_damage(), m.fetch_hp()
					);
					break;
				}

			default:
				mvprintw(XX + 5, Y, " [Warning] %d is an invalid choice.", p_action);
				mvprintw(XX + 6, Y, " => Press any key to continue...\n");
				scanw("\r");
				clear();
				continue;
		}

        /* check monster's hp */
		if (m.hp <= 0) {
			clear();
			win();
			mvprintw(XX + 5, Y, "Congratulation! Player \"%s\" wins the battle against \"%s\" !!", 
				p.fetch_name(), m.fetch_name()
			);
			mvprintw(XX + 6, Y, "The EXP of \"%s\" is increased from %d to %d !!", 
				p.fetch_name(), p.fetch_exp(), p.fetch_exp() + m.fetch_reward_exp()
			);
			p.exp += m.fetch_reward_exp();
			mvprintw(XX + 8, Y, " => Press any key to leave the battlefield...");
			scanw("\r");
			return;
		}

        /* monster use normal attack (as always) */
		Role::normal_attack(m, p);
		mvprintw(X + 12, YYY, "---------- \"%s\" ----------", m.name);
		mvprintw(X + 13, YYY, "\"%s\" chooses the normal attack !!", m.name);
		mvprintw(X + 14, YYY, "\"%s\" inflicts %d damage to \"%s\" !!", m.name, m.damage, p.name); 
		mvprintw(X + 16, YYY, " => The HP of \"%s\" is changed from %d to %d.", 
			p.fetch_name(), p.fetch_hp() + m.fetch_damage(), p.fetch_hp()
		);
		mvprintw(X + 17, YYY, " => The HP of \"%s\" is still %d.", 
			m.fetch_name(), m.fetch_hp()
		);
		refresh();

		/* check player's hp */
		if(p.hp <= 0) {
			clear();
			gameover();
			mvprintw(XX + 5, Y, "\"%s\" loses this battle against %s.", p.name, m.name);
			mvprintw(XX + 6, Y, " => Press any key to leave...\n");
			scanw("\r");
			p.hp = 100;
			return;
		}
    }
}

#endif