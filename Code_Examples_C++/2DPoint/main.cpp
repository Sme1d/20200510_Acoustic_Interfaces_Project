#include <iostream>
#include <vector>
#include "Point2D.h"
using namespace std;

Point2D calculateCentroid(vector<Point2D> &pVec)
{
    Point2D centroid(0,0);

    for (size_t i = 0; i < pVec.size(); i++) {
      centroid = centroid + pVec[i];
    }

    centroid = centroid / pVec.size();
    return centroid;
}

int main() {
  Point2D p0(0,0);
  Point2D p1(0,1);
  Point2D p2(1,0);
  Point2D p3(1,5);

  vector<Point2D> pointVector = {p0, p1, p2, p3};
  Point2D centroid = calculateCentroid(pointVector);
  centroid.printPoint();

  return 0;
}
