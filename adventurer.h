#ifndef ADVENTURER_H
#define ADVENTURER_H
#include "role.h"
#include "skill.h"

class Adventurer: public Player {
public:
    Adventurer(const char*, Skill*);
    Adventurer(const char*, const int&, const int&, const int&, Skill*);
    void desc() const override;
    virtual const char* fetch_skill_name() = 0;   // pure virtual
    // static void skill_attack(Adventurer&, Role&);


protected:
    friend class BattleField;
    virtual void reset_damage() = 0;        // pure virtual
    virtual void reset_hp() = 0;            // pure virtual
    
    Skill* skill;                           // skill
};

Adventurer::Adventurer(const char* name_, Skill* skill_) 
: Player(name_), skill(skill_) {}

Adventurer::Adventurer(const char* name_, const int& dmg_, const int& hp_, const int& exp_, Skill* skill_)
: Player(name_, dmg_, hp_, exp_), skill(skill_) {}

/* other public member function */
void Adventurer::desc() const {
    Role::desc();
    skill->desc();
}

// void Adventurer::skill_attack(Adventurer& attacker, Role& be_attacked) {
//     // log("normal_attack {attacker = ", "");
//     // std::cout << attacker.fetch_name() << ", ";
//     // std::cout << " be_attacked = ";
//     // std::cout << be_attacked.fetch_name() << "} \n";
//     be_attacked.set_hp(
//         be_attacked.fetch_hp() - (attacker.skill)->fetch_skill_damage()
//     );
//     attacker.set_hp(
//         attacker.fetch_hp() + (attacker.skill)->fetch_hp_change()
//     );
// }

#endif