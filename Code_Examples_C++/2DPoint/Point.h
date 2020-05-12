#ifndef POINT_H
#define POINT_H

class Point
{
private:
    float _x;
    float _y;

public:
    Point(float x, float y);

    void SetPoint(float x, float y);

    float getX(){ return _x;};
    float getY(){ return _y;};
    void printPoint();
    float distanceToOtherPoint(Point otherPoint);
};

#endif
