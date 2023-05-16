#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Ninja.hpp"


const int YoungNinjaSpeed = 14;
const int YoungNinjaHealth = 100;

namespace ariel
{

    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const string &_name, const Point &_location) : Ninja(_name, _location, YoungNinjaHealth, YoungNinjaSpeed) {}
        // ~YoungNinja() = default;
    };
}

#endif