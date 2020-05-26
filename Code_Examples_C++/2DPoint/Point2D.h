#ifndef POINT2D_H
#define POINT2D_H

class Point2D{
private:
    float _x;
    float _y;

public:
  Point2D();
  Point2D(float x, float y);

  void SetPoint(float x, float y);

  float getX();
  float getY();
  void printPoint();
  float distanceToOtherPoint(Point2D otherPoint);

  Point2D operator+(Point2D& p2);
  Point2D operator/(float f);
};

#endif
