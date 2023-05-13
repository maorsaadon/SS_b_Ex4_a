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

    Team::Team(const Team &other) : _teamLeader(other._teamLeader), _team(other._team) {}

    Team::Team(Team &&other) noexcept : _teamLeader(other._teamLeader), _team(other._team) {}

    Team &Team::operator=(const Team &other)
    {
        if (this == &other)
            return *this;

        this->_teamLeader = other._teamLeader;
        this->_team = other._team;
        return *this;
    }

    Team &Team::operator=(Team &&other) noexcept
    {
        if (this == &other)
            return *this;

        this->_teamLeader = other._teamLeader;
        this->_team = other._team;
        return *this;
    }

    Team::~Team()
    {
        for (auto player : _team)
        {
            delete player;
        }
    }

    void Team::add(Character *player)
    {
        if (!player->getInTeam() || player->isAlive() || _counter < 11)
        {
            _team.push_back(player);
            player->setInTeam(true);
            player->SetId(_counter);
            _counter++;
        }
        else
            throw invalid_argument("Can't add this player");
    }

    void Team::attack(Team *enemyTeam)
    {
        if (!_teamLeader->isAlive())
        {
            Character *newLeader = nullptr;
            double minDistance = numeric_limits<double>::max();

            for (Character *member : _team)
            {
                if (member->isAlive())
                {
                    double distance = _teamLeader->getLocation().distance(member->getLocation());
                    if (distance < minDistance)
                    {
                        minDistance = distance;
                        newLeader = member;
                    }
                }
            }

            if (newLeader != nullptr)
            {
                _teamLeader = newLeader;
                cout << "New leader chosen: " << _teamLeader->getName() << endl;
            }
            else
            {
                cout << "No living character to become the new leader!" << endl;
                return;
            }
        }

        Character *victim = nullptr;
        double minDistance = numeric_limits<double>::max();

        for (Character *enemy : enemyTeam->getTeam())
        {
            if (enemy->isAlive())
            {
                double distance = _teamLeader->getLocation().distance(enemy->getLocation());
                if (distance < minDistance)
                {
                    minDistance = distance;
                    victim = enemy;
                }
            }
        }

        if (victim == nullptr)
        {
            cout << "No living enemy to attack!" << endl;
            return;
        }

        while (victim->isAlive() && stillAlive() > 0 && enemyTeam->stillAlive() > 0)
        {
            for (Character *member : _team)
            {
                if (member->isAlive())
                {
                    member->_attack(victim);
                }
            }
        }

        if (stillAlive() == 0 || enemyTeam->stillAlive() == 0)
        {
            cout << "Game over" << endl;
        }
    }

    int Team::stillAlive() const
    {
        int counter = 0;

        for (uint i = 0; i < _team.size(); i++)
            if (_team.at(i)->isAlive())
                counter++;

        return counter;
    }

    void Team::print() const
    {
        cout << "The member team : \n"
             << endl;
        for (uint i = 0; i < _team.size(); i++)
            _team.at(i)->print();
    }

    Character *Team::getLeader() const
    {
        return _teamLeader;
    }

    vector<Character *> Team::getTeam() const
    {
        return _team;
    }

}
