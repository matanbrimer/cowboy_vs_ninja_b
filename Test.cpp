#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Point.hpp"
#include "sources/smartTeam.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/Team.hpp"

using namespace ariel;

TEST_CASE("CharacterTest, DefaultConstructor") {
    Character c(100,"MATAN",Point(3.0,2.0),"C");

    CHECK_EQ(c.getName(), "MATAN");
    CHECK_EQ(c.isAlive(), true);
}

TEST_CASE("CharacterTest, HitMethod && isAlive") {
    Character c(5,"DANI",Point(3.0,2.0),"C");
    c.hit(6);
    CHECK_EQ(c.isAlive(), false);
}

TEST_CASE("CharacterTest, DistanceMethod") {
    Character c1(5,"DANI",Point(0.0,0.0),"C");
    Character c2(5,"DANI",Point(3.0,4.0),"C");

    CHECK_EQ(c1.distance(&c2), 5.0);
}

TEST_CASE("CowboyTest, DefaultConstructor && hasboolets") {
    Cowboy c("Nofar", Point(1,1));
    CHECK_EQ(c.getName(), "Nofar");

    CHECK_EQ(c.hasboolets(), true);
}



TEST_CASE("CowboyTest, ShootMethod") {
    Cowboy c1("Matan", Point(1,1));
    Character c2(2,"liran",Point(3.0,2.0),"N");
    c1.shoot(&c2);
    CHECK_EQ(c2.isAlive(), false);
}

TEST_CASE("OldNinjaTest, SlashMethod") {
    OldNinja n("Ninja", Point(2,2));
    Character c(2,"liran",Point(1.5,1.5),"N");

    n.slash(&c);
    CHECK_EQ(c.isAlive(), false);
}

TEST_CASE("SmartTeamTest, AddMethod") {
    Character c(100,"matan",Point(3.0,2.0),"C");
    Team team(&c);

    CHECK_EQ(team.stillAlive(), 1);
   
}

TEST_CASE("SmartTeamTest, AttackMethod") {
    
    Character c1(25,"dan",Point(1.0,1.0),"C");
    Character c2(20,"tom",Point(2.0,2.0),"N");
    smartTeam team1(&c1);
    smartTeam team2(&c2);
    Character c3(15,"yoni",Point(5.0,2.0),"C");
    Character c4(35,"ran",Point(4.0,1.0),"C");
    team1.add(&c3);
    team2.add(&c4);
    team1.attack(&team2);
    
    CHECK_EQ(team2.stillAlive(), 0);
    
}

TEST_CASE("PointTest, SettersAndGetters") {
    Point p(5.0,10.0);

   
    CHECK_EQ(p.getX(), 5.0);
    CHECK_EQ(p.getY(), 10.0);
   
}

TEST_CASE("PointTest, Distance") {
      
    Point p1(5.0, 10.0);
    Point p2(10.0, 10.0);
    CHECK_EQ(p1.distance(p2), 5.0);
    
}

  TEST_CASE("hit") 
    {
        
        Character test(100,"ron",Point(33.0,15.0),"N");;
        int damage = 85;
        test.hit(damage);
        CHECK(test.isAlive() == true);
    }

    TEST_CASE("shoot , hasboolets , reload")
    {
        
        Point point1(2, 8);
        Point point2(5, 8);
        Cowboy player1("dani",point1);
        Cowboy player2("avi",point2);
        CHECK(player1.hasboolets());
        while (player1.hasboolets())
        {
            player1.shoot(&player2);    
        }
        CHECK_FALSE(player1.hasboolets());
        player1.reload();
        CHECK(player1.hasboolets());
    }




    TEST_CASE("Test reload") {
        Point p1(0,0);
        Cowboy cowboy("fredi", p1);
        OldNinja ssusi("yaki",p1);
        CHECK(cowboy.hasboolets());
        for (size_t i = 0; i < 6; i++){
            cowboy.shoot(&ssusi);
        }
        CHECK_FALSE(cowboy.hasboolets());
        cowboy.reload();
        CHECK(cowboy.hasboolets());
        
    }
