#ifndef _LoX_CHARACTER
#define _LoX_CHARACTER

#include "common.hpp"
#include "creature.hpp"

enum Races {
    RACE_HUMAN,
    RACE_ELF,
    RACE_DWARF,
    RACE_HALFLING,
    RACE_GNOME,
    RACE_HALF_ORC,
    RACE_DROMITE,
    RACE_DUERGAR,
    RACE_ELAN,
    RACE_HALF_GIANT,
    RACE_MAENAD,
    RACE_XEPH
};

enum Classes {
    CLASS_BARBARIAN,
    CLASS_BARD,
    CLASS_CLERIC,
    CLASS_DRUID,
    CLASS_FIGHTER,
    CLASS_MONK,
    CLASS_PALADIN,
    CLASS_PSION,
    CLASS_PSYCHIC_WARRIOR,
    CLASS_RANGER,
    CLASS_ROGUE,
    CLASS_SORCEROR,
    CLASS_SOULKNIFE,
    CLASS_WILDER,
    CLASS_WIZARD
};

enum Alignments {
    LAWFUL_GOOD,
    LAWFUL_NEUTRAL,
    LAWFUL_EVIL,
    NEUTRAL_GOOD,
    TRUE_NEUTRAL,
    NEUTRAL_EVIL,
    CHAOTIC_GOOD,
    CHAOTIC_NEUTRAL,
    CHAOTIC_EVIL
};

class Character : public Creature {
    std::string _name;
    unsigned int _age;
    bool _sex;
    char _race;
    char __class;
    char _alignment;

public:
    Character(std::string name, unsigned int age = 30, bool sex = true,
            char race = RACE_HUMAN, char _class = CLASS_FIGHTER,
            char alignment = TRUE_NEUTRAL);

    std::string Name() const {return _name;};
    unsigned int Age() const {return _age;};
    bool Sex() const {return _sex;};
    char Race() const {return _race;};
    char Class() const {return __class;};
    char Alignment() const {return _alignment;};
};

#endif
