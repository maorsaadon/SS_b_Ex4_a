#include "Ninja.hpp"

namespace ariel
{
    Ninja::Ninja(const string &_name, const Point &_location, int _health, int _speed) : Character(_name, _location, _health), _speed(_speed) {}

    void Ninja::move(Character *enemy)
    {
        if (!isAlive())
        {
            cout << "This character is dead\n"
                 << endl;
            return;
        }
        else
            getLocation().moveTowards(enemy->getLocation(), _speed);
    }

    void Ninja::slash(Character *enemy)
    {
        if (!isAlive())
        {
            cout << "This character is dead\n"
                 << endl;
            return;
        }
        else
        {
            if (getLocation().distance(enemy->getLocation()) > 100)
            {
                cout << "Too far to slash the enemy\n"
                     << endl;
                return;
            }
            else
                enemy->hit(40);
        }
    }

    string Ninja::print() const
    {
        cout << "N(" + getName() << ")\n"
             << endl;
        if (isAlive())
            cout << "Hit points: " << (110 - getHealth()) << " Points left: " << getHealth() << "\n"
                 << endl;
        else
            cout << "Hit points: " << 110 << " Points left: -- "
                 << "\n"
                 << endl;

        return " ";
    }

    void Ninja::_attack(Character *enemy)
    {
        if (getLocation().distance(enemy->getLocation()) > 100)
            move(enemy);
        else
            slash(enemy);
            
    }

}