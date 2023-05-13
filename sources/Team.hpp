#ifndef TEAM_HPP
#define TEAM_HPP

#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

#include <vector>

using namespace ariel;

namespace ariel
{

    class Team
    {

    private:
        vector<Character *> _team;

        Character *_teamLeader;

        int _counter = 0;

    public:
        Team(Character *leader);

        void add(Character *player);

        void attack(Team *other);

        int stillAlive() const;

        void print() const;

        // destructor
        ~Team();

        Team(const Team &other);

        Team(Team &&other) noexcept;

        // Copy assignment operator
        Team &operator=(const Team &other);

        // Move assignment operator
        Team &operator=(Team &&other) noexcept;

        Character *getLeader() const;

        vector<Character*> getTeam() const;
    };
}

#endif