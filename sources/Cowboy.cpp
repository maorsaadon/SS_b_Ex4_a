#include <iostream>
#include <string>
#include "Character.hpp"
#include "Cowboy.hpp"

using namespace std;

namespace ariel
{
    Cowboy::Cowboy(const string &_name, const Point &_location) : Character(_name, _location, 110), _bulletsAmount(6) {}

    void Cowboy::shoot(Character *enemy)
    {
        if (!isAlive())
        {
            cout << "This character is dead\n"
                 << endl;
            return;
        }
        else
        {
            enemy->hit(10);
            _bulletsAmount -= 1;
        }
    }

       bool Cowboy::hasboolets() const
    {
        return (_bulletsAmount > 0);
    }

    void Cowboy::reload()
    {
        if (_bulletsAmount > 0)
            throw invalid_argument("You have bullets\n");
        else
            _bulletsAmount = 6;
    }

    string Cowboy::print() const
    {
        string output = "\tC(" + getName() + ")\n\n";
        if (isAlive())
        {
            output += "\t\tHit points: " + to_string(getHit()) + " Points left: " + to_string(getHealth()) + "\n\n";
        }
        else
        {
            output += "\t\tHit points: " + to_string(getHit()) + " Points left: --\n\n";
        }

        cout << output; // Print to the console

        return output;
    }

    void Cowboy::_attack(Character *enemy)
    {
        if (!hasboolets())
            reload();
        else
            shoot(enemy);
    }

    int Cowboy::getBulletsAmount() const
    {
        return _bulletsAmount;
    }

} // namespace ariel
