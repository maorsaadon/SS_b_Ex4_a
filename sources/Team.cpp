#include "Team.hpp"

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

namespace ariel
{

    Team::Team(Character *_teamLeader) : _teamLeader(_teamLeader)
    {
        _teamLeader->SetId(_counter);
        _counter++;
        _team.push_back(_teamLeader);
    }

    void Team::add(Character *player)
    {
        if (!player->GetInTeam() || player->isAlive() || _counter < 11)
        {
            _team.push_back(player);
            player->SetInTeam(true);
            player->SetId(_counter);
            _counter++;
        }
        else
            throw invalid_argument("Can't add this player");
    }

    void Team::attack(Team *other)
    {
        // if (stillAlive() == 0 || other->stillAlive() == 0)
        //     throw invalid_argument("Game over");

        if (!_teamLeader->isAlive() && stillAlive() > 0)
        {
            Character *temp;
            for (uint i = 1; i < _team.size(); i++)
            {
                int temp_dist = numeric_limits<int>::max();
                if (_team.at(i)->isAlive())
                {
                    double dist = _teamLeader->distance(_team.at(i));
                    if (dist < temp_dist)
                    {
                        temp_dist = dist;
                        temp = _team.at(i);
                    }
                    else if (dist == temp_dist)
                        temp = _team.at(uint(_teamLeader->GetId() + 1));
                }
            }

            _teamLeader = temp;
        }
        else
        {
            Character *victim = other->_team.at(0);
            while (victim->isAlive() && stillAlive() > 0 && other->stillAlive() > 0)
            {

                Character *temp;
                for (uint i = 0; i < other->_team.size(); i++)
                {
                    int temp_dist = numeric_limits<int>::max();
                    double dist = _teamLeader->distance(other->_team.at(i));
                    if (dist < temp_dist)
                    {
                        temp_dist = dist;
                        victim = _team.at(i);
                    }
                    else if (dist == temp_dist)
                        victim = _team.at(uint(victim->GetId() + 1));
                }

                while (victim->isAlive())
                    for (uint i = 1; i < _team.size(); i++)
                        if (_team.at(i)->isAlive())
                            _team.at(i)->_attack(victim);
            }
        }

        if (stillAlive() == 0 || other->stillAlive() == 0)
            cout << "Game over" << endl;
    }

    int Team::stillAlive() const
    {
        int counter = 0;
        for (uint i = 1; i < _team.size(); i++)
            if (_team.at(i)->isAlive())
                counter++;

        return counter;
    }

    void Team::print() const
    {
        for (uint i = 1; i < _team.size(); i++)
            _team.at(i)->print();
    }

    // Team::~Team()
    // {
    //     _team.clear();
    // }

}
