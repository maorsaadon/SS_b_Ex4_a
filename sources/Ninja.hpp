#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel
{

    class Ninja : public Character
    {
    private:
        int _speed;
        bool _inTeam = false;

    public:
        Ninja(const string &_name, const Point &_location, int _health, int _speed);

        // virtual ~Ninja(){};

        void move(Character *enemy);

        void slash(Character *enemy);

        string print() const override;

        void attack(Character *enemy) override;

        int getSpeed() const;
    };

}

#endif