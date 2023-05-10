#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <stdio.h>
#include <string>

using namespace std;



namespace ariel{
    class  Character{
        private:
            string _name;
            Point _location;
            int _health;
            int _id = 0;
            bool _inTeam = false;
        
        public:
            Character(const string& _name, const Point& _location, int _health);
            
            Character(const Character &other);

            Character(Character &&other) noexcept;

            Character &operator=(const Character &other);
            
            Character &operator=(Character &&other) noexcept;

            //virtual destructor
            virtual ~Character() {}
            
            virtual string print() const = 0;

             virtual void _attack(Character *enemy) = 0;

            bool isAlive() const;

            double distance(const Character* other) const;

            void hit(int hits);

            const string& getName() const;

            const Point& getLocation() const;

            int getHealth() const;

            bool GetInTeam() const;
            
            void SetInTeam(bool status);

            int GetId();
            
            void SetId(int status);

    };
};



#endif