#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Ninja.hpp"

const int TrainedNinjaSpeed = 12;
const int TrainedNinjaHealth = 120;

namespace ariel
{

    class TrainedNinja : public Ninja
    {

    public:
        TrainedNinja(const string &_name, const Point &_location) : Ninja(_name, _location, TrainedNinjaHealth, TrainedNinjaSpeed){}
        // ~TrainedNinja() = default;
    };
}

#endif