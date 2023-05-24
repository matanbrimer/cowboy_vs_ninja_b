#include <iostream>
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

using namespace std;
using namespace ariel;


Ninja::Ninja(int speed, string name, int hit_points, Point location) 
    : Character(hit_points, name, location,"N"), speed(speed) 
{
    
}



Ninja::~Ninja()
{
}


void Ninja:: move(Character* chr){
      int dist = speed;
        if(this->distance(chr)<speed)
            this->setLocation(Point(chr->getLocation().getX(), chr->getLocation().getY()));
        else
            this->setLocation(this->getLocation().moveTowards(this->getLocation(), chr->getLocation(), (double)speed));
}

void Ninja:: slash(Character* chara){
    if (chara == this) {
        throw std::runtime_error("You cannot shoot yourself");
    }

    if(this->get_hit_points() > 0 ){
        if(this->distance(chara) < 1)
            chara->hit(40);
    }else{
        throw std::runtime_error("A dead player cannot attack");
    }
}

int Ninja:: getSpeed(){
    return speed;
}