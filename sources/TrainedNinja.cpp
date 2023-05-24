#include "TrainedNinja.hpp"
#include <iostream>

using namespace std;
using namespace ariel;


TrainedNinja::TrainedNinja(string name, Point point):Ninja(12,name,120,point)
{
}

TrainedNinja::TrainedNinja(Character chara):Ninja(12,chara.getName(),120,chara.getLocation())
{

}

TrainedNinja::~TrainedNinja()
{
}
