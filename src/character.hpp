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
    uint _age;
    bool _sex;
    uchar _race;
    uchar __class;
    uchar _alignment;

public:
    Character(std::string name, uint age = 30, bool sex = true,
            uchar race = RACE_HUMAN, uchar _class = CLASS_FIGHTER,
            uchar alignment = TRUE_NEUTRAL);

    std::string Name() const {return _name;};
    uint Age() const {return _age;};
    bool Sex() const {return _sex;};
    uchar Race() const {return _race;};
    uchar Class() const {return __class;};
    uchar Alignment() const {return _alignment;};
};

#endif
