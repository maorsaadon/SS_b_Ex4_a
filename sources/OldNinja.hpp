#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"

namespace ariel
{

    class OldNinja : public Ninja
    {
    public:
        OldNinja(const string &_name, const Point &_location);
        // ~OldNinja() = default;
    };
}

#endif