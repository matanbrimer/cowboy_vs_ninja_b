#ifndef TEAM_BASE_HPP
#define TEAM_BASE_HPP

#include <iostream>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "Ninja.hpp"
#include <vector>
#include"Point.hpp"
using namespace std;

namespace ariel{

class Team
{

protected:
    vector<Character*> team;
    Character* getCaptain()const;
    Character* captain;
    int count;
public:
    Team(Character* capt);
    virtual  ~Team();
    virtual void add(Character* );
    virtual void print();
    int getCount();
    void print2(vector<Character*> team2);
    virtual int stillAlive();
    virtual void attack(Team* foe);
    Character* getCloseCaptain(Character* captain,  vector<Character*> team2);
    vector<Character*> getTeam();
    void setCaptain(Character*);
    void attackT( Character* player, Team* foe );
};
}

#endif