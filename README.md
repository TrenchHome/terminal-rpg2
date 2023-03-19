# Role-Play Game on Terminal

* This is a role-play game(RPG) that is executable on terminal or command line. 
* Namely, no graphical user interface(GUI) is applicable.

## Code Organization
TODO

## Class Diagram
```
classDiagram
    Role <|-- Monster
    Role <|-- Player
    Player <|-- Adventurer 
    Adventurer *-- Skill : has-a
    Adventurer <|-- Archer
    Adventurer <|-- Warrior
    BattleField <-- Player : friend
    BattleField <-- Adventurer : friend

    class Role {
        # char* name
        # int hp
        # int damage
        + static normal_attack(Role, Role)
        + virtual desc()
    }

    class Monster {
            # int reward_exp
            + virtual desc()
    }

    class Player {
        # int exp
        - static int n_players
        + static int fetch_n_players()
        + virtual desc()
    }

    class Adventurer {
    <<abstract>>
        + pure-virtual char* fetch_skill_name()
        + virtual desc()
        # pure-virtual reset_hp()
        # pure-virtual reset_damage()
        # Skill* skill
    }

    class Skill {
        - int skill_damage
        - int hp_change
        + void desc()
    }

    class Archer {
        + char* fetch_skill_name()
        # void reset_hp()
        # void reset_damage()
        # Skill* skill
    }

    class Warrior {
        + char* fetch_skill_name()
        # void reset_hp()
        # void reset_damage()
        # Skill* skill
    }

    class BattleField {
        +battle(Player, Monster)
    }
```
