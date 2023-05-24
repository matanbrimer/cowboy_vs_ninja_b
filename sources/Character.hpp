
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"

using namespace std;

namespace ariel{

class Character: public Point
{
private:
    
   
protected:
    Point location;
     int hit_points;
    string name;
    string type;
    bool part_of_team;
public:
    Character(int,string,Point,string);
    virtual ~Character();



    bool isAlive();//Returns true/false if the character is alive
    double distance(Character*);//Returns the distance between the characters
    void hit(int);//Subtracts the appropriate amount of hit points from the character
    string getName();//Returns the name of the character.
    Point getLocation();//Returns the position of the character
    void setName(string);
    string print();
    int get_hit_points();
    string getType();
    void setPartOfTeam(bool);
    bool getPartOfTeam();
   void setLocation(Point );

};

}


#endif