#include "character.hpp"

Character::Character(std::string name, uint age, bool sex,
        uchar race, uchar _class, uchar alignment)
    : Creature(CREATURE_CHARACTER)
{
    _name = name;
    _age = age;
    _sex = sex;
    _race = race;
    __class = _class;
    _alignment = alignment;

    // generate starting stats
}
