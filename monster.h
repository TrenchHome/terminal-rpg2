#ifndef MONSTER_H
#define MONSTER_H
#include "role.h"

class Monster: public Role {
public:
    /* constructers */
    Monster(const char*, const int&);

    /* deconstructer */
    // ~Monster();

    /* getter */
    const int& fetch_reward_exp() const;

    /* setter */
    void set_reward_exp(const int&);
    virtual void desc() const override;

protected:
    friend class BattleField;
    
    int reward_exp;
};

/* constructers */
Monster::Monster(const char* name_, const int& reward_exp_) : reward_exp(reward_exp_), Role(name_) {}

/* deconstructer */
// Monster::~Monster() {}

/* getter */
const int& Monster::fetch_reward_exp() const {return reward_exp;}

/* setter */
void Monster::set_reward_exp(const int& reward_exp_) {reward_exp = reward_exp_;}

/* other public member function */
void Monster::desc() const {
    Role::desc();
    std::cout << std::setw(15) << "\t> reward_exp" << std::setw(15) << reward_exp << '\n';
}

#endif