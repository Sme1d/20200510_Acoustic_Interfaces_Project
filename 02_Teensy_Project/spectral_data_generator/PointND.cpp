#include "PointND.h"
#include <cmath>
#include <iostream>

PointND::PointND(int n_dimensions){
  _n_dimensions = n_dimensions;
  _values = vector<float> (_n_dimensions);
  for (int d = 0; d < _n_dimensions; d++) {
    _values[d] = 0.0;
  }
}

PointND::PointND(int n_dimensions, float values){
  _n_dimensions = n_dimensions;
  _values = vector<float> (_n_dimensions, values);
}

PointND::PointND(vector<float>& valueVec){
  _n_dimensions = valueVec.size();
  _values = vector<float> (_n_dimensions);
  _values = valueVec;
}

float PointND:: getValue(int dimension){
  return _values[dimension];
}

int PointND:: getDimensions(){
  return _n_dimensions;
}

void PointND:: print(){
  cout << "(" << endl;

  for (int d = 0; d < _n_dimensions; d++) {
    cout << getValue(d) << ", ";
  }

  cout << ")" << endl;
}

float PointND::getDistance(PointND otherPoint){
    float dist = 0.0;
    if (otherPoint.getDimensions() == _n_dimensions) {
        float sum = 0.0;
        for (int d = 0; d < _n_dimensions; d++) {
            sum += pow(_values[d] - otherPoint.getValue(d),2);
        }
        dist = sqrt(sum);
    }
    return dist;
}

PointND PointND::operator+(PointND &p2){
    vector<float> values (_n_dimensions);

    for (int d = 0; d < _n_dimensions; d++) {
        float value = _values[d] + p2.getValue(d);
        values[d] = value;
    }

    PointND res = PointND(values);
    return res;
}

PointND PointND::operator/(float f){
    vector<float> values (_n_dimensions);
    for (int d = 0; d < _n_dimensions; d++) {
        float value = _values[d] / f;
        values[d] = value;
    }

    PointND res = PointND(values);
    return res;
}
