#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;


// Point constructor
Point::Point(float x, float y){
    SetPoint(x, y);
}

// Point member function
void Point::SetPoint(float x, float y){
    _x = x;
    _y = y;
}

void Point::printPoint(){
  cout << "(" << _x << "/" << _y << ")" << endl;
}

float Point::distanceToOtherPoint(Point otherPoint){
  float xDistance = abs(getX() - otherPoint.getX());
  float yDistance = abs(getY() - otherPoint.getY());
  float distance = sqrt(pow(xDistance,2)+pow(yDistance,2));
  return distance;
}
