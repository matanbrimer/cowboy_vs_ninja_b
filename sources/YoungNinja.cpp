#include "YoungNinja.hpp"
#include <iostream>

using namespace std;
using namespace ariel;


YoungNinja::YoungNinja(string name, Point point):Ninja(14,name,100,point)
{
}
YoungNinja::YoungNinja(Character chara):Ninja(14,chara.getName(),100,chara.getLocation())
{

}
YoungNinja::~YoungNinja()
{
}
