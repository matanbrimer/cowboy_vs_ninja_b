#include "OldNinja.hpp"
#include <iostream>

using namespace std;
using namespace ariel;


OldNinja::OldNinja(string name, Point point):Ninja(8,name,150,point)
{
}

OldNinja::OldNinja(Character chara):Ninja(8,chara.getName(),150,chara.getLocation())
{

}

OldNinja::~OldNinja()
{
}

