#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"


const int OldNinjaSpeed = 8;
const int OldNinjHealth = 150;

namespace ariel
{

    class OldNinja : public Ninja
    {
    public:
        OldNinja(const string &_name, const Point &_location) : Ninja(_name, _location, OldNinjHealth, OldNinjaSpeed) {}
        // ~OldNinja() = default;
    };
}

#endif