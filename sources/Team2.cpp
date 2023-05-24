#include "Team2.hpp"
#include <iostream>

using namespace std;
using namespace ariel;


Team2::Team2(Character* player):Team(player)
{
}

Team2::~Team2()
{
    
}



void Team2::attack(Team* foe){
    if (foe == nullptr) {
        throw std::invalid_argument("Invalid argument pointer");
       
    }
    if(foe->stillAlive() > 0)
    {
        for (auto it = team.begin(); it != team.end(); ++it){         
            if((*it)->get_hit_points() > 0){
               
                     if(foe->stillAlive() > 0 ){
                         attackT(*it, foe);
                     }else{
                        return;
                     }
                   
            }
        }
    }         
    else{
        throw std::runtime_error("Dead team");
    }
    
}
 

void Team2::print(){
    Character* player;
    int count =1;
    vector<Character*> team_ =getTeam();
    for (auto it = team_.begin(); it != team_.end(); ++it)
        { 
            player = *it;
            cout<<"player "<< count<<"\n"<<player->print();
            count++;
        }
    
}



