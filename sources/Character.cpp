#include <iostream>
#include <string>
#include "Character.hpp"

using namespace std;

namespace ariel
{
    Character::Character(const string &_name, const Point &_location, int _health) : _name(_name), _location(_location), _health(_health), _inTeam(false), _hit(0){}

    Character::Character(const Character &other) : _name(other._name), _location(other._location), _health(other._health), _inTeam(other._inTeam), _hit(other._hit) {}

    Character::Character(Character &&other) noexcept : _name(other._name), _location(other._location), _health(other._health), _inTeam(other._inTeam), _hit(other._hit) {}

    Character &Character::operator=(const Character &other)
    {
        if (this == &other)
            return *this;

        _name = other._name;
        _location = other._location;
        _health = other._health;
        _inTeam = other._inTeam;
        _hit = other._hit;

        return *this;
    }

    Character &Character::operator=(Character &&other) noexcept
    {
        if (this == &other)
            return *this;

        _name = move(other._name);
        _location = move(other._location);
        _health = other._health;
        _inTeam = other._inTeam;
        _hit = other._hit;

        return *this;
    }

    bool Character::isAlive() const
    {
        return (_health > 0);
    }

    double Character::distance(const Character *other) const
    {
        if (other == nullptr)
            throw invalid_argument("Put character please!");
        else
            return _location.distance(other->_location);
    }

    void Character::hit(int hits)
    {
        if(hits < 0)
            throw invalid_argument("hits < 0");
        _health -= hits;
        _hit += hits;
    }

    const string &Character::getName() const
    {
        return _name;
    }

    const Point &Character::getLocation() const
    {
        return _location;
    }

    void Character::setLocation(const Point &location)
    {
        _location = location;
    }

    int Character::getHealth() const
    {
        return _health;
    }

    bool Character::getInTeam() const
    {
        return _inTeam;
    }

    void Character::setInTeam(bool status)
    {
        _inTeam = status;
    }

    int Character::getHit() const
    {
        return _hit;
    }
}
