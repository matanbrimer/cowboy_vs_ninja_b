#include "Team.hpp"
#include <iostream>
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"
using namespace std;
using namespace ariel;


Team::Team(Character* capt):captain(capt)
{   
    count = 0;
    if(captain->get_hit_points() > 0)
        add(captain);

}

Team::~Team(){
      for (auto it = team.begin(); it != team.end(); ++it) {
        if (*it != nullptr) {
            delete *it;
            *it = nullptr;
        }
    }
}

void Team::add(Character* chara){

    for (auto it = team.begin(); it != team.end(); ++it) {
        if (*it == chara) {
            throw std::runtime_error("Character is already in the team");
        }
    }
    if(team.size() < 10 && !chara->getPartOfTeam()){
        team.push_back(chara);
        chara->setPartOfTeam(true);
        count++;
    }
    else{
            
        throw runtime_error("A team can have at most 10 teammates");
    
    }

}

void Team::print2(vector<Character*> team2){
    int count =1;
    for (auto it = team2.begin(); it != team2.end(); ++it)
        {      
            cout<<"player "<< count<<"\n"<<(*it)->print()<<endl;
            
            count++;
        }   
}

void Team::print(){
    vector<Character*> teamNi;
    vector<Character*> teamCo;
    for (auto it = team.begin(); it != team.end(); ++it){
        
        if(typeid(*it) ==  typeid(Cowboy)){
            teamCo.emplace_back(*it);
        }else{
            teamNi.emplace_back(*it);
        }

    }
    print2(teamCo);
    print2(teamNi);
    
}

int Team::stillAlive() {
    int count = 0;
    for (auto it = team.begin(); it != team.end(); ++it) {
        if ((*it)->get_hit_points() > 0) {
            count++;
        }
    }
    return count;
}

vector<Character*> Team::getTeam(){
    return team;
}

Character* Team::getCloseCaptain(Character* captain, vector<Character*> team2){
    double dist = 9999999999999999.9;
    Character* player = nullptr;
    
    for (auto it = team2.begin(); it != team2.end(); ++it)
    {   
        if((*it) != nullptr){
            
            if(captain->distance(*it) <= dist && (*it)->isAlive() ){
                dist = captain->distance(*it);
                player = *it;
            }
        }
    }
    return player;

}

void Team::attackT(Character* player, Team* foe) {

    if (foe->stillAlive() > 0 ) {
        Character* victim = getCloseCaptain(captain,foe->getTeam());
        if(captain->get_hit_points() <= 0){
            setCaptain(getCloseCaptain(captain,getTeam()));
        }
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(player)) {
            if (cowboy->hasboolets()) {
                cowboy->shoot(victim);
            } else {
                cowboy->reload();
            }
        } else if (YoungNinja* youngNinja = dynamic_cast<YoungNinja*>(player)) {
            if (youngNinja->distance(victim) < 1) {
                youngNinja->slash(victim);
            } else {
                youngNinja->move(victim);
            }
        } else if (TrainedNinja* trainedNinja = dynamic_cast<TrainedNinja*>(player)) {
            if (trainedNinja->distance(victim) < 1) {
                trainedNinja->slash(victim);
            } else {
                trainedNinja->move(victim);
            }
        } else if (OldNinja* oldNinja = dynamic_cast<OldNinja*>(player)) {
            if (oldNinja->distance(victim) < 1) {
                oldNinja->slash(victim);
            } else {
                oldNinja->move(victim);
            }
        }
    }

}

void Team::attack(Team* foe){
    if (foe == nullptr) {
        throw std::invalid_argument("Invalid argument pointer");
       
    }
    if(foe->stillAlive() > 0)
    {
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
         
    }else{
        throw std::runtime_error("Dead team");
    }
    
}

void Team::setCaptain(Character* chara){
    if(chara->get_hit_points()>0 && chara != nullptr){
        captain = chara;
    }
}

Character* Team::getCaptain()const{
        return captain;
    }