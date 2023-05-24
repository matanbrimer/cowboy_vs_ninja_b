#include "Cowboy.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, Point point)
    : Character(110, name, point, "C"), amount_of_balls(6)
{
}

Cowboy::Cowboy(Character chara)
    : Character(110, chara.getName(), chara.getLocation(), "C"), amount_of_balls(6)
{
}

Cowboy::~Cowboy()
{
}

bool Cowboy::hasboolets()
{
    return amount_of_balls > 0;
}

void Cowboy::reload()
{
    if(!isAlive()){
        throw std::runtime_error("A dead Cowboy can't load a gun");
    }
       amount_of_balls = 6; 
    
    
}

void Cowboy::shoot(Character* chara)
{   
    if (chara == this) {
            throw std::runtime_error("You cannot shoot yourself");
        }

    if (get_hit_points() > 0 ) {
        if(amount_of_balls > 0){
            chara->hit(10);
            amount_of_balls--;
        }

    }
    else{
        throw std::runtime_error("You attacking a dead character");
    }
}
