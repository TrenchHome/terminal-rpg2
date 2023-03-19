#ifndef PLAYER_H
#define PLAYER_H
#include "role.h"

class Player: public Role {
public:
    /* constructers */
    // Role();
    Player(const char*);
    Player(const char*, const int&, const int&, const int&);

    /* deconstructer */
    virtual ~Player();

    /* getter */
    const int& fetch_exp() const;
    static const int& fetch_n_players();
    
    /* setter */
    void set_exp(const int&);

    /* other public function */
    // friend operator <();
    virtual void desc() const;
    virtual void curses_desc(int, int) const;

protected:
    friend class BattleField;
    
    int exp;                            // experience points
    static int n_players;               // number of players
};

int Player::n_players = 0;

/* constructers */
Player::Player(const char* name_) 
: Role(name_), exp(0) {
    ++n_players;
}

Player::Player(const char* name_, const int& dmg_, const int& hp_, const int& exp_) 
: Role(name_, dmg_, hp_), exp(exp_) {
    ++n_players;
}

/* deconstructer */
Player::~Player() {
    --n_players;
}


/* getter */
const int& Player::fetch_exp() const {return exp;}
const int& Player::fetch_n_players() {return n_players;}

/* setter */
void Player::set_exp(const int& exp_) {exp = exp_;}

/* other public member function */
void Player::desc() const {
    Role::desc();
    std::cout << std::setw(15) << "\t> exp" << std::setw(15) << exp << '\n';
}

void Player::curses_desc(int x, int y) const {
    Role::curses_desc(x, y);
    mvprintw(x + 5, y, " EXP:\t %d\n",        exp);
}

#endif