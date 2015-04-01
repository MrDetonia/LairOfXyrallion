#include "character.hpp"

Character::Character(std::string name, unsigned int age, bool sex,
        char race, char _class, char alignment)
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
