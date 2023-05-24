#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>
#include"Team.hpp"
using namespace std;
namespace ariel{
    

class smartTeam: public Team  //Cowboy,OldNinja,TrainedNinja,YoungNinja
{
private:
    vector<Character*> warriors;
    

public:
    smartTeam(Character*);
    ~smartTeam();
    void attack(Team*);
    void print();
};






}

#endif