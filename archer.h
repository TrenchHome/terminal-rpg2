#ifndef ARCHER_H
#define ARCHER_H
#include "adventurer.h"
#include "skill.h"

Skill healing_arrow(10, 20);

class Archer: public Adventurer {
public:
    Archer(const char*);
    Archer(const char*, const int&, const int&, const int&);
    virtual const char* fetch_skill_name();

protected:
    void reset_damage();     
    void reset_hp();    
    char* skill_name();
};

Archer::Archer(const char* name_) 
: Adventurer(name_, &healing_arrow) {
    reset_damage();
    reset_hp();
}        

Archer::Archer(const char* name_, const int& dmg_, const int& hp_, const int& exp_) 
: Adventurer(name_, dmg_, hp_, exp, &healing_arrow) {
    reset_damage();
    reset_hp();
}        

const char* Archer::fetch_skill_name() {
    return "healing_arrow";
}

void Archer::reset_damage() {
    damage = 10 + int(hp / 20) * 3;
}

void Archer::reset_hp() {
    hp = 120;
}

#endif

