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
        if(enemy == nullptr)
            throw invalid_argument("Nullptr\n");
        if (this == enemy)
            throw runtime_error("Cant kill himself\n");
        if (!isAlive())
            throw runtime_error("cant shoot\n");
        if (!enemy->isAlive())
            throw runtime_error("This enemy is allready dead\n");
        else if (_bulletsAmount <= 0)
        {
            cout << "Out of bullets\n"
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
        if (!isAlive())
            throw runtime_error("can't reload\n");
        _bulletsAmount = 6;
    }

    string Cowboy::print() const
    {
        string output = "\tC " + getName() ;
        if (isAlive())
            output += " " + to_string(getHealth()) + " " + getLocation().print() + "\n";
        else
            output += " -- " + getLocation().print() + "\n";

        cout << output;

        return output;
    }

    void Cowboy::attack(Character *enemy)
    {
        if (enemy == nullptr || !enemy->isAlive() || !isAlive())
            throw invalid_argument("attack failed");
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
