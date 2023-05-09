
#include <stdio.h>
#include <string>
#include "Cowboy.hpp"

using namespace std;

namespace ariel
{
    Cowboy::Cowboy(const string &_name, const Point &_location) : Character(_name, _location, 110), _bulletsAmount(6) {}

    void Cowboy::shoot(Character *enemy)
    {
        if (!isAlive()){
            cout << "This character is dead\n" << endl;
            return;
        }
        else
        {
            enemy->hit(10);
            _bulletsAmount -= 1;
        }
    }

    bool Cowboy::hasboolets() const{
        return (_bulletsAmount > 0);
    }

    void Cowboy::reload(){
        if(_bulletsAmount > 0)
            throw invalid_argument("You have bullets\n");
        else
            _bulletsAmount = 6;
    }

    string Cowboy::print(){
        cout << "C(" + _name << ")\n" << endl;
        if(isAlive())
            cout << "Hit points: "  << (110 - _health) << " Points left: " << _health << "\n" << endl;
        else
            cout << "Hit points: " << 110 << " Points left: -- " << "\n" << endl;

        return " ";
    }

    void Cowboy:: _attack(Character *enemy){
        if (!hasboolets())
            reload();
        else shoot(enemy);
    }


}