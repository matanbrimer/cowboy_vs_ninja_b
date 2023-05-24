#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Team.hpp"
#include <vector>

using namespace std;
namespace ariel{
    

class Team2: public Team
{
private:
    
   

public:
    Team2(Character*);
    ~Team2();
 
    void attack(Team*);    
    void print();

};





}

#endif