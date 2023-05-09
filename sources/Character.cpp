#include <stdio.h>
#include <iostream>
#include <ostream>

#include "Character.hpp"

using namespace std;

namespace ariel
{
    Character::Character(const string &_name, const Point &_location, int _health) : _name(_name), _location(_location), _health(_health){}

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

    bool Character::GetInTeam(){
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