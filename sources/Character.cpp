#include "Character.hpp"
#include <iostream>

using namespace std;
using namespace ariel;



Character::Character(int hit_p, string name_, Point loca, string type_):
            hit_points(hit_p),name(name_),location(loca),type(type_)
{
    part_of_team = false;
}

Character::~Character()
{
    
}

void Character::setPartOfTeam(bool boole){
    part_of_team = boole;
}

bool Character::getPartOfTeam(){
    return part_of_team;
}
   
void Character::setLocation(Point newloc){
    location = Point(newloc.getX(), newloc.getY());
}

bool Character:: isAlive(){
    
    if(hit_points <= 0 )return false;
    return true;
}

double Character:: distance(Character* player){
    return location.distance(player->location);
}

void Character::hit(int hit) {
    if (hit < 0) {
        throw std::invalid_argument("A negative number of points cannot be deducted for a player");
    }
    if (hit_points > 0) {
        if (hit_points >= hit) {
            hit_points -= hit;
        } else {
            hit_points = 0;
        }
    } else {
        throw std::runtime_error("You are attacking a dead character");
    }
}


string Character:: getName(){
    return name;
}

Point Character:: getLocation(){
    return location;
}
 
void Character::setName(string newname){
    name = newname;
}

string Character:: print(){
    string print = " ";
    if(get_hit_points() > 0){
        print = "TYPE: " + getType() + 
                "\nNAME: " + getName() +
                "\nHP: " + to_string(get_hit_points()) + 
                "\nLOCATION: " + location.print();

    }else{
        print = "TYPE: " + getType() + 
                "\nNAME: "  +"(" + getName() + ")" +
                "\nLOCATION: " + location.print();
    }
    return print;
}

int Character:: get_hit_points(){
    return hit_points;
}

string Character:: getType(){
    return type;
}



