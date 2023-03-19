#ifndef WARRIOR_H
#define WARRIOR_H
#include "adventurer.h"
#include "skill.h"

Skill flame_geyser(30, -5);

class Warrior: public Adventurer {
public:
    Warrior(const char*);
    Warrior(const char*, const int&, const int&, const int&);
    virtual const char* fetch_skill_name(); 

protected:
    void reset_damage();    
    void reset_hp();    
};

Warrior::Warrior(const char* name_) : Adventurer(name_, &flame_geyser) {
    reset_damage();
    reset_hp();
}        

Warrior::Warrior(const char* name_, const int& dmg_, const int& hp_, const int& exp_) 
: Adventurer(name_, dmg_, hp_, exp, &flame_geyser) {
    reset_damage();
    reset_hp();
}        

const char* Warrior::fetch_skill_name() {
    return "flame_geyser";
}

void Warrior::reset_damage() {
    damage = 15 + int((250-hp) / 50) * 3;   // damage is based on hp
}

void Warrior::reset_hp() {
    hp = 250;
}

#endif

