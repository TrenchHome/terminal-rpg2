#ifndef SKILL_H
#define SKILL_H
// #define DEFAULT_SKILL_DAMAGE 5
#include "role.h"

class Skill {
public:
    Skill(int, int);                
    // Skill(const Skill&);                // copy constructor

    const int& fetch_skill_damage() const;
    const int& fetch_hp_change() const;
    void desc();

protected:
    int skill_damage;
    int hp_change;
};

Skill::Skill(int dmg, int hp_change_) : skill_damage(dmg), hp_change(hp_change_) {}

// Skill::Skill(const Skill& s) {
//     skill_damage = s.fetch_skill_damage();
// }

const int& Skill::fetch_skill_damage() const {return skill_damage;}
const int& Skill::fetch_hp_change() const {return hp_change;}

void Skill::desc() {
    log("");
    std::cout << std::setiosflags(std::ios::left);
    std::cout << std::setw(30) << "\t---------- Skill ----------\n";
    // cout << setw(15) << "\t> name" << setw(15) << name << '\n';
    std::cout << std::setw(15) << "\t> skill_dmg" << std::setw(15) << skill_damage << '\n';
    std::cout << std::setw(15) << "\t> hp_change" << std::setw(15) << hp_change << '\n';
}

// typedef enum class {
//     flame_geyser, 
//     freezing_arrow,
//     magic_missile,
// } Skill_name;


#endif