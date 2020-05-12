#include <iostream>
#include "Point.h"
using namespace std;

int main() {
  Point point1(1,2);
  Point point2(5,5);
  Point point3(27,2);

  point1.printPoint();
  point2.printPoint();

  cout << point1.distanceToOtherPoint(point2) << endl;


  return 0;
}
