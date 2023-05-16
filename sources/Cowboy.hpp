#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

using namespace std;

namespace ariel
{

    class Cowboy : public Character
    {

    private:
        int _bulletsAmount;

    public:
        Cowboy(const string &_name, const Point &_location);

        void shoot(Character *enemy);

        bool hasboolets() const;

        void reload();

        string print() const override;

        void attack(Character *enemy) override;

        int getBulletsAmount() const;
    };
}

#endif