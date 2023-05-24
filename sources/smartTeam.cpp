#include "smartTeam.hpp"
#include <iostream>

using namespace std;
using namespace ariel;


smartTeam::smartTeam(Character* player):Team(player)
{
}

smartTeam::~smartTeam()
{
}


void smartTeam::attack(Team* foe){
   
 if (foe == nullptr) {
        throw std::invalid_argument("Invalid argument pointer");
       
    }
    if(foe->stillAlive() > 0)
    {
        // Attack with Ninjas
        for (auto it = team.begin(); it != team.end(); ++it){
            if((*it)->get_hit_points() > 0){
                if(Ninja* ninja = dynamic_cast<Ninja*>(*it)){
                     
                    if(foe->stillAlive() > 0 ){
                        attackT(ninja, foe);
                    }
                    else{
                        return;
                    }
                    
                     
                }
            }
        }
        
        // Attack with Cowboys
        for (auto it = team.begin(); it != team.end(); ++it){         
            if((*it)->get_hit_points() > 0){
                if(Cowboy* cowboy = dynamic_cast<Cowboy*>(*it)){
                    if(foe->stillAlive() > 0 ){
                        attackT(cowboy, foe);
                    }else{
                        return;
                    }
                   
                }
            }
        }
             
        
         
    }else{
        throw std::runtime_error("Dead team");
    }
    
    
}


void smartTeam::print(){
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