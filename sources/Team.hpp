#ifndef TEAM_HPP
#define TEAM_HPP

#include <cmath>
#include <stdexcept>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include <sstream>
#include <memory>

#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

const int MaxSizeOfTeam = 10;

using namespace ariel;

namespace ariel
{

    class Team
    {

    private:
        vector<Character *> _team;

        Character *_teamLeader;

        void chooseNewLeader();

        Character *findClosestLivingMember(const vector<Character *> &characters, const Point &targetLocation);

    public:
        Team(Character *_teamleader);

        Team(Character *_teamLeader, const vector<Character*>& _team);
        
        // destructor
        virtual ~Team();

        Team(const Team &other);

        Team(Team &&other) noexcept;

        // Copy assignment operator
        Team &operator=(const Team &other);

        // Move assignment operator
        Team &operator=(Team &&other) noexcept;

        Character *getLeader() const;

        vector<Character*>& getTeam();

        virtual void add(Character *player);

        void attack(Team *other);

        int stillAlive() const;

        void print() const;
    };
}

#endif