#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <stdio.h>
#include <string>

using namespace std;



namespace ariel{
    class  Character{
        protected:
            string _name;
            Point _location;
            int _health;
            int _id = 0;
            bool _inTeam = false;
        
        public:
            Character(const string& _name, const Point& _location, int _health);

            // ~Character() = default;

            bool isAlive() const;

            double distance(const Character* other) const;

            void hit(int hits);

            const string& getName() const;

            const Point& getLocation() const;

            virtual string print() = 0;

            bool GetInTeam();
            
            void SetInTeam(bool status);

            int GetId();
            
            void SetId(int status);

            virtual void _attack(Character *enemy) = 0;
            

    };
};



#endif