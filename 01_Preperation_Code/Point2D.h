#ifndef Point2D_H
#define Point2D_H

class Point2D {
    public:
        Point2D();

        Point2D(float, float);

        Point2D operator+(Point2D& p2);

        Point2D operator/(float f);

        float getX();
        float getY();

        void print();

        float getDistance(Point2D);

    private:
        float _x;
        float _y;
};
#endif
