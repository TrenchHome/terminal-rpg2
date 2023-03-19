#ifndef ROLE_H
#define ROLE_H
#define DEFAULT_NAME "default"
#define DEFAULT_DAMAGE 5
#define DEFAULT_HP 100
#include <iostream>
#include <iomanip>
#include <cstring>
#include "logging.h"

class Role {
public:
    /* constructers */
    // Role();
    Role(const char*);
    Role(const char*, const int&, const int&);

    /* deconstructer */
    virtual ~Role();

    /* getter */
    const char* fetch_name() const;
    const int& fetch_hp() const;
    const int& fetch_damage() const;
    
    /* setter */
    void set_name(const char*);
    void set_hp(const int&);
    void set_damage(const int&);

    /* other public function */
    virtual void desc() const;
    virtual void curses_desc(int, int) const;
    static void normal_attack(Role&, Role&); 

protected:
    void delete_name();

    char* name = nullptr;                   // nickname
    int hp;                           // health points
    int damage;
};

/* constructers */
// Role::Role() : strength(10) {
//     name = new char[strlen(DEFAULT_NAME)+1];
//     strcpy(name, DEFAULT_NAME);
//     log("Constructor(default) is called");
// }

Role::Role(const char* name_) : damage(DEFAULT_DAMAGE), hp(DEFAULT_HP) {
    // log("Constructor {name = ", "");
    // std::cout << name_ << "} \n";
    set_name(name_);
}

Role::Role(const char* name_, const int& dmg_, const int& hp_) : damage(dmg_), hp(hp_) {
    set_name(name_);
} 

/* deconstructer */
Role::~Role() {
    // log("Deconstructor {name = ", "");
    // std::cout << name << "} \n";
    delete_name();
}

/* getter */
const char* Role::fetch_name()  const {return name;}
const int& Role::fetch_hp()     const {return hp;}
const int& Role::fetch_damage() const {return damage;}

/* setter */
void Role::set_name(const char* name_) {
    delete_name();
    name = new char[strlen(name_) + 1];
    strcpy(name, name_);
}
void Role::set_hp(const int& hp_) {hp = hp_;}
void Role::set_damage(const int& damage_) {damage = damage_;}

/* other public member function */
void Role::desc() const {
    log("");
    std::cout << std::setiosflags(std::ios::left);
    std::cout << std::setw(10) << "\t---------- " << std::setw(8) << typeid(*this).name() << " ----------\n";
    std::cout << std::setw(15) << "\t> Name" << std::setw(15) << name << '\n';
    std::cout << std::setw(15) << "\t> Damage" << std::setw(15) << damage << '\n';
    std::cout << std::setw(15) << "\t> HP" << std::setw(15) << hp << '\n';
    // std::cout << "\n";
    // std::cout << "\t-----------------\n";
}

void Role::curses_desc(int x, int y) const {
    mvprintw(x + 0, y, "---------- [%s] ----------", typeid(*this).name());
	mvprintw(x + 2, y, " Name:\t %s\n",      name);
	mvprintw(x + 3, y, " Damage:\t %d\n",    damage);
	mvprintw(x + 4, y, " HP:\t %d\n",        hp);
}

void Role::normal_attack(Role& attacker, Role& be_attacked) {
    // log("normal_attack {attacker = ", "");
    // std::cout << attacker.fetch_name() << ", ";
    // std::cout << " be_attacked = ";
    // std::cout << be_attacked.fetch_name() << "} \n";
    be_attacked.set_hp(
        be_attacked.fetch_hp() - attacker.fetch_damage()
    );
}

/* utility */
void Role::delete_name() {
    if (name != nullptr) {
        // log("--> name is not nullptr");
        delete [] name;
        name = nullptr;
    } 
    // else {
    //     // log("--> name is nullptr, no need to delete");
    // }
}

#endif