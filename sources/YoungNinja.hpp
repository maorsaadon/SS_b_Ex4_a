#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Ninja.hpp"

namespace ariel
{

    class YoungNinja : public Ninja
    {

    public:
        YoungNinja(const string &name, const Point &location);
        // ~YoungNinja() = default;
    };
}

#endif