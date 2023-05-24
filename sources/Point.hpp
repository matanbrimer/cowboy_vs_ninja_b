#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>

 using namespace std;

namespace ariel{

class Point{

private:
    double x;
    double y;

public:
    Point(double x=0, double y=0);
    Point(Point const &point);
    ~Point();
    double distance(Point);
    double getX()const; 
    double getY()const; 
    static Point moveTowards(Point,Point, double);
    void setX(double x);
    void setY(double y);
    string print();
    

};
}

#endif