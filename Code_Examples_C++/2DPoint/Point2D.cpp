#include "Point2D.h"
#include <iostream>
#include <cmath>
using namespace std;


// Point constructor
Point2D::Point2D(){
    SetPoint(0.0, 0.0);
}

float Point2D:: getY(){
  return _y;
}

float Point2D:: getX(){
  return _x;
}

Point2D::Point2D(float x, float y){
    SetPoint(x, y);
}

// Point member function
void Point2D::SetPoint(float x, float y){
    _x = x;
    _y = y;
}

void Point2D::printPoint(){
  cout << "(" << _x << "/" << _y << ")" << endl;
}

Point2D Point2D::operator+(Point2D &p2){
  float newX = getX() + p2.getX();
  float newY = getY() + p2.getY();
  Point2D result = Point2D(newX,newY);

  return result;
}

Point2D Point2D::operator/(float f){
  float newX = getX() / f;
  float newY = getY() / f;
  Point2D result = Point2D(newX, newY);

  return result;
}

float Point2D::distanceToOtherPoint(Point2D otherPoint){
  float xDistance = abs(getX() - otherPoint.getX());
  float yDistance = abs(getY() - otherPoint.getY());
  float distance = sqrt(pow(xDistance,2)+pow(yDistance,2));
  return distance;
}
