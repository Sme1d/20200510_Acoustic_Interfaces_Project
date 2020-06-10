#include "Point2D.h"
#include <cmath>
#include <iostream>
using namespace std;

Point2D::Point2D(){
  _x = 0.0;
  _y = 0.0;
}

Point2D::Point2D(float newX, float newY){
  _x = newX;
  _y = newY;
}

float Point2D:: getY(){
  return _y;
}

float Point2D:: getX(){
  return _x;
}

void Point2D:: print(){
  cout << "(" << getX() << ", " << getY()<< ")" << endl;
}

float Point2D::getDistance(Point2D otherPoint){
  float distance = sqrt(pow((getY() - otherPoint.getY()),2)+pow((getX()- otherPoint.getX()),2));
  return distance;
}

Point2D Point2D::operator+(Point2D &p2){
    float y = _y + p2.getY();
    float x = _x + p2.getX();
    Point2D res = Point2D(x,y);
    return res;
}

Point2D Point2D::operator/(float f){
    float y = _y / f;
    float x = _x / f;
    Point2D res = Point2D(x,y);
    return res;
}
