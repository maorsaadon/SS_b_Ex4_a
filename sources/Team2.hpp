#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character *_teamLeader) : Team(_teamLeader){}
        void add(Character *player) override
        {

            if (player != nullptr && player->isAlive() && !player->getInTeam() && getTeam().size() < MaxSizeOfTeam)
            {
                getTeam().push_back(player) ;
                player->setInTeam(true);
            }
            else
            {
                throw runtime_error("Can't add this player");
            }
        }
       
    };
}


#endif