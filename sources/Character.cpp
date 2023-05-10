#include <stdio.h>
#include <iostream>
#include <ostream>

#include "Character.hpp"

using namespace std;

namespace ariel
{
    Character::Character(const string &_name, const Point &_location, int _health) : _name(_name), _location(_location), _health(_health){}

    Character::Character(const Character &other) :_name(other._name), _location(other._location), _health(other._health) {}

    Character::Character(Character &&other) noexcept : _name(other._name), _location(other._location), _health(other._health) {}

    Character &Character::operator=(const Character &other)
    {
        if (this == &other)
            return *this;

        this->_name = other._name;
        this->_location = other._location;
        this->_health = other._health;
        return *this;
    }

    Character &Character::operator=(Character &&other) noexcept
    {
        if (this == &other)
            return *this;

        this->_name = other._name;
        this->_location = other._location;
        this->_health = other._health;
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

    void Character::hit(int hits){
        _health -= hits;
    }

    const string& Character::getName() const{
        return _name;
    }

    const Point& Character::getLocation() const{
        return _location;
    }

    int Character::getHealth() const{
        return _health;
    }

    bool Character::GetInTeam() const{
        return _inTeam;
    }

    void Character::SetInTeam(bool status){
        _inTeam = status;
    }

    int Character::GetId(){
        return _id;
    }

    void Character::SetId(int id){
        _id = id;
    }


}