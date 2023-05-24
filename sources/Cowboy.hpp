#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <iostream>
#include "Character.hpp"

namespace ariel {

class Cowboy : public Character {
private:
    int amount_of_balls;

public:
    Cowboy(std::string name, Point point);
    Cowboy(Character chara);
    virtual ~Cowboy();

    bool hasboolets();
    void reload();
    void shoot(Character* chara);
};

}

#endif
