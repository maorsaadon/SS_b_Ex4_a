#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Ninja.hpp"

namespace ariel
{

    class TrainedNinja : public Ninja
    {

    public:
        TrainedNinja(const string &name, const Point &location);
        // ~TrainedNinja() = default;
    };
}

#endif