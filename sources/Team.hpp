#ifndef TEAM_HPP
#define TEAM_HPP



#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

#include <vector>

using namespace ariel;


namespace ariel{

    class Team{

        private:

            vector<Character*> _team;

            Character* _teamLeader;

            int _counter = 0;

        public:

            Team(Character* leader);

            void add(Character* player);

            void attack(Team* other);

            int stillAlive() const;
            
            void print() const;

            // //destructor
            // ~Team();

            // Team(const Team& other) : _teamLeader(other._teamLeader){
            // // Copy the state of the `other` object
            // // to the new `Team` object
            // // ...
            // }

            // // Copy assignment operator
            // Team& operator=(const Team& other) {
            //     if (this != &other) {
            //         // Copy the state of the `other` object
            //         // to the current object
            //         // ...
            //     }
            //     return *this;
            // }

            // // Move constructor
            // Team(Team&& other) = default;

            // // Move assignment operator
            // Team& operator=(Team&& other) = default;
    };
}



#endif